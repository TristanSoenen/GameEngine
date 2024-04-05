#include "HealthComponent.h"


dae::HealthComponent::HealthComponent(GameObject* pOwner)
	:Component(pOwner)
{
	
}

void dae::HealthComponent::PlayerDied()
{
	--m_Lives;
	//ADD healthcomponent player died function to it
	//NotifyObservers();
}