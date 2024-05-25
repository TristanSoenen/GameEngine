#include "BossGalaga.h"
#include "RenderComponent.h"

dae::BossGalaga::BossGalaga(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Boss.png", glm::vec2(20, 20)));
	auto renderComp = pOwner->GetComponent<dae::RenderComponent>();
	m_CurrentState = std::move( std::make_unique<dae::BossNormalState>(renderComp));
}

void dae::BossGalaga::ChangeState(std::unique_ptr<dae::BossGalagaVisualState> state)
{
	//Chat gpt helped with this function will change it later.
	m_CurrentState->OnExit();
	m_CurrentState = std::move(state);
	m_CurrentState->OnEnter();
}