#pragma once
#include "GameObject.h"
#include "MovementComponent.h"
namespace dae
{
	class Command
	{
	public:
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
		GameActorCommand(GameObject* actor) { m_actor = actor; }
		virtual ~GameActorCommand() {};
	};

	class Move : public GameActorCommand
	{
	private:

	public:
		void Execute() override { GetGameActor()->GetComponent<dae::MovementComponent>()->MovementInput(); }
	};
}