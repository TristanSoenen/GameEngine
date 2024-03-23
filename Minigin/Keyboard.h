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
		void CreateCommand(std::unique_ptr<dae::Command> pCommand, const int key);

	private:

		std::vector<std::unique_ptr<dae::Command>> m_Commands;
		std::vector<int> m_Keys;
	};
}


