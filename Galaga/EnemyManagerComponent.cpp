#include "EnemyManagerComponent.h"
#include "EnemyComponent.h"

dae::EnemyManagerComponent::EnemyManagerComponent(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{

}

void dae::EnemyManagerComponent::Update()
{
	for (auto& enemy : m_Enemies)
	{
		if (enemy->GetAttack() == false)
		{
			enemy->SetAttack(true);
		}
	}
}