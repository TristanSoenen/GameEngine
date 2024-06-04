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
	private:
		bool m_AttachedToPlayer;
	};
}