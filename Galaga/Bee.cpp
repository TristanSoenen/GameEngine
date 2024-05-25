#include "Bee.h"
#include "RenderComponent.h"

dae::Bee::Bee(GameObject* pOwner)
	:dae::Component(pOwner)
{
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Bee.png", glm::vec2(20, 20)));
}
