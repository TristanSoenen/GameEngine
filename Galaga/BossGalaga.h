#pragma once
#include <Component.h>
#include <Observer.h>
#include <subject.h>
#include "EnemyStates.h"

namespace dae
{
	class EnemyState;
	class BossGalaga final: public Component, Observer, Subject
	{
	public:
		BossGalaga(GameObject* pOwner);
		~BossGalaga() = default;
		void Update() override;

		void ChangeState(std::unique_ptr<EnemyState> state);
		void Notify(Event event) override;
		void AddObserverToBoss(Observer* obs);
	private:
		bool m_AlreadyHit = false;
		std::unique_ptr<EnemyState> m_CurrentState;
	};
}


