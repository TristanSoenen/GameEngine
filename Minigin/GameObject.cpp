#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"
#include "algorithm"


dae::GameObject::~GameObject() = default;

void dae::GameObject::Fixed_Update()
{
	for (auto& component : m_Components)
	{
		component->Fixed_Update();
	}
}

void dae::GameObject::Update()
{
	for (auto& component : m_Components)
	{
		component->Update();
	}
}

void dae::GameObject::Render() const
{
	const auto& pos = m_transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_texture, pos.x, pos.y);

	for (auto& component : m_Components)
	{
		component->Render();
	}
}

void dae::GameObject::SetTexture(const std::string& filename)
{
	m_texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::AddComponent(std::unique_ptr<Component> component)
{
	m_Components.emplace_back(std::move(component));
}

void dae::GameObject::RemoveComponent(std::unique_ptr<Component> component)
{
	m_Components.erase(std::remove(m_Components.begin(), m_Components.end(), component));
}

//dae::Component* dae::GameObject::GetComponent()
//{
//	//return 
//}

bool dae::GameObject::HasComponentBeenAdded(std::unique_ptr<Component> component)
{
	if (std::find(m_Components.begin(), m_Components.end(), component) != m_Components.end())
	{
		return true;
	}
	return false;
}