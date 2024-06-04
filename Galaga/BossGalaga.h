#pragma once
#include <Component.h>
#include <Observer.h>
#include "BossGalagaVisualState.h"

namespace dae
{
	class BossGalaga final: public Component, Observer
	{
	public:
		BossGalaga(GameObject* pOwner);
		~BossGalaga() = default;
		void ChangeState(std::unique_ptr<BossGalagaVisualState> state);
		void Notify(Event event) override;

	private:
		bool m_AlreadyHit = false;
		std::unique_ptr<BossGalagaVisualState> m_CurrentState;
	};
}


