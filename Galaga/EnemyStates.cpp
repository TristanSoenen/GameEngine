#include "EnemyStates.h"
#include "TransformComponent.h"
#include "EnemyComponent.h"
#include "HelperFunctions.h"


void dae::EnterGame::OnEnter()
{
	if (m_LeftSide == true)
	{
		m_Path = generateCirclePoints(100.0, 260.0, 80, 8, 0.0, false);
	}
	else
	{
		m_Path = generateCirclePoints(300.0, 260.0, 80, 8, 180.0, true);
	}

	m_Path.push_back(m_Path[0]);
	m_Path.push_back(m_SquadPos);
}

void dae::EnterGame::Update()
{
	if (index < int(m_Path.size()))
	{
		auto transformComp = m_pOwner->GetComponent<dae::TransformComponent>();
		glm::vec2 pos = transformComp->GetPosition();
		if (glm::length(m_Path[index] - pos) < 2.0f)
		{
			if (index == int(m_Path.size() -1))
			{
				auto comp = m_pOwner->GetComponent<dae::EnemyComponent>();
				comp->ChangeState(std::make_unique<InPosition>(m_pOwner));
			}
			else
			{
				index++;
			}
		}
		else
		{
			auto nextPos = Seek(pos, m_Path[index]);
			transformComp->SetPosition(nextPos.x, nextPos.y, 0.0f);
		}
	}
}

void dae::InPosition::OnEnter()
{
	auto comp = m_pOwner->GetComponent<dae::EnemyComponent>();
	comp->SetInPosition(true);
}

void dae::InPosition::Update()
{
	if (m_pOwner->GetComponent<dae::EnemyComponent>()->GetAttack() == true)
	{
		auto comp = m_pOwner->GetComponent<dae::EnemyComponent>();
		comp->ChangeState(std::make_unique<dae::Attack>(m_pOwner));
	}
}

void dae::InPosition::OnExit()
{
	auto comp = m_pOwner->GetComponent<dae::EnemyComponent>();
	comp->SetInPosition(false);
}

glm::vec2 targetPos{ 400, 400 };
void dae::Attack::Update()
{
	auto transformComp = m_pOwner->GetComponent<dae::TransformComponent>();
	glm::vec2 pos = transformComp->GetPosition();
	if (glm::length(targetPos - pos) < 2.0f)
	{
		auto comp = m_pOwner->GetComponent<dae::EnemyComponent>();
		auto endpos = comp->GetSquadPosition();
		comp->ChangeState(std::make_unique<dae::GoBack>(m_pOwner, endpos));
	}
	else
	{
		auto nextPos = Seek(pos, targetPos);
		transformComp->SetPosition(nextPos.x, nextPos.y, 0.0f);
	}
}

void dae::Attack::OnExit()
{
	auto comp = m_pOwner->GetComponent<dae::EnemyComponent>();
	comp->SetAttack(false);
}

void dae::GoBack::Update()
{
	auto transformComp = m_pOwner->GetComponent<dae::TransformComponent>();
	glm::vec2 pos = transformComp->GetPosition();
	if (glm::length(m_SquadPos - pos) < 2.0f)
	{
		auto comp = m_pOwner->GetComponent<dae::EnemyComponent>();
		comp->ChangeState(std::make_unique<dae::InPosition>(m_pOwner));
	}
	else
	{
		auto nextPos = Seek(pos, m_SquadPos);
		transformComp->SetPosition(nextPos.x, nextPos.y, 0.0f);
	}
}