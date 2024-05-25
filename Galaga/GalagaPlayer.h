#pragma once
#include <Component.h>

namespace dae
{
	class GameObject;
	class GalagaPlayer : public Component
	{
	public:
		GalagaPlayer(GameObject* pOwner);
		~GalagaPlayer() = default;
	};
}