#include "GameComponent.h"

dae::GameComponent::GameComponent(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{

}

void dae::GameComponent::Notify(Event event)
{
	switch (event.type)
	{
	case GAME_OVER:
	
		break;
	case HIT:
		++m_Hits;
		break;
	case FIRED:
		++m_TotalShotsFired;
		break;
	}
}

