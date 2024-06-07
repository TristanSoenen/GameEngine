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
		EnemyTypes m_Type;

	public:

		EnterGame(GameObject* pOwner, EnemyTypes type)
			:m_pOwner(pOwner)
			,m_Type(type)
		{

		};

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

		void OnEnter() override
		{
			std::cout << "changedState\n";
		}

		void Update() override
		{

		}

	private:

	};

}