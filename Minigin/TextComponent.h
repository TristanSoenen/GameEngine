#pragma once
#include "Component.h"
namespace dae
{
	class GameObject;

	class TextComponent : public Component
	{
	public:
		TextComponent(GameObject* pOwner);
		~TextComponent() = default;
	private:

	};
}