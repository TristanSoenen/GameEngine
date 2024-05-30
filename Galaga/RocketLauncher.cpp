#include "RocketLauncher.h"
#include "Rocket.h"
#include "SceneManager.h"
#include "Scene.h"
#include "Structs.h"

dae::RocketLauncher::RocketLauncher(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{

}

void dae::RocketLauncher::FireRocket()
{
	auto rocket = std::make_shared<dae::GameObject>();
	rocket->AddComponent(std::make_shared<dae::Rocket>(rocket.get()));
	auto owner = GetOwner();
	glm::vec3 pos = owner->GetWorldPosition();
	GameSizes sizes{};
	rocket->SetPosition(pos.x + (sizes.characterSizes.x / 2.0f) - (sizes.rocketSize.x /2.0f), pos.y - sizes.rocketSize.y);
	auto& scene = SceneManager::GetInstance().GetCurrentScene();
	scene.Add(rocket);
}