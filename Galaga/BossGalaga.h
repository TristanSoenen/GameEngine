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
		void SetAttack(bool value) { m_Attack = value; }
		void SetInPosition(bool value) { m_InPosition = value; }
		bool GetAttack() const { return m_Attack; }
		bool GetInPositions() const { return m_InPosition; }
		glm::vec2 GetSquadPosition() const { return m_PositionInSquad; }
	private:
		glm::vec2 m_PositionInSquad;
		bool m_AlreadyHit = false;
		bool m_Attack = true;
		bool m_InPosition = false;
		glm::vec3 m_StartSide;
		std::unique_ptr<EnemyState> m_CurrentState;
	};
}