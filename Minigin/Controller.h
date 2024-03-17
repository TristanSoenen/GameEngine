#pragma once
#include <Xinput.h>

namespace dae
{
	struct ControllerInput
	{

	};

	class Controller
	{
	public:
		Controller() = default;
		~Controller() = default;

		bool ProcessInput();
	private:
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

		XINPUT_STATE m_CurrentState;
		int m_ControllerIndex{};
		unsigned int m_ButtonsPressedThisFrame;
		unsigned int m_ButtonsReleasedThisFrame;
	};
}