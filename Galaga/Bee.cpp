#include "Bee.h"
#include "RenderComponent.h"

dae::Bee::Bee(GameObject* pOwner)
	:dae::Component(pOwner)
{
	//add the render component
	pOwner->AddComponent(std::shared_ptr<dae::RenderComponent>());


}
