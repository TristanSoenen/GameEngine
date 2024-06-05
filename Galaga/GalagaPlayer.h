#pragma once
#include <Component.h>
#include "Observer.h"
#include "Subject.h"

namespace dae
{
	class TransformComponent;
	class GalagaPlayer final: public Component, Observer, Subject
	{
	public:
		GalagaPlayer(GameObject* pOwner);
		~GalagaPlayer() = default;
		void Notify(Event event) override;
		void Update() override;
		void AddObserverToPlayer(dae::Observer* obs)
		{
			AddObserver(obs);
		}

		int GetLives() const { return m_Lives; }
	private:
		bool m_FreezePosition;
		std::shared_ptr<TransformComponent> m_TranformComp;
		int m_Lives = 3;
	};
}