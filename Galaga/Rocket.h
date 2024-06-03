#pragma once
#include <Component.h>

namespace dae
{
	class TransformComponent;
	class Rocket final: public Component
	{
	public:
		Rocket(GameObject* pOwner);
		~Rocket() = default;
		
		void Update() override;

	private:
		std::shared_ptr<TransformComponent> m_TrasformComp;
		const float m_Speed = 250.0f;
	};
}
