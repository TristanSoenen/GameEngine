#include "MovementComponent.h"
#include <iostream>

dae::MovementComponent::MovementComponent(GameObject* pOwner)
	:Component{ pOwner }
{
	m_MovementSpeed = 5.0f;
}

void dae::MovementComponent::MovementInput()
{
	std::cout << "move";
}