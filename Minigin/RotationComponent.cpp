#include "RotationComponent.h"
#include "TransformComponent.h"
#include "DeltaTime.h"
#include "cassert"
#include "glm/glm.hpp"

dae::RotationComponent::RotationComponent(GameObject* pOwner) 
	:dae::Component{pOwner}
{
	glm::vec2 RotationPoint{};
	glm::vec2 m_position{ 100.0f, 100.0f };
	m_TransformComp = pOwner->GetComponent<dae::TransformComponent>();
	assert(m_TransformComp);
}

void dae::RotationComponent::Update()
{
	glm::vec2 middlePoint{ 200.0f, 200.0f};
	float radius{ 20.0f };
	float deltaTime = DeltaTime::GetInstance().GetDeltaTime();
	float pi{ 3.14159f };
	float speed{ pi / 20.0f };
	float angle{ speed * deltaTime };
	glm::vec2 nextPos{middlePoint.x + radius * std::cosf(angle), middlePoint.y + radius * std::sinf(angle)};
	m_Position = nextPos;
	m_TransformComp->SetPosition(m_Position.x, m_Position.y, 0.0f);
}