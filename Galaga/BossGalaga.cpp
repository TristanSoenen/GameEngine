#include "BossGalaga.h"

dae::BossGalaga::BossGalaga(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
	//m_CurrentState = std::make_unique<dae::BossNormalState>();
}

void dae::BossGalaga::ChangeState(std::unique_ptr<dae::BossGalagaVisualState> state)
{
	m_CurrentState->OnExit();
	m_CurrentState = std::move(state);
	m_CurrentState->OnEnter();
}