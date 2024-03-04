#pragma once
#include "Component.h"
namespace dae
{
	class GameObject;
	class TransformComponent;

	class RotationComponent :public Component
	{
	public:
		RotationComponent(GameObject* pOwner);
		~RotationComponent() = default;

		void Update() override;
	private:
		glm::vec2 m_Position;
		std::shared_ptr<TransformComponent> m_TransformComp;
	};
}