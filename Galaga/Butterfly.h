#pragma once
#include <Component.h>
namespace dae
{
	class Butterfly final: public Component
	{
	public:
		Butterfly(GameObject* pOwner);
		~Butterfly() = default;
	};
}


