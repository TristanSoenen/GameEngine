#include "BossGalaga.h"
#include "RenderComponent.h"
#include "CollisionComponent.h"
#include "structs.h"

dae::BossGalaga::BossGalaga(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
	GameSizes size{};
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Boss.png", size.characterSizes));
	auto renderComp = pOwner->GetComponent<dae::RenderComponent>();
	m_CurrentState = std::make_unique<dae::EnterGame>(pOwner, EnemyTypes::BOSS);

	pOwner->AddComponent(std::make_shared<dae::CollisionComponent>(pOwner, dae::CollisionTypes::Enemy));
	pOwner->GetComponent <dae::CollisionComponent>()->AddCollisionObserver(this);
}

void dae::BossGalaga::Update()
{
	m_CurrentState->Update();
}

void dae::BossGalaga::ChangeState(std::unique_ptr<dae::EnemyState> state)
{
	//Chat gpt helped with this function will change it later.
	m_CurrentState->OnExit();
	m_CurrentState = std::move(state);
	m_CurrentState->OnEnter();
}

void dae::BossGalaga::Notify(dae::Event event)
{
	switch (event.type)
	{
	case HIT:
		if (m_AlreadyHit == true)
		{
			auto owner = GetOwner();
			owner->GetComponent<CollisionComponent>()->RemoveFromCollisionVector();
			dae::Event notifyEvent{};
			notifyEvent.type = BOSSGALAGA_DIED;
			NotifyObservers(notifyEvent);
			GetOwner()->MarkForDead();
		}
		else
		{
			GetOwner()->GetComponent<dae::RenderComponent>()->SetTexture("../Data/BossHit.png");
			m_AlreadyHit = true;
		}
		break;
	}
}

void dae::BossGalaga::AddObserverToBoss(dae::Observer* obs)
{
	AddObserver(obs);
}