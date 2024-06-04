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
	m_CurrentState = std::move( std::make_unique<dae::BossNormalState>(renderComp));

	pOwner->AddComponent(std::make_shared<dae::CollisionComponent>(pOwner, dae::CollisionTypes::Enemy));
	pOwner->GetComponent <dae::CollisionComponent>()->AddCollisionObserver(this);
}

void dae::BossGalaga::ChangeState(std::unique_ptr<dae::BossGalagaVisualState> state)
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