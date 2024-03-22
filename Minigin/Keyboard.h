#pragma once
#include <SDL.h>
#include "Command.h"
#include <vector>
#include <memory>

namespace dae
{

	class Keyboard
	{
	public:
		Keyboard() = default;
		~Keyboard() = default;

		bool ProcessInput();
		bool IsPressed(unsigned int key) { const Uint8* state = SDL_GetKeyboardState(NULL);  return state[key]; }

	private:

		//vector of keys and vector of commands use map instead?
		//std::vector<int, std::unique_ptr<Command>> m_KeysAndCommands;

	};
}


