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
		switch (m_Type)
		{
		case dae::BEE:
			if (m_InPosition == true)
			{
				notifyEvent.type = BEE_INPOS_DIED;
			}
			else
			{
				notifyEvent.type = BEE_DIED;
			}
			NotifyObservers(notifyEvent);
			RemoveCollisionAndMarkForDead();
			break;
		case dae::BUTTERFLY:
			if (m_InPosition == true)
			{
				notifyEvent.type = BUTTERFLY_INPOS_DIED;
			}
			else
			{
				notifyEvent.type = BUTTERFLY_DIED;
			}
			NotifyObservers(notifyEvent);
			RemoveCollisionAndMarkForDead();
			break;
		case dae::BOSS:
			if (m_AlreadyHit == true)
			{
				if (m_InPosition == true)
				{
					notifyEvent.type = BOSSGALAGA_INPOS_DIED;
				}
				else
				{
					notifyEvent.type = BOSSGALAGA_DIED;
				}
				NotifyObservers(notifyEvent);
				RemoveCollisionAndMarkForDead();
			}
			else
			{
				auto owner = GetOwner();
				owner->GetComponent<dae::RenderComponent>()->SetTexture("../Data/BossHit.png");
				m_AlreadyHit = true;
			}
			break;
		}
		break;
	}
}

void dae::EnemyComponent::RemoveCollisionAndMarkForDead()
{
	m_Alive = false;
	auto owner = GetOwner();
	owner->GetComponent<CollisionComponent>()->RemoveFromCollisionVector();
	GetOwner()->MarkForDead();
}