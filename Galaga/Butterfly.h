#pragma once
#include <Component.h>
namespace dae
{
	class GameObject;
	class Butterfly : public Component
	{
	public:
		Butterfly(GameObject* pOwner);
		~Butterfly() = default;
	};
}


