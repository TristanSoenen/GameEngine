#pragma once
#include <Component.h>
namespace dae
{
	class GameObject;
	class Bee : public Component
	{
	public:
		Bee(GameObject* pOwner);
		~Bee() = default;
	};
}