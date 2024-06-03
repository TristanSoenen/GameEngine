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

	struct GameSizes
	{
		glm::vec2 characterSizes = { 25, 25 };
		glm::vec2 playfieldSize = { 400, 400 };
		glm::vec2 rocketSize = { 5, 8 };
		glm::vec2 GetRocketSize() const { return rocketSize; }
	};
}
