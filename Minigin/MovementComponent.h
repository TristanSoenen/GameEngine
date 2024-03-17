#pragma once
#include "Component.h"
namespace dae
{
	class GameObject;
	class TransformComponent;

	class MovementComponent : public Component
	{
	public:
		MovementComponent(GameObject* pOwner);
		~MovementComponent() = default;
		void MovementInput();
	private:
		float m_MovementSpeed;
	};
}