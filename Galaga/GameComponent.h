#pragma once
#include <Component.h>
#include <Observer.h>

namespace dae
{
	class GameComponent final : public Component, Observer
	{
	public:
		GameComponent(GameObject* pOwner);
		~GameComponent() = default;
		void Update() override;
		void Notify(Event event);
		Observer* GetObserver() { return this; }

		void SwitchToHighScores()
		{
			if (m_ShowResults == true)
			{
				m_GoToHighScoreLevel = true;
			}
		}
		void SkipLevel();
	private:
		void CreateLevel(std::string beeFile, std::string butterflyFile, std::string bossFile, int levelidx);
		void CreateShotSFiredLevel();
		void CreateScoreBoard();
		int m_CurrentLevel = 0;
		int m_TotalShotsFired = 0;
		int m_Hits = 0;
		bool m_GoToHighScoreLevel = false;
		bool m_ShowResults = false;
	};
}
