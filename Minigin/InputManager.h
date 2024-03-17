#pragma once
#include "windows.h"
#include "Controller.h"
#include "Command.h"
#include "Xinput.h"
#include "Singleton.h"
#include <memory>

namespace dae
{
	//class Controller;
	class GameObject;

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		//void CreateCommand(GameObject* pObject,Command* pCommand, unsigned int key, bool controller);
	private:
		std::unique_ptr<Controller> m_Controller1 = std::make_unique<Controller>(); 
	};
}