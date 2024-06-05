#pragma once
#include <Component.h>
namespace dae
{
	class Observer;
	class RocketLauncher final: public Component
	{
	public:
		RocketLauncher(GameObject* pOwner, bool onPlayer);
		~RocketLauncher() = default;
		void FireRocket();
		void DecrementRocketCount() 
		{ 
			--m_RocketCount; 
			if (m_RocketCount < 0)
				m_RocketCount = 0;
		}
	private:
		int m_RocketCount = 0;
		const int m_MaxRocketFiredCount = 2;
		bool m_AttachedToPlayer;
	};
}