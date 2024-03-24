#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TransformComponent.h"

dae::RenderComponent::RenderComponent(GameObject* pOwner)
	:Component(pOwner)
{
	m_TransformComponent = pOwner->GetComponent<TransformComponent>();
}

void dae::RenderComponent::Render()
{
	auto& pos = m_TransformComponent->GetPosition();
	dae::Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
}

void dae::RenderComponent::SetTexture(const std::string& filepath)
{
	m_Texture = dae::ResourceManager::GetInstance().LoadTexture(filepath);
}