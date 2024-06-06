#include "ScoreComponent.h"
#include "TextComponent.h"
#include "Font.h"

dae::ScoreComponent::ScoreComponent(dae::GameObject* pOwner, std::shared_ptr<Font> font)
	:dae::Component(pOwner)
	,m_font(font)
{
	pOwner->AddComponent(std::make_shared<dae::TextComponent>(pOwner, m_text + std::to_string(m_Score), font));
	m_TextComp = pOwner->GetComponent<dae::TextComponent>();
}

void dae::ScoreComponent::Notify(dae::Event event)
{
	switch (event.type)
	{
	case BEE_DIED:
		m_Score += 50;
		m_TextComp->SetText( m_text + std::to_string(m_Score));
		break;
	case BUTTERFLY_DIED:
		m_Score += 80;
		m_TextComp->SetText( m_text + std::to_string(m_Score));
		break;
	case BOSSGALAGA_DIED:
		m_Score += 150;
		m_TextComp->SetText( m_text +std::to_string(m_Score));
		break;
	}
}