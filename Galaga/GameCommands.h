#pragma once
#include "Command.h"
#include "RocketLauncher.h"
#include "GameComponent.h"
#include "ServiceLocator.h"

namespace dae
{
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
			auto actor = GetGameActor();
			if (actor->GetMarkedForDead() == false)
			{
				auto rocketlauncher = actor->GetComponent<RocketLauncher>();
				rocketlauncher->FireRocket();
			}
		}
	};

	class MuteCommand : public GameActorCommand
	{
	public:
		MuteCommand(GameObject* actor)
			:GameActorCommand(actor)
		{

		}

		~MuteCommand() = default;

		void Execute() override
		{
			auto ss = ServiceLocator::get_Sound_System();
			ss->Mute();
		}
	};

	class SwitchHighScoresCommand : public GameActorCommand
	{
	public:
		SwitchHighScoresCommand(GameObject* actor)
			:GameActorCommand(actor)
		{

		}

		~SwitchHighScoresCommand() = default;

		void Execute() override
		{
			auto actor = GetGameActor();
			auto rocketlauncher = actor->GetComponent<GameComponent>();
 			rocketlauncher->SwitchToHighScores();
		}
	};
}