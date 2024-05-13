#include "BossGalaga.h"
#include "RenderComponent.h"

dae::BossGalaga::BossGalaga(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
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