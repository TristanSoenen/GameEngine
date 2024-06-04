#include "Bee.h"
#include "RenderComponent.h"
#include "CollisionComponent.h"
#include "Structs.h"

dae::Bee::Bee(GameObject* pOwner)
	:dae::Component(pOwner)
{
	GameSizes size{};
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Bee.png", size.characterSizes));

	pOwner->AddComponent(std::make_shared<dae::CollisionComponent>(pOwner, dae::CollisionTypes::Enemy));
	pOwner->GetComponent <dae::CollisionComponent>()->AddCollisionObserver(this);
}

void dae::Bee::Notify(dae::Event event)
{
	switch (event.type)
	{
	case HIT:
		GetOwner()->MarkForDead();
		break;
	}
}
