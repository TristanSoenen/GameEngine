#include "Rocket.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "Structs.h"

dae::Rocket::Rocket(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
	GameSizes size{};
	m_RocketSize = size.GetRocketSize();
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Rocket.png", m_RocketSize));

	m_TrasformComp = pOwner->GetComponent<dae::TransformComponent>();
}

void dae::Rocket::Update()
{
	glm::vec3 pos = m_TrasformComp->GetWorldPosition();
	if (pos.y < 0.0f - m_RocketSize.y)
	{
		GetOwner()->MarkForDead();
	}
	pos += glm::vec3{ 0, -1, 0 } * m_Speed * DeltaTime::GetInstance().GetDeltaTime();
	m_TrasformComp->SetPosition(pos.x, pos.y, pos.z);
}