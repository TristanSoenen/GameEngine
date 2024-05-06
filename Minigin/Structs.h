#pragma once
#include "Command.h"
#include <memory>
#include <any>


namespace dae
{
	enum eventType
	{
		PLAYER_DIED,
		FIRE,
		ENEMY_DIED,
		ENEMY_HIT
	};

	struct Event
	{
		eventType type;
	};

	struct Rect
	{
		int x;
		int y;
		int width;
		int height;
	};
}
