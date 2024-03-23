#include "Keyboard.h"

bool dae::Keyboard::ProcessInput()
{
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

void dae::Keyboard::CreateCommand(std::unique_ptr<dae::Command> pCommand, const int key)
{
	m_Commands.emplace_back(std::move(pCommand));
	m_Keys.emplace_back(key);
}