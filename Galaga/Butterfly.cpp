#include "Butterfly.h"
#include "RenderComponent.h"

dae::Butterfly::Butterfly(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
	//add the render component
	pOwner->AddComponent(std::shared_ptr<dae::RenderComponent>());


}