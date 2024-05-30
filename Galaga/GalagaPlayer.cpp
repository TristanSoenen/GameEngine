#include "GalagaPlayer.h"
#include "RenderComponent.h"
#include "RocketLauncher.h"
#include "Structs.h"

dae::GalagaPlayer::GalagaPlayer(GameObject* pOwner)
	:dae::Component(pOwner)
{
	GameSizes size{};
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/StarShip.png", size.characterSizes));

	//add rocket Launcher
	pOwner->AddComponent(std::make_shared<dae::RocketLauncher>(pOwner));
}