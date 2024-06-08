#pragma once
#include <Component.h>
#include "Subject.h"

namespace dae
{
	class EnemyComponent;
	class EnemyManagerComponent :public Component, Subject
	{
	public:
		EnemyManagerComponent(GameObject* pOwner);
		~EnemyManagerComponent() = default;
		void Update() override;
		void AllEnemiesInPosition(bool value);
		void AddEnemy(EnemyComponent* enemy);
		void RemoveEnemy(EnemyComponent* enemy);
		void AddObserverToEnemyManager(Observer* obs) { AddObserver(obs); };
		
	private:
		bool m_AttackFlag = false;
		bool m_NoEnemies = true;
		std::vector<EnemyComponent*> m_Enemies;
	};
}