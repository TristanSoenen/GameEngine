#include "GalagaPlayer.h"
#include "RenderComponent.h"
#include "RocketLauncher.h"
#include "CollisionComponent.h"
#include "TransformComponent.h"
#include "Structs.h"

dae::GalagaPlayer::GalagaPlayer(GameObject* pOwner)
	:dae::Component(pOwner)
{
	GameSizes size{};
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/StarShip.png", size.characterSizes));

	//add rocket Launcher
	pOwner->AddComponent(std::make_shared<dae::RocketLauncher>(pOwner, true));

	//add CollisionComponent
	pOwner->AddComponent(std::make_shared<dae::CollisionComponent>(pOwner, dae::CollisionTypes::Player));
	pOwner->GetComponent<dae::CollisionComponent>()->AddCollisionObserver(this);

	m_TranformComp = pOwner->GetComponent<dae::TransformComponent>();
}

void dae::GalagaPlayer::Notify(dae::Event event)
{
	switch (event.type)
	{
	case HIT:
		--m_Lives;
		dae::Event notifyEvent{};
		if (m_Lives < 0)
		{
			auto owner = GetOwner();
			owner->GetComponent<CollisionComponent>()->RemoveFromCollisionVector();

			notifyEvent.type = GAME_OVER;
			NotifyObservers(notifyEvent);
			owner->MarkForDead();
		}
		notifyEvent.type = PLAYER_DIED;
		NotifyObservers(notifyEvent);
		break;
	}
}