#pragma once
#include "Command.h"
namespace dae
{
	class KillCommand : public GameActorCommand
	{
	public:
		KillCommand(GameObject* actor)
			:GameActorCommand(actor)
		{

		}
		~KillCommand() = default;

		void Execute() override
		{

		}
	};

	class FireCommand : public GameActorCommand
	{
	public:
		FireCommand(GameObject* actor)
			:GameActorCommand(actor)
		{

		}

		~FireCommand() = default;

		void Execute() override
		{
			auto& ss = ServiceLocator::get_Sound_System();
			ss.Play(0, 100.0f);
		}
	};

	class ChangeStateCommand : public GameActorCommand
	{
	public:
		ChangeStateCommand(GameObject* actor)
			:GameActorCommand(actor)
		{

		}

		~ChangeStateCommand() = default;

		void Execute() override
		{
			//call change state function on boss galaga
			
		}
	};
}


