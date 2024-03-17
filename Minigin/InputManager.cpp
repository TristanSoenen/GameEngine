#include <SDL.h>
#include "control.h"
#include "InputManager.h"
#include "Controller.h"
#include <backends/imgui_impl_sdl2.h>
#include "Command.h"

bool dae::InputManager::ProcessInput()
{

	m_Controller1->ProcessInput();
	
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

//void dae::InputManager::CreateCommand(GameObject* pObject, Command* pCommand, unsigned int key, bool controller)
//{
//	if (controller)
//	{
//		m_Controller1->CreateCommand(pObject, pCommand);
//	}
//
//	int key = key;
//}