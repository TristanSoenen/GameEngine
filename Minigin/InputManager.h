#pragma once
#include "windows.h"
#include "Controller.h"
#include "Keyboard.h"
#include "Command.h"
#include "Xinput.h"
#include "Singleton.h"
#include <memory>
#include <vector>

namespace dae
{
	//class Controller;
	class GameObject;

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		bool IsPressed(unsigned int key) { const Uint8* state = SDL_GetKeyboardState(NULL);  return state[key]; }
		void CreateCommandKeyBoard(std::unique_ptr<Command> pCommand, int key);
		void CreateCommandForController(std::unique_ptr<Command> pCommand, int ControllerIndex, const int key);
		void AddController(std::unique_ptr<Controller> pController);
	private:
		//Comand
		std::vector<std::unique_ptr<dae::Command>> m_Commands;
		std::vector<std::unique_ptr<Controller>> m_Controllers;

		std::unique_ptr<Controller> m_Controller1 = std::make_unique<Controller>(); 
		std::unique_ptr<Keyboard> m_Keyboard = std::make_unique<Keyboard>();
	};
}