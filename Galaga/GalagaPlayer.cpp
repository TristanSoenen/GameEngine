#include "GalagaPlayer.h"
#include "RenderComponent.h"

dae::GalagaPlayer::GalagaPlayer(GameObject* pOwner)
	:dae::Component(pOwner)
{
	//add the render component
	pOwner->AddComponent(std::shared_ptr<RenderComponent>());
}