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

	return true;
}

void dae::Controller::CreateCommand(std::unique_ptr<dae::Command> pCommand)
{
	m_Commands.emplace_back(std::move(pCommand));
}