#pragma once
#include <Component.h>
#include <Observer.h>
#include <subject.h>

namespace dae
{
	class Butterfly final: public Component, Observer, Subject
	{
	public:
		Butterfly(GameObject* pOwner);
		~Butterfly() = default;
		void Notify(Event event) override;
		void AddObserverToButterfly(dae::Observer* obs)
		{
			AddObserver(obs);
		}
	};
}