#pragma once
#include <Component.h>
#include "BossGalagaVisualState.h"

namespace dae
{
	class GameObject;
	class BossGalaga : public Component
	{
	public:
		BossGalaga(GameObject* pOwner);
		~BossGalaga() = default;
		void ChangeState(std::unique_ptr<BossGalagaVisualState> state);

	private:
		std::unique_ptr<BossGalagaVisualState> m_CurrentState;
	};
}


