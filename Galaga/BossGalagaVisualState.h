#pragma once
#include "memory"
namespace dae
{
	class GameObject;
	class BossGalagaVisualState
	{
	public:
		BossGalagaVisualState() = default;
		virtual ~BossGalagaVisualState() = default;
		virtual void OnEnter() {};
		virtual void OnExit() {};
	};

	class BossNormalState : BossGalagaVisualState
	{
	public:
		BossNormalState() = default;
		~BossNormalState() = default;
		//void OnEnter() override
		//{
		//}
	};

	class BossHitState : BossGalagaVisualState
	{
	public:
		BossHitState() = default;
		~BossHitState() = default;
		//void OnEnter() override
		//{
		//}
	};

	class BossExplode : BossGalagaVisualState
	{
	public:
		BossExplode() = default;
		~BossExplode() = default;
		//void OnEnter() override
		//{
		//}
	};
}