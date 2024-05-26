#pragma once
#include <Component.h>
namespace dae
{
	class RocketLauncher : public Component
	{
	public:
		RocketLauncher(GameObject* pOwner);
		~RocketLauncher() = default;
		void FireRocket();
	};
}