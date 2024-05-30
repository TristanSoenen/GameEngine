#include "Rocket.h"
#include "RenderComponent.h"
#include "Structs.h"

dae::Rocket::Rocket(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
	GameSizes size{};
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Rocket.png", size.rocketSize));
}