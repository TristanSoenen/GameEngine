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
	private:
		std::vector<std::shared_ptr<EnemyComponent>> m_Enemies;
	};
}