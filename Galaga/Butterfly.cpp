#include "Butterfly.h"
#include "RenderComponent.h"
#include "CollisionComponent.h"
#include "structs.h"

dae::Butterfly::Butterfly(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
	GameSizes size{};
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Butterfly.png", size.characterSizes));

	pOwner->AddComponent(std::make_shared<dae::CollisionComponent>(pOwner, dae::CollisionTypes::Enemy));
	pOwner->GetComponent <dae::CollisionComponent>()->AddCollisionObserver(this);
}

void dae::Butterfly::Notify(dae::Event event)
{
	switch (event.type)
	{
	case HIT:
		auto owner = GetOwner();
		owner->GetComponent<CollisionComponent>()->RemoveFromCollisionVector();
		dae::Event notifyEvent{};
		notifyEvent.type = BUTTERFLY_DIED;
		NotifyObservers(notifyEvent);
		owner->MarkForDead();
		break;
	}
}