#include "GalagaPlayer.h"
#include "RenderComponent.h"
#include "RocketLauncher.h"
#include "CollisionComponent.h"
#include "TransformComponent.h"
#include "Structs.h"

dae::GalagaPlayer::GalagaPlayer(GameObject* pOwner)
	:dae::Component(pOwner)
{
	GameSizes size{};
	//add the render component
	pOwner->AddComponent(std::make_shared<dae::RenderComponent>(pOwner, "../Data/StarShip.png", size.characterSizes));

	//add rocket Launcher
	pOwner->AddComponent(std::make_shared<dae::RocketLauncher>(pOwner, true));

	//add CollisionComponent
	pOwner->AddComponent(std::make_shared<dae::CollisionComponent>(pOwner, dae::CollisionTypes::Player));
	pOwner->GetComponent<dae::CollisionComponent>()->AddCollisionObserver(this);

	m_TranformComp = pOwner->GetComponent<dae::TransformComponent>();
}

void dae::GalagaPlayer::Notify(dae::Event event)
{
	switch (event.type)
	{
	case HIT:
		m_FreezePosition = true;
		GetOwner()->MarkForDead();
		break;
	}
}

void dae::GalagaPlayer::Update()
{
	if (m_FreezePosition == true)
	{
		auto currentPos = m_TranformComp->GetWorldPosition();
		m_TranformComp->SetPosition(currentPos.x, currentPos.y, 0.0f);
	}
}