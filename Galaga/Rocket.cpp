#include "Rocket.h"
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "RocketLauncher.h"
#include "CollisionComponent.h"
#include "CollisionManager.h"
#include "DeltaTime.h"
#include "Structs.h"

dae::Rocket::Rocket(dae::GameObject* pOwner, bool firedByPlayer, dae::RocketLauncher* launcher)
	:dae::Component(pOwner)
	,m_FiredByPlayer(firedByPlayer)
	,m_launcher(launcher)
{
	if (firedByPlayer)
	{
		m_Direction = glm::vec3{ 0, -1, 0 };
	}
	else
	{
		m_Direction = glm::vec3{ 0, 1, 0 };
	}
	GameSizes size{};
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/Rocket.png", size.rocketSize));

	m_TrasformComp = pOwner->GetComponent<dae::TransformComponent>();
	pOwner->AddComponent(std::make_shared<dae::CollisionComponent>(pOwner, dae::CollisionTypes::Projectile));
	pOwner->GetComponent <dae::CollisionComponent>()->AddCollisionObserver(this);
}

void dae::Rocket::Update()
{
	GameSizes size{};
	glm::vec3 pos = m_TrasformComp->GetWorldPosition();
	if (pos.y < 0.0f - size.rocketSize.y)
	{
		ReportRocketDead();
		auto owner = GetOwner();
		CollisionManager::GetInstance().Remove(owner->GetComponent<dae::CollisionComponent>().get(), dae::CollisionTypes::Projectile);
		owner->MarkForDead();
	}
	pos += m_Direction * m_Speed * DeltaTime::GetInstance().GetDeltaTime();
	m_TrasformComp->SetPosition(pos.x, pos.y, pos.z);
}

void dae::Rocket::ReportRocketDead()
{
	m_launcher->DecrementRocketCount();
}

void dae::Rocket::Notify(dae::Event event)
{
	switch (event.type)
	{
	case HIT:
		auto owner = GetOwner();
		ReportRocketDead();
		if (m_FiredByPlayer)
		{
			m_launcher->IncrementHitCount();
		}
		owner->GetComponent<CollisionComponent>()->RemoveFromCollisionVector();
		owner->MarkForDead();
		break;
	}
}