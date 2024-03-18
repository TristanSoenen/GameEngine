#include <SDL.h>
#include "control.h"
#include "InputManager.h"
#include "Controller.h"
#include <backends/imgui_impl_sdl2.h>
#include "Command.h"

bool dae::InputManager::ProcessInput()
{

	//m_Controller1->ProcessInput();
	
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		//process event for IMGUI
		ImGui_ImplSDL2_ProcessEvent(&e);
		if (e.type == SDL_KEYDOWN) 
		{
			if (e.key.keysym.scancode == SDL_SCANCODE_W)
			{
				if (m_Commands.size() > 0)
				{
					m_Commands[0]->Execute();
				}
			}
			if (e.key.keysym.scancode == SDL_SCANCODE_S)
			{
				if (m_Commands.size() > 0)
				{
					m_Commands[1]->Execute();
				}
			}
			if (e.key.keysym.scancode == SDL_SCANCODE_A)
			{
				if (m_Commands.size() > 0)
				{
					m_Commands[3]->Execute();
				}
			}
			if (e.key.keysym.scancode == SDL_SCANCODE_D)
			{
				if (m_Commands.size() > 0)
				{
					m_Commands[2]->Execute();
				}
			}
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
	
		// etc...
	}




	return true;
}

//void dae::InputManager::AddController()
//{
// 
//}

void dae::InputManager::CreateCommand(std::unique_ptr<dae::Command> pCommand)
{
	m_Commands.emplace_back(std::move(pCommand));
}