#include "MovementComponent.h"

dae::MovementComponent::MovementComponent(GameObject* pOwner)
	:Component{ pOwner }
{
	m_MovementSpeed = 5.0f;
}

void dae::MovementComponent::MovementInput()
{

}