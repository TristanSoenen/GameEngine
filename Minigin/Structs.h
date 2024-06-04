#pragma once
#include <glm/glm.hpp>
#include <memory>
#include <any>


namespace dae
{
	enum eventType
	{
		PLAYER_DIED,
		HIT,
		ENEMY_DIED,
		ENEMY_HIT
	};

	enum ControllerButtons
	{
		DPAD_LEFT = 0x0004,
		DPAD_RIGHT = 0x0008,
		GAMEPAD_A = 0x1000,
		GAMEPAD_X = 0x4000
	};

	struct Event
	{
		eventType type;
	};

	enum CollisionTypes
	{
		Player,
		Enemy,
		Projectile
	};

	struct Rect
	{
		float x;
		float y;
		float width;
		float height;
	};

	struct GameSizes
	{
		glm::vec2 characterSizes = { 25, 25 };
		glm::vec2 playfieldSize = { 400, 480 };
		glm::vec2 rocketSize = { 5, 8 };
		glm::vec2 GetRocketSize() const { return rocketSize; }
	};
}
