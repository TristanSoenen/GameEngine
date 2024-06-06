#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "Minigin.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "InputManager.h"
#include "Scene.h"
#include "Component.h"
#include "RotationComponent.h"
#include "RenderComponent.h"
#include "TextComponent.h"
#include "BossGalaga.h"
#include "Butterfly.h"
#include "Bee.h"
#include "GalagaPlayer.h"
#include "BackGround.h"
#include "Controller.h"
#include "Command.h"
#include "GameCommands.h"
#include "ServiceLocator.h"
#include "Sound_System.h"
#include "SDL_Sound_System.h"
#include "Logging_Sound_System.h"
#include "Structs.h"
#include "ScoreComponent.h"
#include "LivesComponent.h"
#include "GameComponent.h"

#include <fstream>
#include "sstream"
#include "iostream"



void ReadPositions(std::vector<glm::vec2>& positions, std::string filename)
{
	//most of it is from chat gpt with some changesd
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Error: Could not open the file!" << std::endl;
	}

	std::string line;
	while (std::getline(file, line)) {
		// Remove possible whitespace at the beginning and end of the line
		line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](unsigned char ch) {
			return !std::isspace(ch);
			}));
		line.erase(std::find_if(line.rbegin(), line.rend(), [](unsigned char ch) {
			return !std::isspace(ch);
			}).base(), line.end());

		// Skip empty lines
		if (line.empty()) {
			continue;
		}

		std::stringstream ss(line);
		float x, y;
		if (ss >> x >> y) {
			positions.push_back(glm::vec2(x, y));
		}
	}
}


std::unique_ptr<Sound_System> ServiceLocator::_ss_instance{ std::make_unique<Null_Sound_System>() };

void load()
{
#if _DEBUG
	ServiceLocator::register_Sound_System(std::make_unique<Logging_Sound_System>(std::make_unique<SDL_Sound_System>()));
#else

	ServiceLocator::register_Sound_System(std::make_unique<SDL_Sound_System>());
#endif

	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");
	auto background0 = std::make_shared<dae::GameObject>();
	background0->SetPosition(0, 0);
	background0->AddComponent(std::make_shared<dae::BackGround>(background0.get(), 100.0f));
	scene.Add(background0);

	auto background1 = std::make_shared<dae::GameObject>();
	background1->SetPosition(0, -480);
	background1->AddComponent(std::make_shared<dae::BackGround>(background1.get(), 100.0f));
	scene.Add(background1);

	auto player = std::make_shared<dae::GameObject>();
	player->AddComponent(std::make_shared<dae::GalagaPlayer>(player.get()));
	player->SetPosition(200, 400);
	auto& input = dae::InputManager::GetInstance();
	input.AddController(std::make_unique<dae::Controller>());
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(player.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 100.0f), SDL_SCANCODE_D, false);
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(player.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 100.0f), SDL_SCANCODE_A, false);
	input.CreateCommandForController(std::make_unique<dae::MoveCommand>(player.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 100.0f), 0, dae::DPAD_LEFT, false);
	input.CreateCommandForController(std::make_unique<dae::MoveCommand>(player.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 100.0f), 0, dae::DPAD_RIGHT, false);
	input.CreateCommandForController(std::make_unique<dae::FireCommand>(player.get()), 0, dae::GAMEPAD_A, true);
	input.CreateCommandKeyBoard(std::make_unique<dae::KillCommand>(player.get()), SDL_SCANCODE_K, true);
	input.CreateCommandKeyBoard(std::make_unique<dae::FireCommand>(player.get()), SDL_SCANCODE_F, true);
	auto ss = ServiceLocator::get_Sound_System();
	ss->LoadSound("../Data/PlayerShoot.wav");
	scene.Add(player);

	auto Bee = std::make_shared<dae::GameObject>();
	Bee->AddComponent(std::make_shared<dae::Bee>(Bee.get()));
	Bee->SetPosition(0, 377);
	scene.Add(Bee);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto score = std::make_shared<dae::GameObject>();
	score->AddComponent(std::make_shared<dae::ScoreComponent>(score.get(), font));
	score->SetPosition(400, 50);
	auto scoreComp = score->GetComponent<dae::ScoreComponent>();
	scene.Add(score);

	auto galagaPlayerComp = player->GetComponent<dae::GalagaPlayer>();
	auto lives = std::make_shared<dae::GameObject>();
	lives->AddComponent(std::make_shared<dae::LivesComponent>(lives.get(), galagaPlayerComp->GetLives(), font));
	auto livesComp = lives->GetComponent<dae::LivesComponent>();
	lives->SetPosition(400, 350);
	galagaPlayerComp->AddObserverToPlayer(livesComp->GetObserver());
	scene.Add(lives);

	auto game = std::make_shared<dae::GameObject>();
	game->AddComponent(std::make_shared<dae::GameComponent>(game.get()));
	scene.Add(game);

	//adding enemies to the game with filepositions
	std::vector<glm::vec2> positions;
	ReadPositions(positions, "../Data/Formation1Bees.txt");
	for(int i = 0; i < int(positions.size()); i++)
	{
		auto bee = std::make_shared<dae::GameObject>();
		bee->AddComponent(std::make_shared<dae::Bee>(bee.get()));
		auto beeComp2 = bee->GetComponent<dae::Bee>();
		beeComp2->AddObserverToBee(scoreComp->GetObserver());
		bee->SetPosition(positions[i].x, positions[i].y);
		scene.Add(bee);
	}
	positions.clear();
	ReadPositions(positions, "../Data/Formation1Butterflies.txt");
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto btfly = std::make_shared<dae::GameObject>();
		btfly->AddComponent(std::make_shared<dae::Butterfly>(btfly.get()));
		auto btlfyComp = btfly->GetComponent<dae::Butterfly>();
		btlfyComp->AddObserverToButterfly(scoreComp->GetObserver());
		btfly->SetPosition(positions[i].x, positions[i].y);
		scene.Add(btfly);
	}
	positions.clear();
	ReadPositions(positions, "../Data/Formation1Boss.txt");
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto bs = std::make_shared<dae::GameObject>();
		bs->AddComponent(std::make_shared<dae::BossGalaga>(bs.get()));
		auto bsComp = bs->GetComponent<dae::BossGalaga>();
		bsComp->AddObserverToBoss(scoreComp->GetObserver());
		bs->SetPosition(positions[i].x, positions[i].y);
		scene.Add(bs);
	}

}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}

