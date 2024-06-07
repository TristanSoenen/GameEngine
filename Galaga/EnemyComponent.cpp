#include "EnemyComponent.h"
#include "RenderComponent.h"
#include "CollisionComponent.h"

dae::EnemyComponent::EnemyComponent(dae::GameObject* pOwner, glm::vec2 squadPos, EnemyTypes type)
	:dae::Component(pOwner)
	,m_PositionInSquad(squadPos)
	,m_Type(type)
{
	GameSizes size{};
	m_CurrentState = std::make_unique<dae::InPosition>(pOwner);
	switch(type)
	{
	case dae::BEE:
		pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Bee.png", size.characterSizes));
		break;
	case dae::BUTTERFLY:
		pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Butterfly.png", size.characterSizes));
		break;
	case dae::BOSS:
		pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Boss.png", size.characterSizes));
		break;
	}
	auto renderComp = pOwner->GetComponent<dae::RenderComponent>();
	m_CurrentState = std::make_unique<dae::EnterGame>(pOwner, m_PositionInSquad);
	m_CurrentState->OnEnter();
	pOwner->AddComponent(std::make_shared<dae::CollisionComponent>(pOwner, dae::CollisionTypes::Enemy));
	pOwner->GetComponent <dae::CollisionComponent>()->AddCollisionObserver(this);
}

void dae::EnemyComponent::Update()
{
	m_CurrentState->Update();
}

void dae::EnemyComponent::Notify(Event event)
{
	dae::Event notifyEvent{};
	switch (event.type)
	{
	case HIT:
		auto owner = GetOwner();
		switch (m_Type)
		{
		case dae::BEE:
			notifyEvent.type = BEE_DIED;
			owner->GetComponent<CollisionComponent>()->RemoveFromCollisionVector();
			NotifyObservers(notifyEvent);
			GetOwner()->MarkForDead();
			break;
		case dae::BUTTERFLY:
			notifyEvent.type = BUTTERFLY_DIED;
			owner->GetComponent<CollisionComponent>()->RemoveFromCollisionVector();
			NotifyObservers(notifyEvent);
			GetOwner()->MarkForDead();
			break;
		case dae::BOSS:
			if (m_AlreadyHit == true)
			{
				notifyEvent.type = BOSSGALAGA_DIED;
				owner->GetComponent<CollisionComponent>()->RemoveFromCollisionVector();
				NotifyObservers(notifyEvent);
				GetOwner()->MarkForDead();
			}
			else
			{
				owner->GetComponent<dae::RenderComponent>()->SetTexture("../Data/BossHit.png");
				m_AlreadyHit = true;
			}
			break;
		}
		break;

	}
}