#include "EnemyManagerComponent.h"
#include "EnemyComponent.h"
#include <cstdlib> 
#include <ctime> 


dae::EnemyManagerComponent::EnemyManagerComponent(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{
	srand((unsigned)time(0));
}

void dae::EnemyManagerComponent::Update()
{
	for (auto& enemy : m_Enemies)
	{
		if (enemy->GetInPositions() == false)
		{
			m_AttackFlag = false;
			break;
		}
		else
		{
			m_AttackFlag = true;
		}
	}

	AllEnemiesInPosition(m_AttackFlag);

	for (auto& enemy : m_Enemies)
	{
		if (enemy->IsALive() == false)
		{
			RemoveEnemy(enemy);
		}
	}
}


void dae::EnemyManagerComponent::AllEnemiesInPosition(bool value)
{
	if (value == true)
	{
		if (m_Enemies.size() > 1)
		{
			int randIndex = rand() % m_Enemies.size();
			m_Enemies[randIndex]->SetAttack(true);
			int randIndex2 = rand() % m_Enemies.size();
			while (randIndex == randIndex2)
			{
				randIndex2 = rand() % m_Enemies.size();
			}
			m_Enemies[randIndex2]->SetAttack(true);
		}
		else
		{
			m_Enemies[0]->SetAttack(true);
		}
	}
}

void dae::EnemyManagerComponent::RemoveEnemy(dae::EnemyComponent* enemy)
{
	m_Enemies.erase(std::remove(m_Enemies.begin(), m_Enemies.end(), enemy), m_Enemies.end());
}

void dae::EnemyManagerComponent::AddEnemy(dae::EnemyComponent* enemy)
{
	m_Enemies.emplace_back(enemy);
}