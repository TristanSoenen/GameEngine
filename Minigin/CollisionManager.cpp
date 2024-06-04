#include "CollisionManager.h"
#include "iostream"

void dae::CollisionManager::Update()
{
	CheckForCollisionBetweenProjectilesAndEnemies(m_Enemies, m_Projectiles);
	CheckForCollisionBetweenPlayers(m_Players, m_Enemies);
}

void dae::CollisionManager::CheckForCollisionBetweenPlayers(
	std::vector<dae::CollisionComponent*> vec1, std::vector<dae::CollisionComponent*> vec2)
{
	for (auto& collisionComp : vec1)
	{
		dae::Rect size1 = collisionComp->GetSize();
		for (auto& collisionComp2 : vec2)
		{
			dae::Rect size2 = collisionComp2->GetSize();
			if (CheckRectOverlap(size1, size2))
			{
				collisionComp->Hit();
				collisionComp2->Hit();
			}
		}
	}
}

void dae::CollisionManager::CheckForCollisionBetweenProjectilesAndEnemies(
	std::vector<dae::CollisionComponent*> enemyVec, std::vector<dae::CollisionComponent*> projectileVec)
{
	for (auto& projectile : m_Projectiles)
	{
		dae::Rect projectileSize = projectile->GetSize();
		for (auto& enemy : enemyVec)
		{
			dae::Rect enemySize = enemy->GetSize();
			if (CheckRectOverlap(projectileSize, enemySize) == true)
			{
				projectile->MarkForDead();
				enemy->Hit();
			}
		}
	}

}

bool dae::CollisionManager::CheckRectOverlap(Rect r1, Rect r2) const
{
	if (r1.x <= r2.x + r2.width && r2.x <= r1.x + r1.width &&
		r1.y <= r2.y + r2.height && r2.y <= r1.y + r1.height)
	{
		return true;
	}
	return false;
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