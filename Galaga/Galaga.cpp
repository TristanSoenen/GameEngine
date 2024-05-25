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
#include "BossGalaga.h"
#include "Butterfly.h"
#include "Bee.h"
#include "GalagaPlayer.h"
#include "BackGround.h"
#include "Collision.h"
#include "Controller.h"
#include "Command.h"
#include "GameCommands.h"
#include "ServiceLocator.h"
#include "Sound_System.h"
#include "SDL_Sound_System.h"
#include "Logging_Sound_System.h"

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

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);

	auto programming4Text = std::make_shared<dae::GameObject>();
	programming4Text->AddComponent(std::make_shared<dae::TextComponent>(programming4Text.get(), "Programming 4 Assigment", font));
	programming4Text->SetPosition(100, 20);
	scene.Add(programming4Text);

	auto font2 = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 20);
	auto info1 = std::make_shared<dae::TextObject>("Press F for sound", font2);
	info1->SetPosition(5, 100);
	scene.Add(info1);

	auto info2 = std::make_shared<dae::TextObject>("use A and D to move", font2);
	info2->SetPosition(5, 120);
	scene.Add(info2);

	auto info3 = std::make_shared<dae::TextObject>("use W forHitState and S for explode State", font2);
	info3->SetPosition(5, 80);
	scene.Add(info3);

	//auto fpsObj = std::make_shared<dae::GameObject>();

	//fpsObj->AddComponent(std::make_shared<dae::FPSComponent>(fpsObj.get(), 1));
	//fpsObj->SetPosition(20, 20);
	//scene.Add(fpsObj);

	//auto livesHud = std::make_shared<dae::GameObject>();
	//livesHud->AddComponent(std::make_shared<dae::LivesUIComponent>(livesHud.get()));
	//scene.Add(livesHud);

	auto starship = std::make_shared<dae::GameObject>();
	starship->AddComponent(std::make_shared<dae::GalagaPlayer>(starship.get()));
	starship->AddComponent(std::make_shared<dae::Collision>(starship.get()));
	//starship->GetComponent<dae::Collision>()->AddObserverComponent(livesHud->GetComponent<dae::LivesUIComponent>().get());
	
	starship->SetPosition(200, 400);
	auto& input = dae::InputManager::GetInstance();
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 100.0f), SDL_SCANCODE_D);
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 100.0f), SDL_SCANCODE_A);
	input.CreateCommandKeyBoard(std::make_unique<dae::KillCommand>(starship.get()), SDL_SCANCODE_K);
	input.CreateCommandKeyBoard(std::make_unique<dae::FireCommand>(starship.get()), SDL_SCANCODE_F);
	auto& ss = ServiceLocator::get_Sound_System();
	ss.LoadSound("../Data/PlayerShoot.wav");
	scene.Add(starship);

	auto Boss = std::make_shared<dae::GameObject>();
	Boss->SetPosition(200, 200);
	Boss->AddComponent(std::make_shared<dae::BossGalaga>(Boss.get()));
	input.CreateCommandKeyBoard(std::make_unique<dae::ChangeStateCommandHit>(Boss.get()), SDL_SCANCODE_W);
	input.CreateCommandKeyBoard(std::make_unique<dae::ChangeStateCommandDeath>(Boss.get()), SDL_SCANCODE_S);
	scene.Add(Boss);

	auto Bee = std::make_shared<dae::GameObject>();
	Bee->AddComponent(std::make_shared<dae::Bee>(Bee.get()));
	Bee->SetPosition(0, 0);
	scene.Add(Bee);

	auto butterfly = std::make_shared<dae::GameObject>();
	butterfly->AddComponent(std::make_shared<dae::Butterfly>(butterfly.get()));
	butterfly->SetPosition(30, 30);
	scene.Add(butterfly);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}