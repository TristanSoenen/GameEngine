#pragma once
#include "Windows.h"
#include <Xinput.h>
#include "Command.h"
#include <memory>
#include <vector>

namespace dae
{
	class Controller
	{
	public:
		Controller() {};
		~Controller() {};

		bool IsDownThisFrame(unsigned int button) const
		{
			return m_ButtonsPressedThisFrame & button;
		}
		bool IsUpThisFrame(unsigned int button) const
		{
			return m_ButtonsReleasedThisFrame & button;
		}
		bool IsPressed(unsigned int button) const
		{
			return m_CurrentState.Gamepad.wButtons & button;
		}

		bool ProcessInput();
		template <typename T> void CreateCommand(GameObject* pObject, T);
		//template <typename T> std::shared_ptr<T> AddCommand();
		//void CreateCommand(GameObject* pObject, Command* pCommand);
	private:
		XINPUT_STATE m_CurrentState{};
		int m_ControllerIndex{};
		unsigned int m_ButtonsPressedThisFrame{};
		unsigned int m_ButtonsReleasedThisFrame{};

		//Comand
		//std::unique_ptr<dae::Move> m_MoveCommand = std::make_unique<dae::Move>();
		std::vector<dae::Command> m_Comands;
	};
}

template <typename T>
void dae::Controller::CreateCommand(dae::GameObject* pObject, T type)
{
	auto command = std::make_unique<type>(pObject);
	m_Comands.emplace_back(command);
}