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
		glm::vec2 m_MiddlePointCircle;
		std::shared_ptr<TransformComponent> m_TransformComp;
		float m_Speed;
		float m_Radius;
		float m_ElapsedTime{ 0.0f };
	};
}