#pragma once
#include <Component.h>
#include "Observer.h"
#include <subject.h>

namespace dae
{
	class Bee final: public Component, Observer, Subject
	{
	public:
		Bee(GameObject* pOwner);
		~Bee() = default;
		void Notify(Event event) override;
		void AddObserverToBee(dae::Observer* obs)
		{
			AddObserver(obs);
		}
	};
}