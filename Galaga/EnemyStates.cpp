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

	m_Path.emplace_back(m_Path[0]);
	m_Path.emplace_back(m_SquadPos);
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


void dae::Attack::OnEnter()
{
	auto transformComp = m_pOwner->GetComponent<dae::TransformComponent>();
	glm::vec2 pos = transformComp->GetPosition();
	const float startY = 150.0f;
	m_Path.emplace_back(glm::vec2(pos.x, startY));
	float firstleftX =  pos.x - rand() % int(pos.x);
	m_Path.emplace_back(glm::vec2(firstleftX, startY));
	float firstDive = float(rand() % 251);
	m_Path.emplace_back(glm::vec2(firstleftX, firstDive + startY));
	float spaceX = 376 - firstleftX;
	float randRight = float(rand() % int(spaceX));
	m_Path.emplace_back(glm::vec2(randRight, firstDive + startY));
	float secondDive = firstDive + (250 - firstDive) + startY;
	m_Path.emplace_back(glm::vec2(randRight, secondDive));
	float xleftRight = float(rand() %  50);
	m_Path.emplace_back(glm::vec2(randRight - xleftRight, secondDive));
}

void dae::Attack::Update()
{
	if (index < int(m_Path.size()))
	{
		auto transformComp = m_pOwner->GetComponent<dae::TransformComponent>();
		glm::vec2 pos = transformComp->GetPosition();
		if (glm::length(m_Path[index] - pos) < 2.0f)
		{
			if (index == int(m_Path.size() - 1))
			{
				auto comp = m_pOwner->GetComponent<dae::EnemyComponent>();
				comp->ChangeState(std::make_unique<dae::GoBack>(m_pOwner, comp->GetSquadPosition()));
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