#include "MovementComponent.h"
#include "TransformComponent.h"
#include "DeltaTime.h"
#include "glm/glm.hpp"
#include <iostream>

dae::MovementComponent::MovementComponent(GameObject* pOwner)
	:Component{ pOwner }
	,m_MovementSpeed{100.0f}
{
	m_TransformComp = pOwner->GetComponent<dae::TransformComponent>();
	assert(m_TransformComp);
}

void dae::MovementComponent::MovementInput(Direction direction)
{
	float deltaTime = DeltaTime::GetInstance().GetDeltaTime();
	m_direction = direction;
	auto currentPosition = m_TransformComp->GetPosition();
	glm::vec3 nextPos = currentPosition;
	switch (m_direction)
	{
	case dae::Direction::Up:
		nextPos.y -= m_MovementSpeed * deltaTime;
		break;
	case dae::Direction::Down:
		nextPos.y += m_MovementSpeed * deltaTime;
		break;
	case dae::Direction::Left:
		nextPos.x -= m_MovementSpeed * deltaTime;
		break;
	case dae::Direction::Right:
		nextPos.x += m_MovementSpeed * deltaTime;
		break;
	case dae::Direction::none:
		break;
	default:
		break;
	}
	m_TransformComp->SetPosition(nextPos.x, nextPos.y, nextPos.z);
}