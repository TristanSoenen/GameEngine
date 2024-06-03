#pragma once
#include <Component.h>

namespace dae
{
	class Rocket final: public Component
	{
	public:
		Rocket(GameObject* pOwner);
		~Rocket() = default;
		
		//void Update() override;

	private:

	};
}
