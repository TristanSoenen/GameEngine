#include "LivesComponent.h"
#include "TextComponent.h"
#include "Font.h"

dae::LivesComponent::LivesComponent(dae::GameObject* pOwner, int lives, std::shared_ptr<Font> font)
	:dae::Component(pOwner)
	,m_lives(lives)
	,m_font(font)
{
	pOwner->AddComponent(std::make_shared<dae::TextComponent>(pOwner, m_text + std::to_string(m_lives), font));
	m_TextComp = pOwner->GetComponent<dae::TextComponent>();
}

void dae::LivesComponent::Notify(dae::Event event)
{
	switch (event.type)
	{
	case PLAYER_DIED:
		--m_lives;
		m_TextComp->SetText(m_text + std::to_string(m_lives));
		break;
	}
}