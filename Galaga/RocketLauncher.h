#pragma once
#include <Component.h>
namespace dae
{
	class RocketLauncher final: public Component
	{
	public:
		RocketLauncher(GameObject* pOwner);
		~RocketLauncher() = default;
		void FireRocket();
	};
}