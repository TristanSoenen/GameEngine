#include "Butterfly.h"
#include "RenderComponent.h"

dae::Butterfly::Butterfly(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Butterfly.png", glm::vec2(20, 20)));
}