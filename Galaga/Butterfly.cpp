#include "Butterfly.h"
#include "RenderComponent.h"
#include "structs.h"

dae::Butterfly::Butterfly(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
	GameSizes size{};
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Butterfly.png", size.characterSizes));
}