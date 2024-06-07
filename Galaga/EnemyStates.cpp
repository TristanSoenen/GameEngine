#include "EnemyStates.h"
#include "TransformComponent.h"
#include "BossGalaga.h"

void dae::EnterGame::Update()
{
	auto transformComp = m_pOwner->GetComponent<TransformComponent>();
	glm::vec2 pos = transformComp->GetPosition();
	if (pos.y > 200.0f)
	{
		auto comp = m_pOwner->GetComponent<BossGalaga>();
		comp->ChangeState(std::make_unique<InPosition>(m_pOwner));
	}
	pos.y += 10.0f * DeltaTime::GetInstance().GetDeltaTime();
	transformComp->SetPosition(pos.x, pos.y, 0.0f);
}