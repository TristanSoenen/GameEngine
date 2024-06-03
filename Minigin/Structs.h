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

	enum ControllerButtons
	{
		DPAD_LEFT = 0x0004,
		DPAD_RIGHT = 0x0008,
		GAMEPAD_A = 0x8000,
		GAMEPAD_X = 0x4000
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
		glm::vec2 playfieldSize = { 400, 480 };
		glm::vec2 rocketSize = { 5, 8 };
		glm::vec2 GetRocketSize() const { return rocketSize; }
	};
}
