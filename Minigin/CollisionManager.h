#pragma once
#include "Singleton.h"
#include "CollisionComponent.h"
#include <vector>
namespace dae
{
	class CollisionManager : public Singleton<CollisionManager>
	{
	public:
		void Update();
		void AddToCollisionVector(CollisionComponent* comp, CollisionTypes type);
	private:
		void CheckForCollisionBetweenPlayers(std::vector<CollisionComponent*> vec1, std::vector<CollisionComponent*> vec2);
		std::vector<CollisionComponent*> m_Enemies;
		std::vector<CollisionComponent*> m_Players;
		std::vector<CollisionComponent*> m_Projectiles;
	};
}