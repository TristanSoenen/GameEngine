#pragma once
#include "Windows.h"
#include <Xinput.h>
#include "Command.h"
#include "Structs.h"
#include <memory>
#include <vector>
#include <unordered_map>

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
		void CreateCommand(std::unique_ptr<dae::Command> pCommand, const int key);
	private:
		XINPUT_STATE m_CurrentState{};
		int m_ControllerIndex{};
		unsigned int m_ButtonsPressedThisFrame{};
		unsigned int m_ButtonsReleasedThisFrame{};

		//Comand
		std::vector<std::unique_ptr<dae::Command>> m_Commands;
		std::vector<int> m_Keys;
		//std::unordered_map<int, std::unique_ptr<dae::Command>> m_CommandAndKey;
	};
}