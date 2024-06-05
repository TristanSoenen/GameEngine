#pragma once
#include <Component.h>
#include <Subject.h>
namespace dae
{
	class Observer;
	class RocketLauncher final: public Component, Subject
	{
	public:
		RocketLauncher(GameObject* pOwner, bool onPlayer);
		~RocketLauncher() = default;
		void FireRocket();
		void IncrementHitCount()
		{
			if (m_AttachedToPlayer)
			{
				Event eve{};
				eve.type = HIT;
				NotifyObservers(eve);
			}
		}
		void DecrementRocketCount() 
		{
			--m_RocketCount; 
			if (m_RocketCount < 0)
				m_RocketCount = 0;
		}

		void AddObserverToLauncher(Observer* obs)
		{
			AddObserver(obs);
		}
	private:
		int m_RocketCount = 0;
		const int m_MaxRocketFiredCount = 2;
		bool m_AttachedToPlayer;
	};
}