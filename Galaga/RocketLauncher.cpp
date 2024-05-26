#include "RocketLauncher.h"
#include "SceneManager.h"

dae::RocketLauncher::RocketLauncher(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{

}

void dae::RocketLauncher::FireRocket()
{
	auto rocket = std::make_shared<dae::GameObject>();
	dae::SceneManager::GetInstance();
}