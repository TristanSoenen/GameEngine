#pragma once
#include <memory>
#include "Component.h"
#include "Transform.h"
#include "vector"

namespace dae
{
	class Texture2D;
	//class Component;

	
	// todo: this should become final.
	class GameObject
	{
	public:
		
		virtual void Fixed_Update();
		virtual void Update();
		virtual void Render() const;

		void AddComponent(std::unique_ptr<Component> component);
		void RemoveComponent(std::unique_ptr<Component> component);
		//Component* GetComponent();
		
		bool HasComponentBeenAdded(std::unique_ptr<Component> component);


		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

	private:
		std::vector<std::unique_ptr<Component>> m_Components;
		Transform m_transform{};
		// todo: mmm, every gameobject has a texture? Is that correct?
		std::shared_ptr<Texture2D> m_texture{};
	};
}
