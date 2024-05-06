#pragma once
#include "Component.h"
#include "Subject.h"

namespace dae
{
	class GameObject;
	class Collision : public Component, Subject
	{
	public:
		Collision(GameObject* pOwner);
		~Collision() = default;

		void AddObserverComponent(Observer* observer);
		void Update() override;
		void CheckForCollisions();
		void MarkAsHit();
	private:
		bool m_Hit;
	};
}