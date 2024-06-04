#pragma once
#include <Component.h>
#include "Observer.h"
namespace dae
{
	class Bee final: public Component, Observer
	{
	public:
		Bee(GameObject* pOwner);
		~Bee() = default;
		void Notify(Event event) override;
	};
}