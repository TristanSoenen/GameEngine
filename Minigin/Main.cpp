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
#include "MovementComponent.h"
#include "Controller.h"
#include "Command.h"

void load()
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto spacebackground1 = std::make_shared<dae::GameObject>();
	spacebackground1->SetTexture("Background.png");
	spacebackground1->SetPosition(50, 0);
	scene.Add(spacebackground1);

	auto go = std::make_shared<dae::GameObject>();
	/*go->SetTexture("background.tga");
	scene.Add(go);*/

	go = std::make_shared<dae::GameObject>();
	go->SetTexture("logo.tga");
	go->SetPosition(216, 180);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto to = std::make_shared<dae::TextObject>("Programming 4 Assignment", font);
	to->SetPosition(100, 20);
	scene.Add(to);

	go->AddComponent<dae::FPSComponent>();
	go->SetPosition(20, 20);
	scene.Add(go);

	auto starship = std::make_shared<dae::GameObject>();
	starship->SetTexture("starship.png");
	starship->SetPosition(200, 200);
	starship->AddComponent<dae::MovementComponent>();
	auto& input = dae::InputManager::GetInstance();
	input.CreateCommand(std::make_unique<dae::MoveUp>(starship.get()));
	input.CreateCommand(std::make_unique<dae::MoveDown>(starship.get()));
	input.CreateCommand(std::make_unique<dae::MoveRight>(starship.get()));
	input.CreateCommand(std::make_unique<dae::MoveLeft>(starship.get()));
	scene.Add(starship);

	auto Starship2 = std::make_shared<dae::GameObject>();
	Starship2->SetTexture("starship.png");
	Starship2->SetPosition(400, 200);
	Starship2->AddComponent<dae::MovementComponent>();
	input.AddController(std::make_unique<dae::Controller>());
	input.CreateCommandForController(std::make_unique<dae::MoveUp>(Starship2.get()), 0);
	input.CreateCommandForController(std::make_unique<dae::MoveDown>(Starship2.get()), 0);
	input.CreateCommandForController(std::make_unique<dae::MoveRight>(Starship2.get()), 0);
	input.CreateCommandForController(std::make_unique<dae::MoveLeft>(Starship2.get()), 0);
	scene.Add(Starship2);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}