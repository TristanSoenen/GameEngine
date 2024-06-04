#pragma once
#include <Component.h>
#include <Observer.h>

namespace dae
{
	class Butterfly final: public Component, Observer
	{
	public:
		Butterfly(GameObject* pOwner);
		~Butterfly() = default;
		void Notify(Event event) override;
	};
}