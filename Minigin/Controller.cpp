#include "Controller.h"

bool dae::Controller::ProcessInput()
{
	XINPUT_STATE previusState{};

	CopyMemory(&previusState, &m_CurrentState, sizeof(XINPUT_STATE));
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(m_ControllerIndex, &m_CurrentState);

	auto buttonChanges = m_CurrentState.Gamepad.wButtons ^ previusState.Gamepad.wButtons;
	m_ButtonsPressedThisFrame = buttonChanges & m_CurrentState.Gamepad.wButtons;
	m_ButtonsReleasedThisFrame = buttonChanges & (~m_CurrentState.Gamepad.wButtons);

	if (!m_Commands.empty() && !m_Keys.empty())
	{
		for (int index{ 0 }; index < m_Keys.size(); index++)
		{
			if (IsPressed(m_Keys[index]))
			{
				m_Commands[index]->Execute();
			}
		}
	}

	/*if (IsPressed(1))
	{
		if (m_Commands.size() > 0)
		{
			m_Commands[0]->Execute();
		}
	}
	if (IsPressed(2))
	{
		if (m_Commands.size() > 0)
		{
			m_Commands[1]->Execute();
		}
	}
	if (IsPressed(4))
	{
		if (m_Commands.size() > 0)
		{
			m_Commands[3]->Execute();
		}
	}
	if (IsPressed(8))
	{
		if (m_Commands.size() > 0)
		{
			m_Commands[2]->Execute();
		}
	}*/

	/*if (!m_CommandAndKey.empty())
	{
		for (auto& [key, command] : m_CommandAndKey)
		{
			
			if (IsPressed(key))
			{
				command->Execute();
			}
		}
	}*/

	return true;
}

void dae::Controller::CreateCommand(std::unique_ptr<dae::Command> pCommand,const int key)
{
	m_Commands.emplace_back(std::move(pCommand));
	m_Keys.emplace_back(key);
	//m_CommandAndKey.emplace(std::make_unique<CommandAndKey>( pCommand, key));
}