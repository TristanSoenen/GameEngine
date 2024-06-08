#pragma once
#include <Component.h>

namespace dae
{
	class EnemyComponent;
	class EnemyManagerComponent :public Component
	{
	public:
		EnemyManagerComponent(GameObject* pOwner);
		~EnemyManagerComponent() = default;
		void Update() override;
		void AllEnemiesInPosition(bool value);
		void AddEnemy(EnemyComponent* enemy);
		void RemoveEnemy(EnemyComponent* enemy);
	private:
		bool m_AttackFlag = false;
		std::vector<EnemyComponent*> m_Enemies;
	};
}