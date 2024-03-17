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
#include "TextObject.h"
#include "Scene.h"
#include "Component.h"
#include "FPSComponent.h"
#include "RotationComponent.h"
#include "MovementComponent.h"

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
	scene.Add(starship);

	auto starship2 = std::make_shared<dae::GameObject>();
	starship2->SetTexture("starship.png");
	starship2->SetPosition(400, 200);
	starship2->AddComponent<dae::MovementComponent>();
	scene.Add(starship2);

	
	//auto parent = std::make_shared<dae::GameObject>();
	//parent->SetTexture("logo.tga");
	//parent->AddComponent<dae::RotationComponent>();
	//scene.Add(parent);

	//auto child = std::make_shared<dae::GameObject>();
	//child->SetTexture("logo.tga");
	//child->SetParent(parent, false);
	//scene.Add(parent);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}