#pragma once
#include <memory>
#include "Transform.h"
#include <vector>
#include <string>

namespace dae
{
	class Component;
	class Texture2D;
	// todo: this should become final.
	class GameObject
	{
	public:
		
		virtual void Fixed_Update();
		virtual void Update();
		virtual void Render() const;

		void AddComponent(std::shared_ptr<Component> component);
		void RemoveComponent(std::shared_ptr<Component> component);
		//Component* GetComponent();
		//template <typename T> Component* GetComponent(T)
		//{
		//	
		//	//std::find(T)
		//	return T;
		//}
		bool HasComponentBeenAdded(std::shared_ptr<Component> component);
		//void SetParent(GameObject* parent, bool keepWorldPosition);
		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		std::vector<std::shared_ptr<dae::Component>> m_Components;
		
		//these can be components
		Transform m_transform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		std::shared_ptr<Texture2D> m_texture{};
	};
}
