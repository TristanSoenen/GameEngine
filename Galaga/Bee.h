#pragma once
#include <Component.h>
namespace dae
{
	class GameObject;
	class Bee : public Component
	{
		Bee(GameObject* pOwner);
		~Bee() = default;
	};
}