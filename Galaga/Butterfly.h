#pragma once
#include <Component.h>
namespace dae
{
	class GameObject;
	class Butterfly : public Component
	{
		Butterfly(GameObject* pOwner);
		~Butterfly() = default;
	};
}


