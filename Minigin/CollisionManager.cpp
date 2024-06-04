#include "CollisionManager.h"
#include "iostream"

void dae::CollisionManager::Update()
{
	CheckForCollisionBetweenPlayers(m_Players, m_Enemies);
}

void dae::CollisionManager::CheckForCollisionBetweenPlayers(std::vector<dae::CollisionComponent*> vec1
	, std::vector<dae::CollisionComponent*> vec2)
{
	for (auto& collisionComp : vec1)
	{
		dae::Rect size1 = collisionComp->GetSize();
		for (auto& collisionComp2 : vec2)
		{
			dae::Rect size2 = collisionComp2->GetSize();
			if (size1.x <= size2.x + size2.width && size2.x <= size1.x + size1.width &&
				size1.y <= size2.y + size2.height && size2.y <= size1.y + size1.height)
			{
				collisionComp->PlayerAndEnemyOverlap();
				collisionComp2->PlayerAndEnemyOverlap();
			}
		}
	}
}

void dae::CollisionManager::AddToCollisionVector(dae::CollisionComponent* comp, dae::CollisionTypes type)
{
	switch (type)
	{
	case dae::Player:
		m_Players.emplace_back(comp);
		break;
	case dae::Enemy:
		m_Enemies.emplace_back(comp);
		break;
	case dae::Projectile:
		m_Projectiles.emplace_back(comp);
		break;
	}
}