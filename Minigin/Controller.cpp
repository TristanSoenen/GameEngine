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
		for (int index{ 0 }; index < int(m_Keys.size()); index++)
		{
			if (IsPressed(m_Keys[index]))
			{
				m_Commands[index]->Execute();
			}
		}
	}

	return true;
}

void dae::Controller::CreateCommand(std::unique_ptr<dae::Command> pCommand,const int key)
{
	m_Commands.emplace_back(std::move(pCommand));
	m_Keys.emplace_back(key);
}