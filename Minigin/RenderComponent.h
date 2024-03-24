#pragma once
#include "Component.h"


namespace dae
{
	class Texture2D;
	class TransformComponent;

	class RenderComponent : public Component
	{
	public:
		RenderComponent(GameObject* pOwner);
		~RenderComponent() = default;
		void Render() override;
		void SetTexture(const std::string& filepath);

	private:
		std::shared_ptr<Texture2D> m_Texture;
		std::shared_ptr<TransformComponent> m_TransformComponent;
	};
}