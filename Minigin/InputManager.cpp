#include <SDL.h>
#include "control.h"
#include "InputManager.h"
#include "Controller.h"
#include <backends/imgui_impl_sdl2.h>
#include "Command.h"

bool dae::InputManager::ProcessInput()
{
	if (m_Controllers.size() > 0)
	{
		for (int index = 0; index < int(m_Controllers.size()); index++)
		{
			m_Controllers[index]->ProcessInput();
		}
	}
	
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		//process event for IMGUI
		ImGui_ImplSDL2_ProcessEvent(&e);
		if (e.type == SDL_KEYDOWN) 
		{
	
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
	
		// etc...
	}

	if (IsPressed(SDL_SCANCODE_W))
	{
		if (m_Commands.size() > 0)
		{
			m_Commands[0]->Execute();
		}
	}
	if (IsPressed(SDL_SCANCODE_S))
	{
		if (m_Commands.size() > 0)
		{
			m_Commands[1]->Execute();
		}
	}
	if (IsPressed(SDL_SCANCODE_D))
	{
		if (m_Commands.size() > 0)
		{
			m_Commands[2]->Execute();
		}
	}
	if (IsPressed(SDL_SCANCODE_A))
	{
		if (m_Commands.size() > 0)
		{
			m_Commands[3]->Execute();
		}
	}


	return true;
}

void dae::InputManager::CreateCommand(std::unique_ptr<dae::Command> pCommand)
{
	m_Commands.emplace_back(std::move(pCommand));
}

void dae::InputManager::CreateCommandForController(std::unique_ptr<Command> pCommand, int ControllerIndex)
{
	if (m_Controllers.size() > 0)
	{
		m_Controllers[ControllerIndex]->CreateCommand(std::move(pCommand));
	}
}

void dae::InputManager::AddController(std::unique_ptr<Controller> pController)
{
	m_Controllers.emplace_back(std::move(pController));
}