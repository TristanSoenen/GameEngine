#pragma once
//#include "GameObject.h"

namespace dae
{
	class GameObject;

	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual void Notify(GameObject* actor) = 0;
	};
}