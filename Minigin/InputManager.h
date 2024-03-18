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
		//void CreateCommand(GameObject* pObject,Command* pCommand, unsigned int key, bool controller);
		void CreateCommand(std::unique_ptr<Command> pCommand);
	private:
		//Comand
		std::vector<std::unique_ptr<dae::Command>> m_Commands;
		std::unique_ptr<Controller> m_Controller1 = std::make_unique<Controller>(); 
	};
}