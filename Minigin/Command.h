#pragma once
#include "glm/glm.hpp"
#include "GameObject.h"
#include "DeltaTime.h"

namespace dae
{
	class Command
	{
	public:
		Command() {};

		virtual ~Command() = default;
		virtual void Execute() = 0;
	};

	class GameActorCommand : public Command
	{
	private: 
		GameObject* m_actor;
	protected:
		GameObject* GetGameActor() const { return m_actor; }
	public:
		GameActorCommand(GameObject* actor) 
			:Command()
			,m_actor{actor}
		{}
		virtual ~GameActorCommand() = default;
	};

	class MoveCommand : public GameActorCommand
	{
		glm::vec3 m_Direction;
		float m_MoveSpeed;
	public:
		MoveCommand(GameObject* actor, const glm::vec3 direction, const float moveSpeed)
			: GameActorCommand(actor)
			, m_Direction(direction)
			, m_MoveSpeed(moveSpeed)
		{

		}

		~MoveCommand() = default;
		void Execute() override
		{
			glm::vec3 nextPos = GetGameActor()->GetWorldPosition();
			nextPos += glm::normalize(m_Direction) * m_MoveSpeed *  DeltaTime::GetInstance().GetDeltaTime();
			GetGameActor()->SetPosition(nextPos.x, nextPos.y);
		}
	};
}