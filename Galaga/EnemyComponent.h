#pragma once
#include <Component.h>
#include <Observer.h>
#include <subject.h>
#include "EnemyStates.h"
#include "Structs.h"

namespace dae
{
    class EnemyComponent : public Component, Subject, Observer
    {
	public:
		EnemyComponent(GameObject* pOwner, glm::vec2 squadPos, EnemyTypes type);
		~EnemyComponent() = default;
		void Update() override;
		void RemoveCollisionAndMarkForDead();

		void ChangeState(std::unique_ptr<EnemyState> state)
		{
			//Chat gpt helped with this function will change it later.
			m_CurrentState->OnExit();
			m_CurrentState = std::move(state);
			m_CurrentState->OnEnter();
		}

		void Notify(Event event) override;
		void AddObserverToEnemy(Observer* obs) { AddObserver(obs); }
		void SetAttack(bool value) { m_Attack = value; }
		bool GetAttack() const { return m_Attack; }
		glm::vec2 GetSquadPosition() const { return m_PositionInSquad; }

		void SetInPosition(bool value) { m_InPosition = value; }
		bool GetInPositions() const { return m_InPosition; }
	private:
		EnemyTypes m_Type;
		glm::vec2 m_PositionInSquad;
		bool m_AlreadyHit = false;
		bool m_Attack = false;
		bool m_InPosition = false;
		std::unique_ptr<EnemyState> m_CurrentState;
    };

}

