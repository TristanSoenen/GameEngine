#pragma once
#include "Xinput.h"
#include "Singleton.h"
#include <memory>

namespace dae
{
	class Controller;

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		
		bool TestController()
		{
			/*bool result{ IsPressed(1) };
			return result;*/
		}
	private:
		/*bool IsDownThisFrame(unsigned int button) const
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
		unsigned int m_ButtonsReleasedThisFrame;*/
		//std::unique_ptr<Controller> m_Controller1;
	};

}
