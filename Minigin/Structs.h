#pragma once
#include "Command.h"
#include <memory>
#include <any>


namespace dae
{
	struct Event
	{
		std::any Eventfunction;
	};

	struct Rect
	{
		int x;
		int y;
		int width;
		int height;
	};
}
