#pragma once
#include "memory"
#include "RenderComponent.h"

namespace dae
{
	class GameObject;
	class BossGalagaVisualState
	{
	public:
		BossGalagaVisualState() = default;
		virtual ~BossGalagaVisualState() = default;
		BossGalagaVisualState(const BossGalagaVisualState& other) = delete;
		BossGalagaVisualState(BossGalagaVisualState&& other) = delete;
		BossGalagaVisualState& operator=(const BossGalagaVisualState& other) = delete;
		BossGalagaVisualState& operator=(BossGalagaVisualState&& other) = delete;

		virtual void OnEnter() {};
		virtual void OnExit() {};
	};

	class BossNormalState final : public BossGalagaVisualState
	{
	public:
		BossNormalState(std::shared_ptr<RenderComponent> renderComp)
			: m_RenderComp(renderComp)
		{

		}
		~BossNormalState() = default;
		
		BossNormalState(const BossNormalState& other) = delete;
		BossNormalState(BossNormalState&& other) = delete;
		BossNormalState& operator=(const BossNormalState& other) = delete;
		BossNormalState& operator=(BossNormalState&& other) = delete;

		void OnEnter() override
		{
			m_RenderComp->SetTexture("../Data/Boss.png");
		}
	private: 
		std::shared_ptr<RenderComponent> m_RenderComp;
	};

	class BossHitState final : public BossGalagaVisualState
	{
	public:
		BossHitState(std::shared_ptr<RenderComponent> rendercomp)
			: m_RenderComp(rendercomp)
		{

		}
		~BossHitState() = default;

		BossHitState(const BossHitState& other) = delete;
		BossHitState(BossHitState&& other) = delete;
		BossHitState& operator=(const BossHitState& other) = delete;
		BossHitState& operator=(BossHitState&& other) = delete;

		void OnEnter() override
		{
			m_RenderComp->SetTexture("../Data/Bee.png");
		}
	private:
		std::shared_ptr<RenderComponent> m_RenderComp;
	};

	class BossExplode final : public BossGalagaVisualState
	{
	public:
		BossExplode(std::shared_ptr<RenderComponent> renderComp)
			: m_RenderComp(renderComp)
		{

		}
		~BossExplode() = default;
		BossExplode(const BossExplode& other) = delete;
		BossExplode(BossExplode&& other) = delete;
		BossExplode& operator=(const BossExplode& other) = delete;
		BossExplode& operator=(BossExplode&& other) = delete;

		void OnEnter() override
		{
			m_RenderComp->SetTexture("../Data/DeathEnemy.png");
		}
	private:
		std::shared_ptr<RenderComponent> m_RenderComp;
	};
}