#pragma once
#include <Component.h>
#include "Observer.h"

namespace dae
{
	class RocketLauncher;
	class TransformComponent;
	class Rocket final: public Component, Observer
	{
	public:
		Rocket(GameObject* pOwner, bool firedByPlayer, RocketLauncher* launcher);
		~Rocket() = default;
		void Update() override;
		void Notify(Event event) override;
		void ReportRocketDead();
	private:
		RocketLauncher* m_launcher;
		bool m_FiredByPlayer;
		glm::vec3 m_Direction;
		std::shared_ptr<TransformComponent> m_TrasformComp;
		const float m_Speed = 250.0f;
	};
}
