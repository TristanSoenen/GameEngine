#include "Collision.h"


dae::Collision::Collision(dae::GameObject* pOwner) 
	:dae::Component(pOwner)
	,dae::Subject()
	,m_Hit{ false }
{
	
}

void dae::Collision::AddObserverComponent(dae::Observer* observer)
{
	AddObserver(observer);
}

void dae::Collision::CheckForCollisions()
{
	if (m_Hit == true)
	{
		dae::Event eve{};
		eve.type = dae::PLAYER_DIED;
		NotifyObservers(eve);
		m_Hit = false;
	}
}

void dae::Collision::Update()
{
	CheckForCollisions();
}

void dae::Collision::MarkAsHit()
{
	m_Hit = true;
}