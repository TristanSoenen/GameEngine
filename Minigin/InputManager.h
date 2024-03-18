#pragma once
#include "windows.h"
#include "Controller.h"
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
		void CreateCommand(std::unique_ptr<Command> pCommand);
		void CreateCommandForController(std::unique_ptr<Command> pCommand, int ControllerIndex);
		void AddController(std::unique_ptr<Controller> pController);
	private:
		//Comand
		std::vector<std::unique_ptr<dae::Command>> m_Commands;
		std::vector<std::unique_ptr<Controller>> m_Controllers;
		std::unique_ptr<Controller> m_Controller1 = std::make_unique<Controller>(); 
	};
}