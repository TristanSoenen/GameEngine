#include "RotationComponent.h"
#include "TransformComponent.h"
#include "DeltaTime.h"
#include "cassert"
#include "glm/glm.hpp"

dae::RotationComponent::RotationComponent(GameObject* pOwner) 
	:dae::Component{pOwner}
	,m_Speed{3.14159f / 2.0f}
	,m_Radius{50.0f}
	,m_MiddlePointCircle{200.0f, 200.0f}
	,m_Position{}
{
	m_TransformComp = pOwner->GetComponent<dae::TransformComponent>();
	assert(m_TransformComp);
}

void dae::RotationComponent::Update()
{
	m_ElapsedTime += DeltaTime::GetInstance().GetDeltaTime();
	float angle{ m_Speed * m_ElapsedTime };
	glm::vec2 nextPos{m_MiddlePointCircle.x + m_Radius * std::cosf(angle), m_MiddlePointCircle.y + m_Radius * std::sinf(angle)};
	m_Position = nextPos;
	m_TransformComp->SetPosition(m_Position.x, m_Position.y, 0.0f);
}