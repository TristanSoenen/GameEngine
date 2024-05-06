#include "LivesUIComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::LivesUIComponent::LivesUIComponent(GameObject* pOwner)
	:Component(pOwner)
{
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	m_TextObject = std::make_shared<dae::TextObject>(m_LivesText, font);
	m_TextObject->Update();
}

void dae::LivesUIComponent::Render()
{
	m_TextObject->SetPosition(5.0f, 140.0f);
	m_TextObject->Render();
}


void dae::LivesUIComponent::PlayerDied()
{
	--m_AmountOfLives;
	m_LivesText = "# lives : " + std::to_string(m_AmountOfLives);
	m_TextObject->SetText(m_LivesText);
}
void dae::LivesUIComponent::Notify(Event eventFunction)
{
	switch (eventFunction.type)
	{
	case PLAYER_DIED:
		PlayerDied();
		break;
	}
}