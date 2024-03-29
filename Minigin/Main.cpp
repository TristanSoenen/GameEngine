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
#include "LivesUIComponent.h"
#include "Controller.h"
#include "Command.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto spacebackground1 = std::make_shared<dae::GameObject>();
	spacebackground1->AddComponent<dae::RenderComponent>();
	spacebackground1->SetTexture("Background.png");
	spacebackground1->SetPosition(50, 0);
	scene.Add(spacebackground1);

	auto go = std::make_shared<dae::GameObject>();
	/*go->SetTexture("background.tga");
	scene.Add(go);*/

	go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::RenderComponent>();
	go->SetTexture("logo.tga");
	go->SetPosition(216, 180);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	to->SetPosition(100, 20);
	scene.Add(to);

	//go->AddComponent<dae::FPSComponent>();
	//go->SetPosition(20, 20);
	scene.Add(go);

	auto observerScoreStarship = std::make_shared<dae::GameObject>();
	auto observerLivesStarship = std::make_shared<dae::GameObject>();// ui
	//observerLivesStarship->AddComponent<dae::LivesUIComponent>();

	auto observerScoreStarship2 = std::make_shared<dae::GameObject>();
	auto observerLivesStarship2 = std::make_shared<dae::GameObject>();
	scene.Add(observerScoreStarship);
	scene.Add(observerLivesStarship);
	scene.Add(observerScoreStarship2);
	scene.Add(observerScoreStarship2);

	auto starship = std::make_shared<dae::GameObject>();
	starship->AddComponent<dae::RenderComponent>();
	starship->SetTexture("starship.png");
	starship->SetPosition(200, 200);
	auto& input = dae::InputManager::GetInstance();
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ 0.0f, -1.0f, 0.0f }, 50.0f), SDL_SCANCODE_W);
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ 0.0f, 1.0f, 0.0f }, 50.0f), SDL_SCANCODE_S);
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 50.0f), SDL_SCANCODE_D);
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 50.0f), SDL_SCANCODE_A);
	//starship->AddObserver(observerScoreStarship);
	//starship->AddObserver(observerLivesStarship);
	scene.Add(starship);

	auto Starship2 = std::make_shared<dae::GameObject>();
	Starship2->AddComponent<dae::RenderComponent>();
	Starship2->SetTexture("starship.png");
	Starship2->SetPosition(400, 200);
	input.AddController(std::make_unique<dae::Controller>());
	input.CreateCommandForController(std::make_unique<dae::MoveCommand>(Starship2.get(), glm::vec3{ 0.0f, 1.0f, 0.0f }, 100.0f), 0, 2);		//down
	input.CreateCommandForController(std::make_unique<dae::MoveCommand>(Starship2.get(), glm::vec3{ 0.0f, -1.0f, 0.0f }, 100.0f), 0, 1);	//up 
	input.CreateCommandForController(std::make_unique<dae::MoveCommand>(Starship2.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 100.0f), 0, 8);		//right
	input.CreateCommandForController(std::make_unique<dae::MoveCommand>(Starship2.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 100.0f), 0, 4);	//left
	//Starship2->AddObserver(observerScoreStarship2);
	//Starship2->AddObserver(observerLivesStarship2);
	scene.Add(Starship2);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}