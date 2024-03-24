#pragma once
#include <memory>
#include "Transform.h"
#include "Observer.h"
#include "glm/glm.hpp"
#include <vector>
#include <string>
#include "iostream"

namespace dae
{
	class Component;
	class Texture2D;
	class TransformComponent;
	// todo: this should become final.
	class GameObject
	{
	public:
		
		virtual void Fixed_Update();
		virtual void Update();
		virtual void Render() const;

		template <typename T> std::shared_ptr<T> AddComponent();
		template <typename T> std::shared_ptr<T> GetComponent();
		void RemoveComponent(std::shared_ptr<Component> component);
		bool HasComponentBeenAdded(std::shared_ptr<Component> component);
		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);
		glm::vec3 GetWorldPosition();

		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		//parents and children
		std::shared_ptr<GameObject> GetParent();
		void SetParent(std::shared_ptr<GameObject> parent, bool keepWorldPosition);
		size_t GetChildrenCount();
		GameObject* GetChildAt(int index);
		//bool IsChild(GameObject* parent);

		//observer functions
		void AddObserver(Observer* observer);
		void RemoveObserver(Observer* observer);

	protected:
		void NotifyObservers()
		{
			//empty
		}

	private:
		//observers
		std::vector<Observer*> m_Observers;

		//private Functions
		void AddChild(GameObject* child);
		void RemoveChild(GameObject* child);
		//components
		std::vector<std::shared_ptr<dae::Component>> m_Components;
		//parents & children
		std::shared_ptr<GameObject> m_Parent = nullptr;
		std::vector<GameObject*> m_Children;
		
		//these can be components
		std::shared_ptr<TransformComponent> m_TransformComponent;

		Transform m_transform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		//std::shared_ptr<Texture2D> m_texture{};
	};

	template<typename T>
	inline std::shared_ptr <T> dae::GameObject::AddComponent()
	{
		auto component = std::make_shared<T>(this);
		m_Components.emplace_back(component);
		return component;
	}

	template<typename T>
	inline std::shared_ptr <T> dae::GameObject::GetComponent()
	{
		for(auto& component : m_Components)
		{
			if (auto castedComponent = std::dynamic_pointer_cast<T>(component))
			{
				return castedComponent;
			}
		}
		return nullptr;
	}
}


