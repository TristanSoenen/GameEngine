#pragma once
#include "Structs.h"

namespace dae
{
	class Subject;
	class Observer
	{
	public:
		Observer() {};
		virtual ~Observer() = default;
		virtual void Notify(Subject* subject, Event) = 0;
	};
}