#pragma once
#include "Command.h"
#include "BossGalagaVisualState.h"
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
			auto rocketlauncher = actor->GetComponent<RocketLauncher>();
			rocketlauncher->FireRocket();
			auto& ss = ServiceLocator::get_Sound_System();
			ss.Play(0, 100.0f);
		}
	};

	class ChangeStateCommandHit : public GameActorCommand
	{
	public:
		ChangeStateCommandHit(GameObject* actor)
			:GameActorCommand(actor)
		{

		}

		~ChangeStateCommandHit() = default;

		void Execute() override
		{
			//call change state function on boss galaga
			auto actor = GetGameActor();
			auto galageBoss = actor->GetComponent<BossGalaga>();
			auto renderComp = actor->GetComponent<RenderComponent>();
			galageBoss->ChangeState(std::make_unique<BossHitState>(renderComp));
		}
	};

	class ChangeStateCommandDeath : public GameActorCommand
	{
	public:
		ChangeStateCommandDeath(GameObject* actor)
			:GameActorCommand(actor)
		{

		}

		~ChangeStateCommandDeath() = default;

		void Execute() override
		{
			//call change state function on boss galaga
			auto actor = GetGameActor();
			auto galageBoss = actor->GetComponent<BossGalaga>();
			auto renderComp = actor->GetComponent<RenderComponent>();
			galageBoss->ChangeState(std::make_unique<BossExplode>(renderComp));
		}
	};
}


