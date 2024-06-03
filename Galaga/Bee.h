#pragma once
#include <Component.h>
namespace dae
{
	class Bee final: public Component
	{
	public:
		Bee(GameObject* pOwner);
		~Bee() = default;
	};
}