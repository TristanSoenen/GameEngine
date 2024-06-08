#pragma once
#include "Structs.h"
#include "GameObject.h"
#include "DeltaTime.h"

namespace dae
{
	class EnterGame;
	class InPosition;
	class EnemyState
	{
	public:
		EnemyState() = default;
		virtual ~EnemyState() = default;
		EnemyState(const EnemyState& other) = delete;
		EnemyState(EnemyState&& other) = delete;
		EnemyState& operator=(const EnemyState& other) = delete;
		EnemyState& operator=(EnemyState&& other) = delete;

		virtual void OnEnter() {};
		virtual void OnExit() {};
		virtual void Update() {};
	};

	class EnterGame final: public EnemyState
	{
	private:
		GameObject* m_pOwner;
		glm::vec2 m_SquadPos;
		std::vector<glm::vec2> m_LeftSidePath;
		int index = 0;
		
	public:

		EnterGame(GameObject* pOwner, glm::vec2 endPos)
			:m_pOwner(pOwner)
			,m_SquadPos(endPos)
		{

		};

		void OnEnter() override;

		void Update() override;

	};

	class InPosition : public EnemyState
	{
	private: 
		GameObject* m_pOwner;

	public:
		InPosition(GameObject* pOwner)
			:m_pOwner(pOwner)
		{

		}

		void OnEnter() override;
		void Update() override;
		void OnExit() override;
	};

	class Attack : public EnemyState
	{
	private:
		GameObject* m_pOwner;

	public:
		Attack(GameObject* pOwner)
			:m_pOwner(pOwner)
		{

		}

		void Update() override;

		void OnExit() override;
	};

	class GoBack : public EnemyState
	{
	private:
		GameObject* m_pOwner;
		glm::vec2 m_SquadPos;

	public:
		GoBack(GameObject* pOwner, glm::vec2 endPos)
			:m_pOwner(pOwner)
			,m_SquadPos(endPos)
		{

		}

		void Update() override;
	};
	

}