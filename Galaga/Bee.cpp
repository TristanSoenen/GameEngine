#include "Bee.h"
#include "RenderComponent.h"
#include "Structs.h"

dae::Bee::Bee(GameObject* pOwner)
	:dae::Component(pOwner)
{
	GameSizes size{};
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Bee.png", size.characterSizes));
}
