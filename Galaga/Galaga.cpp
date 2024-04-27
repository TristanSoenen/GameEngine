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
#include "TextObject.h"
#include "Scene.h"
#include "Component.h"
#include "FPSComponent.h"
#include "RotationComponent.h"
#include "RenderComponent.h"
#include "TextComponent.h"
#include "LivesUIComponent.h"
#include "HealthComponent.h"
#include "Controller.h"
#include "Command.h"
#include "ServiceLocator.h"
#include "Sound_System.h"
#include "SDL_Sound_System.h"

std::unique_ptr<Sound_System> ServiceLocator::_ss_instance{ std::make_unique<Null_Sound_System>() };

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	ServiceLocator::register_Sound_System(std::make_unique<SDL_Sound_System>());

	/*auto spacebackground1 = std::make_shared<dae::GameObject>();
	spacebackground1->AddComponent<dae::RenderComponent>();
	spacebackground1->SetTexture("Background.png");
	spacebackground1->SetPosition(50, 0);
	scene.Add(spacebackground1);*/

	//auto go = std::make_shared<dae::GameObject>();
	//go->SetTexture("background.tga");
	//scene.Add(go);

	//go = std::make_shared<dae::GameObject>();
	//go->AddComponent<dae::RenderComponent>();
	//go->SetTexture("logo.tga");
	//go->SetPosition(216, 180);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	//auto to = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	//to->SetPosition(100, 20);
	//scene.Add(to);

	auto programming4Text = std::make_shared<dae::GameObject>();
	programming4Text->AddComponent(std::make_shared<dae::TextComponent>(programming4Text.get(), "Programming 4 Assigment", font));
	programming4Text->SetPosition(100, 20);
	scene.Add(programming4Text);

	auto font2 = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	auto info1 = std::make_shared<dae::TextObject>("use the dpad to move and press X to kill and A to get points", font2);
	info1->SetPosition(5, 100);
	scene.Add(info1);

	auto info2 = std::make_shared<dae::TextObject>("use WASD to move and press Q to kill and E to get Points", font2);
	info2->SetPosition(5, 120);
	scene.Add(info2);

	auto fpsObj = std::make_shared<dae::GameObject>();

	//fpsObj->AddComponent<dae::FPSComponent>();
	fpsObj->AddComponent(std::make_shared<dae::FPSComponent>(fpsObj.get(), 1));
	fpsObj->SetPosition(20, 20);
	scene.Add(fpsObj);
	//scene.Add(go);

	//auto observerScoreStarship = std::make_shared<dae::GameObject>();

	//auto observerLivesStarship = std::make_shared<dae::GameObject>();  // ui
	//observerLivesStarship->AddComponent<dae::LivesUIComponent>();
	//observerLivesStarship->SetPosition(5, 140);
	//scene.Add(observerLivesStarship);

	//auto observerScoreStarship2 = std::make_shared<dae::GameObject>();
	//auto observerLivesStarship2 = std::make_shared<dae::GameObject>();
	//scene.Add(observerScoreStarship);
	//scene.Add(observerLivesStarship);
	//scene.Add(observerScoreStarship2);
	//scene.Add(observerScoreStarship2);

	auto starship = std::make_shared<dae::GameObject>();
	starship->AddComponent(std::make_shared<dae::RenderComponent>(starship.get()));
	starship->SetTexture("starship.png");
	starship->SetPosition(200, 200);
	auto& input = dae::InputManager::GetInstance();
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ 0.0f, -1.0f, 0.0f }, 50.0f), SDL_SCANCODE_W);
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ 0.0f, 1.0f, 0.0f }, 50.0f), SDL_SCANCODE_S);
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 50.0f), SDL_SCANCODE_D);
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 50.0f), SDL_SCANCODE_A);
	//starship->AddComponent<dae::HealthComponent>();
	//auto healthComp = starship->GetComponent<dae::HealthComponent>();
	//healthComp->AddObserver();
	//starship->AddObserver(observerScoreStarship);
	//starship->AddObserver(observerLivesStarship);
	scene.Add(starship);



	//auto Starship2 = std::make_shared<dae::GameObject>();
	//Starship2->AddComponent<dae::RenderComponent>();
	//Starship2->AddComponent<dae::HealthComponent>();
	//Starship2->SetTexture("starship.png");
	//Starship2->SetPosition(400, 200);
	//input.AddController(std::make_unique<dae::Controller>());
	//input.CreateCommandForController(std::make_unique<dae::MoveCommand>(Starship2.get(), glm::vec3{ 0.0f, 1.0f, 0.0f }, 100.0f), 0, 2);		//down
	//input.CreateCommandForController(std::make_unique<dae::MoveCommand>(Starship2.get(), glm::vec3{ 0.0f, -1.0f, 0.0f }, 100.0f), 0, 1);	//up 
	//input.CreateCommandForController(std::make_unique<dae::MoveCommand>(Starship2.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 100.0f), 0, 8);		//right
	//input.CreateCommandForController(std::make_unique<dae::MoveCommand>(Starship2.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 100.0f), 0, 4);	//left
	//input.CreateCommandForController(std::make_unique<dae::KillCommand>(Starship2.get()), 0, 16384);
	//input.CreateCommandForController(std::make_unique<dae::IncreaseScoreCommand>(Starship2.get()), 0, 4096);// X

	//
	////Starship2->AddObserver(observerScoreStarship2);
	////Starship2->AddObserver(observerLivesStarship2);
	//scene.Add(Starship2);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}