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

	auto starship = std::make_shared<dae::GameObject>();
	starship->AddComponent(std::make_shared<dae::GalagaPlayer>(starship.get()));
	starship->SetPosition(200, 400);
	auto& input = dae::InputManager::GetInstance();
	input.AddController(std::make_unique<dae::Controller>());
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 100.0f), SDL_SCANCODE_D, false);
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 100.0f), SDL_SCANCODE_A, false);
	input.CreateCommandForController(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 100.0f), 0, dae::DPAD_LEFT, false);
	input.CreateCommandForController(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 100.0f), 0, dae::DPAD_RIGHT, false);
	input.CreateCommandForController(std::make_unique<dae::FireCommand>(starship.get()), 0, dae::GAMEPAD_A, true);
	input.CreateCommandKeyBoard(std::make_unique<dae::KillCommand>(starship.get()), SDL_SCANCODE_K, true);
	input.CreateCommandKeyBoard(std::make_unique<dae::FireCommand>(starship.get()), SDL_SCANCODE_F, true);
	auto ss = ServiceLocator::get_Sound_System();
	ss->LoadSound("../Data/PlayerShoot.wav");
	scene.Add(starship);

	auto Boss = std::make_shared<dae::GameObject>();
	Boss->SetPosition(200, 200);
	Boss->AddComponent(std::make_shared<dae::BossGalaga>(Boss.get()));
	scene.Add(Boss);

	auto Bee = std::make_shared<dae::GameObject>();
	Bee->AddComponent(std::make_shared<dae::Bee>(Bee.get()));
	Bee->SetPosition(0, 377);
	scene.Add(Bee);

	auto Bee2 = std::make_shared<dae::GameObject>();
	Bee2->AddComponent(std::make_shared<dae::Bee>(Bee2.get()));
	Bee2->SetPosition(100, 300);
	scene.Add(Bee2);

	auto butterfly = std::make_shared<dae::GameObject>();
	butterfly->AddComponent(std::make_shared<dae::Butterfly>(butterfly.get()));
	butterfly->SetPosition(300, 300);
	scene.Add(butterfly);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto score = std::make_shared<dae::GameObject>();
	score->AddComponent(std::make_shared<dae::ScoreComponent>(score.get(), font));
	score->SetPosition(450, 50);
	auto scoreComp = score->GetComponent<dae::ScoreComponent>();
	auto bossGalageComp = Boss->GetComponent<dae::BossGalaga>();
	bossGalageComp->AddObserverToBoss(scoreComp->GetObserver());
	scene.Add(score);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}