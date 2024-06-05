#include "RocketLauncher.h"
#include "Rocket.h"
#include "SceneManager.h"
#include "GalagaPlayer.h"
#include "CollisionComponent.h"
#include "Scene.h"
#include "Observer.h"
#include "Structs.h"
#include "ServiceLocator.h"

dae::RocketLauncher::RocketLauncher(dae::GameObject* pOwner, bool onPlayer)
	:dae::Component(pOwner)
	,m_AttachedToPlayer(onPlayer)
{

}

void dae::RocketLauncher::FireRocket()
{
	if (m_RocketCount < m_MaxRocketFiredCount)
	{
		auto owner = GetOwner();
		auto rocket = std::make_shared<dae::GameObject>();
		if (m_AttachedToPlayer == true)
		{
			rocket->AddComponent(std::make_shared<dae::Rocket>(rocket.get(), m_AttachedToPlayer, this));
		}
		glm::vec3 pos = owner->GetWorldPosition();
		GameSizes sizes{};
		rocket->SetPosition(pos.x + (sizes.characterSizes.x / 2.0f) - (sizes.rocketSize.x / 2.0f), pos.y - sizes.rocketSize.y);
		auto& scene = SceneManager::GetInstance().GetCurrentScene();
		scene.Add(rocket);
		if (m_AttachedToPlayer == true)
		{
			auto& ss = ServiceLocator::get_Sound_System();
			ss.Play(0, 100.0f);
		}
		++m_RocketCount;
	}

}