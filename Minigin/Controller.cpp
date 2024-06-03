#include "Controller.h"
#include "Windows.h"
#include <Xinput.h>


dae::Controller::Controller()
{
	m_ControllerImpl = std::make_unique<ControllerImpl>();
}

dae::Controller::~Controller()
{
	
}

class dae::Controller::ControllerImpl
{
public:

	//~ControllerImpl() {};

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

	bool ProcessInput()
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

	void CreateCommand(std::unique_ptr<dae::Command> pCommand, const int key)
	{
		m_Commands.emplace_back(std::move(pCommand));
		m_Keys.emplace_back(key);
	}

private:
	XINPUT_STATE m_CurrentState{};
	int m_ControllerIndex{};
	unsigned int m_ButtonsPressedThisFrame{};
	unsigned int m_ButtonsReleasedThisFrame{};

	//Comand
	std::vector<std::unique_ptr<dae::Command>> m_Commands;
	std::vector<int> m_Keys;
};

bool dae::Controller::ProcessInput()
{
	return m_ControllerImpl->ProcessInput();
}

void dae::Controller::CreateCommand(std::unique_ptr<dae::Command> pCommand,const int key)
{
	m_ControllerImpl->CreateCommand( std::move(pCommand), key);
}

bool dae::Controller::IsDownThisFrame(unsigned int button) const
{
	return m_ControllerImpl->IsDownThisFrame(button);
}

bool dae::Controller::IsUpThisFrame(unsigned int button) const
{
	return m_ControllerImpl->IsUpThisFrame(button);
}

bool dae::Controller::IsPressed(unsigned int button) const
{
	return m_ControllerImpl->IsPressed(button);
}