#pragma once
#include "Component.h"
namespace dae
{
	class GameObject;
	class TransformComponent;

	enum class Direction
	{
		Up,
		Down,
		Left,
		Right,
		none
	};

	class MovementComponent : public Component
	{
	public:
		MovementComponent(GameObject* pOwner);
		~MovementComponent() = default;
		void MovementInput(Direction direction);
		
	private:
		std::shared_ptr<TransformComponent> m_TransformComp;
		float m_MovementSpeed;
		Direction m_direction = Direction::none;
	};
}