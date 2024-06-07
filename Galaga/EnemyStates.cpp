#include "EnemyStates.h"
#include "TransformComponent.h"
#include "EnemyComponent.h"
#include "DeltaTime.h"

//!!!!!!!!!!!!This function Comes from chat gpt!!!!!!!!!!!!!!!!!!!!!!!!!!!!
std::vector<glm::vec2> generateCirclePoints(double cx, double cy, double radius, int numPoints, double startAngleDeg)
{
	std::vector<glm::vec2> points;
	double angleIncrement = 360.0 / numPoints; // Angle between each point

	for (int i = 0; i < numPoints; ++i) {
		double angleDeg = startAngleDeg - i * angleIncrement; // Current angle in degrees
		double angleRad = angleDeg * 3.14159 / 180.0; // Convert angle to radians

		double x = cx + radius * cos(angleRad);
		double y = cy + radius * sin(angleRad);

		points.push_back({ x, y });
	}

	return points;
}

//seek helperfunction
glm::vec2 Seek(glm::vec2& currentPos, glm::vec2 targetPos)
{
	glm::vec2 dir = currentPos - targetPos;
	dir = glm::normalize(dir);

	glm::vec2 nextPos = currentPos;
	nextPos -= dir * 100.0f * dae::DeltaTime::GetInstance().GetDeltaTime();
	return nextPos;
}

void dae::EnterGame::OnEnter()
{
	//m_LeftSidePath.push_back();
	m_LeftSidePath = generateCirclePoints(125.0, 260.0, 80, 8, 0.0);
	m_LeftSidePath.push_back(m_LeftSidePath[0]);
	m_LeftSidePath.push_back(m_SquadPos);
}

void dae::EnterGame::Update()
{
	if (index < int(m_LeftSidePath.size()))
	{
		auto transformComp = m_pOwner->GetComponent<dae::TransformComponent>();
		glm::vec2 pos = transformComp->GetPosition();
		if (glm::length(m_LeftSidePath[index] - pos) < 2.0f)
		{
			if (index == int(m_LeftSidePath.size() -1))
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
			auto nextPos = Seek(pos, m_LeftSidePath[index]);
			transformComp->SetPosition(nextPos.x, nextPos.y, 0.0f);
		}
	}
}

void dae::InPosition::Update()
{
	if (m_pOwner->GetComponent<dae::EnemyComponent>()->GetAttack() == true)
	{
		auto comp = m_pOwner->GetComponent<dae::EnemyComponent>();
		comp->ChangeState(std::make_unique<dae::Attack>(m_pOwner));
	}
}

glm::vec2 targetPos{ 400, 400 };
void dae::Attack::Update()
{
	auto transformComp = m_pOwner->GetComponent<dae::TransformComponent>();
	glm::vec2 pos = transformComp->GetPosition();
	if (glm::vec2(targetPos - pos).length() < 5.0f)
	{
		auto nextPos = Seek(pos, targetPos);
		transformComp->SetPosition(nextPos.x, nextPos.y, 0.0f); 
	}
	else
	{

	}
}

void dae::GoBack::Update()
{

}