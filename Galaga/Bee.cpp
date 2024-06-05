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
		auto owner = GetOwner();
		owner->GetComponent<CollisionComponent>()->RemoveFromCollisionVector();
		dae::Event notifyEvent{};
		notifyEvent.type = BEE_DIED;
		NotifyObservers(notifyEvent);
		owner->MarkForDead();
		break;
	}
}
