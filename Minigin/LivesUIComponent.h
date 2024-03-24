#pragma once
#include "GameObject.h"
#include "Component.h"
#include "Observer.h"
#include "Structs.h"
#include <iostream>

namespace dae
{
	class LivesUIComponent :public Component, public Observer
	{
		LivesUIComponent(GameObject* pOwner)
			:Component(pOwner) ,Observer()
		{

		}
	};
}


