#pragma once
#include "GameObject.h"
#include "MovementComponent.h"
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

	class MoveUp : public GameActorCommand
	{
	public:
		MoveUp(GameObject* actor) : GameActorCommand{ actor } {};
		~MoveUp() = default;
		void Execute() override { GetGameActor()->GetComponent<dae::MovementComponent>()->MovementInput(dae::Direction::Up); }
	};
	class MoveDown : public GameActorCommand
	{
	public:
		MoveDown(GameObject* actor) : GameActorCommand{ actor } {};
		~MoveDown() = default;
		void Execute() override { GetGameActor()->GetComponent<dae::MovementComponent>()->MovementInput(dae::Direction::Down); }
	};
	class MoveLeft : public GameActorCommand
	{
	public:
		MoveLeft(GameObject* actor) : GameActorCommand{ actor } {};
		~MoveLeft() = default;
		void Execute() override { GetGameActor()->GetComponent<dae::MovementComponent>()->MovementInput(dae::Direction::Left); }
	};
	class MoveRight : public GameActorCommand
	{
	public:
		MoveRight(GameObject* actor) : GameActorCommand{ actor } {};
		~MoveRight() = default;
		void Execute() override { GetGameActor()->GetComponent<dae::MovementComponent>()->MovementInput(dae::Direction::Right); }
	};
}