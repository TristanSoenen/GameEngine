#ifndef HEALTHCOMPONENT_H // Check if HEALTHCOMPONENT_H is not defined
#define HEALTHCOMPONENT_H // If not, define HEALTHCOMPONENT_H


#pragma once
#include "Subject.h"
#include "Component.h"


namespace dae
{
	class GameObject;

	class HealthComponent final :  public Component, public Subject
	{
	public:
		HealthComponent(GameObject* pOwner);
		~HealthComponent() = default;
		void PlayerDied();
	private:
		int m_Lives = 3; 
	};
}

#endif // End of include guard