#pragma once
#include "Structs.h"

namespace dae
{
	class GameObject;
	class Observer
	{
	public:
		virtual ~Observer() = default;
		virtual  void  Notify(Event eventFunction, GameObject* actor) = 0;
	};
}