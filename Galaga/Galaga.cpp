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
	auto& sceneShotsFired = dae::SceneManager::GetInstance().CreateScene("shotsfired");
	/*auto spacebackground1 = std::make_shared<dae::GameObject>();
	spacebackground1->AddComponent<dae::RenderComponent>();
	spacebackground1->SetTexture("Background.png");
	spacebackground1->SetPosition(50, 0);
	scene.Add(spacebackground1);*/

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

	auto info3 = std::make_shared<dae::TextObject>("use Z forHitState and S for explode State", font2);
	info3->SetPosition(5, 80);
	scene.Add(info3);

	auto fpsObj = std::make_shared<dae::GameObject>();

	fpsObj->AddComponent(std::make_shared<dae::FPSComponent>(fpsObj.get(), 1));
	fpsObj->SetPosition(20, 20);
	scene.Add(fpsObj);

	auto livesHud = std::make_shared<dae::GameObject>();
	livesHud->AddComponent(std::make_shared<dae::LivesUIComponent>(livesHud.get()));
	scene.Add(livesHud);

	auto starship = std::make_shared<dae::GameObject>();
	starship->AddComponent(std::make_shared<dae::RenderComponent>(starship.get()));
	starship->AddComponent(std::make_shared<dae::Collision>(starship.get()));
	starship->GetComponent<dae::Collision>()->AddObserverComponent(livesHud->GetComponent<dae::LivesUIComponent>().get());
	
	starship->SetTexture("starship.png");
	starship->SetPosition(200, 400);
	auto& input = dae::InputManager::GetInstance();
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ 1.0f, 0.0f, 0.0f }, 100.0f), SDL_SCANCODE_D);
	input.CreateCommandKeyBoard(std::make_unique<dae::MoveCommand>(starship.get(), glm::vec3{ -1.0f, 0.0f, 0.0f }, 100.0f), SDL_SCANCODE_A);
	input.CreateCommandKeyBoard(std::make_unique<dae::KillCommand>(starship.get()), SDL_SCANCODE_K);
	input.CreateCommandKeyBoard(std::make_unique<dae::FireCommand>(starship.get()), SDL_SCANCODE_F);
	auto& ss = ServiceLocator::get_Sound_System();
	ss.LoadSound("../Data/PlayerShoot.wav");
	scene.Add(starship);

	auto shotsfired = std::make_shared<dae::GameObject>();
	shotsfired->SetPosition(200, 200);
	shotsfired->AddComponent(std::make_shared<dae::RenderComponent>(shotsfired.get()));
	shotsfired->AddComponent(std::make_shared<dae::BossGalaga>(shotsfired.get()));
	input.CreateCommandKeyBoard(std::make_unique<dae::ChangeStateCommandHit>(shotsfired.get()), SDL_SCANCODE_W);
	input.CreateCommandKeyBoard(std::make_unique<dae::ChangeStateCommandDeath>(shotsfired.get()), SDL_SCANCODE_S);
	shotsfired->SetTexture("Boss.png");
	sceneShotsFired.Add(shotsfired);
}

int main(int, char*[]) {
	dae::Minigin engine("../Data/");
	engine.Run(load);
    return 0;
}