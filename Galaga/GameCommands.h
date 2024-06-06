#pragma once
#include "Command.h"
#include "RocketLauncher.h"

namespace dae
{
	class RenderComponent;
	class BossGalaga;
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
			auto actor = GetGameActor();
			if (actor->GetMarkedForDead() == false)
			{
				auto rocketlauncher = actor->GetComponent<RocketLauncher>();
				rocketlauncher->FireRocket();
			}
		}
	};
}