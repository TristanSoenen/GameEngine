#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "Component.h"
#include "TransformComponent.h"
#include "algorithm"

dae::GameObject::GameObject()
{
	m_TransformComponent = AddComponent<dae::TransformComponent>();
}

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
	//m_transform.SetPosition(x, y, 0.0f);
	m_TransformComponent->SetPosition(x, y, 0.0f);
}

//glm::vec3 dae::GameObject::GetWorldPosition() const
//{
//	return m_TransformComponent->GetWorldPosition();
//}

void dae::GameObject::RemoveComponent(std::shared_ptr<dae::Component> component)
{
	m_Components.erase(std::remove(m_Components.begin(), m_Components.end(), component), m_Components.end());
}

bool dae::GameObject::HasComponentBeenAdded(std::shared_ptr<dae::Component> component)
{
	if (std::find(m_Components.begin(), m_Components.end(), component) != m_Components.end())
	{
		return true;
	}
	return false;
}

//dae::GameObject* dae::GameObject::GetParent()
//{
//	return m_Parent;
//}

void dae::GameObject::SetParent(std::shared_ptr<dae::GameObject> parent, bool keepWorldPosition)
{
	glm::vec3 oldPos = m_TransformComponent->GetWorldPosition();
	// 1. Check if the new parent is valid(not itself or one of its children)
	if (parent == m_Parent)
	{
		return;
	}
	if (parent == nullptr)
	{
		glm::vec3 newPos = m_TransformComponent->GetWorldPosition();
		m_TransformComponent->SetPosition(newPos.x, newPos.y, newPos.z);
	}
	else
	{
		if (keepWorldPosition == true)
		{
			//m_TransformComponent->SetPosition(m_TransformComponent->GetWorldPosition() - parent->GetWorldPosition());
			//m_TransformComponent->SetDirtyFlag();
		}
	}


	// 2. Remove itself from the previus parent(RemoveChild?).
	if (m_Parent)
	{
		m_Parent->RemoveChild(this);
	}
	// 3. Set the given parent on itself.
	m_Parent = parent;
	// 4. add itself as a child to the given parent(AddChild?).
	if (m_Parent)
	{
		m_Parent->AddChild(this);
	}
	// 5. UpdatePosition, roation and scale.

}

//size_t dae::GameObject::GetChildrenCount()
//{
//	return m_Children.size();
//}
//
//std::shared_ptr<dae::GameObject> dae::GameObject::GetChildAt(int index)
//{
//	return m_Children[index];
//}

void dae::GameObject::AddChild(dae::GameObject* child)
{
	// 1. Check if the new child is valid(Not null and not one of its parents)
	if (child != nullptr )
	{
		// 2. Remove the given child from the childs pervious parent(remove child?)
		//RemoveChild(child);
		//// 3. set itself as parent of the child(set parent?)
		//child->SetParent(m_Parent, false);
		// 4. add the child to its children list.
		m_Children.emplace_back(child);
		// 5. update position, rotation and scale.
	}
}

void dae::GameObject::RemoveChild(dae::GameObject* child)
{
	// 1. Check if the child is valid(not null and one of its children)
	if (child == nullptr)
	{
		return;
	}
	// 2. remove the given child from the children list
	m_Children.erase(std::remove(m_Children.begin(), m_Children.end(), child));
	// 3. remove itself as a parent of the child(SetParent?)
	
	// 4. update position, roation and scale
	
}

//bool dae::GameObject::IsChild(dae::GameObject> parent)
//{
//	for (auto& child : m_Children)
//	{
//		if (child == parent)
//		{
//			return false;
//		}
//	}
//	return true;
//}