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
		m_Score += 100;
		break;
	case BEE_INPOS_DIED:
		m_Score += 50;
		break;
	case BUTTERFLY_DIED:
		m_Score += 160;
		break;
	case BUTTERFLY_INPOS_DIED:
		m_Score += 80;
		break;
	case BOSSGALAGA_DIED:
		m_Score += 400;
		break;
	case BOSSGALAGA_INPOS_DIED:
		m_Score += 150;
		break;
	}
	m_TextComp->SetText(m_text + std::to_string(m_Score));
}