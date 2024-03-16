#include <SDL.h>
#include "Windows.h"
#include "InputManager.h"
#include <backends/imgui_impl_sdl2.h>
#include <Xinput.h>

bool dae::InputManager::ProcessInput()
{
	XINPUT_STATE currentState{};
	XINPUT_STATE previusState{};
	
	CopyMemory(&previusState, &currentState, sizeof(XINPUT_STATE));
	ZeroMemory(&currentState, sizeof(XINPUT_STATE));
	XInputGetState(m_ControllerIndex, &currentState);

	//auto buttonChanges = currentState.Gamepad.wButtons ^ previusState.Gamepad.wButtons;
	//buttonsPressedThisFrame = buttonChanges & currentState.Gamepad.wButtons;
	//buttonsReleasedThisFrame = buttonChanges & (~currentState.Gamepad.wButtons);

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		//process event for IMGUI
		ImGui_ImplSDL2_ProcessEvent(&e);
		if (e.type == SDL_KEYDOWN) {
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
		// etc...
	}

	return true;
}
