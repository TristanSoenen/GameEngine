#include "GalagaPlayer.h"
#include "RenderComponent.h"
#include "RocketLauncher.h"

dae::GalagaPlayer::GalagaPlayer(GameObject* pOwner)
	:dae::Component(pOwner)
{
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/StarShip.png", glm::vec2(20, 20)));

	//add rocket Launcher
	pOwner->AddComponent(std::make_shared<dae::RocketLauncher>(pOwner));
}