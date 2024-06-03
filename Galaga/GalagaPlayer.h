#pragma once
#include <Component.h>

namespace dae
{
	class GalagaPlayer final: public Component
	{
	public:
		GalagaPlayer(GameObject* pOwner);
		~GalagaPlayer() = default;
	};
}