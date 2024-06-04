#pragma once
#include <Component.h>
#include "Observer.h"

namespace dae
{
	class TransformComponent;
	class Rocket final: public Component
	{
	public:
		Rocket(GameObject* pOwner, bool firedByPlayer);
		~Rocket() = default;
		void Update() override;
	private:
		bool m_FiredByPlayer;
		glm::vec3 m_Direction;
		std::shared_ptr<TransformComponent> m_TrasformComp;
		const float m_Speed = 250.0f;
	};
}
