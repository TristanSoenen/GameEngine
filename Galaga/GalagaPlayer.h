#pragma once
#include <Component.h>

namespace dae
{
	class GameObject;
	class GalagaPlayer : public Component
	{
		GalagaPlayer(GameObject* pOwner);
		~GalagaPlayer() = default;
	};
}