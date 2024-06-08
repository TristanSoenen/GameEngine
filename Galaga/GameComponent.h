#pragma once
#include <Component.h>
#include <Observer.h>

namespace dae
{
	class GameComponent : public Component, Observer
	{
	public:
		GameComponent(GameObject* pOwner);
		~GameComponent() = default;
		void Notify(Event event);
		Observer* GetObserver() { return this; }
	private:
		void CreateLevel(std::string beeFile, std::string butterflyFile, std::string bossFile, int levelidx);
		void CreateShotSFiredLevel();
		int m_CurrentLevel = 0;
		int m_TotalShotsFired = 0;
		int m_Hits = 0;
	};
}
