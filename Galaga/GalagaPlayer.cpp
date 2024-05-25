#include "GalagaPlayer.h"
#include "RenderComponent.h"

dae::GalagaPlayer::GalagaPlayer(GameObject* pOwner)
	:dae::Component(pOwner)
{
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/StarShip.png", glm::vec2(20, 20)));
}