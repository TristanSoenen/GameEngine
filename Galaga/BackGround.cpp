#include "BackGround.h"
#include "RenderComponent.h"
#include "DeltaTime.h"
#include "Structs.h"

dae::BackGround::BackGround(dae::GameObject* pOwner, float speed)
	:dae::Component(pOwner)
	,m_Speed(speed)
{
	m_ResetPosition = false;
	GameSizes size{};
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Background.png", size.playfieldSize));
}

void dae::BackGround::Update()
{
	GameObject* owner = GetOwner();
	glm::vec3 pos = owner->GetWorldPosition();
	if(pos.y >= 480)
	{
		pos.y = -480;
	}
	pos += glm::vec3{ 0, 1, 0 } * m_Speed * DeltaTime::GetInstance().GetDeltaTime();
	owner->SetPosition(pos.x, pos.y);
	
}