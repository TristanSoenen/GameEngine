#pragma once
#include <Component.h>

namespace dae
{
	class GameObject;
	class Rocket : public Component
	{
	public:
		Rocket(GameObject* pOwner);
		~Rocket() = default;
		
		void Update() override;

	private:

	};
}
