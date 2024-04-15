#include "TextComponent.h"
#include "GameObject.h"
#include "TextObject.h"
#include "TransformComponent.h"
#include "Font.h"

dae::TextComponent::TextComponent(dae::GameObject* pOwner, std::string text, std::shared_ptr<dae::Font> font)
	:Component(pOwner)
{
	m_TextObject = std::make_unique<TextObject>(text, font);

	auto transformComp =  pOwner->GetComponent<TransformComponent>();
	auto pos = transformComp->GetPosition();
	m_TextObject->SetPosition(pos.x, pos.y);
}

void dae::TextComponent::Render()
{
	m_TextObject->Render();
}

void dae::TextComponent::SetPosition(float x, float y)
{
	m_TextObject->SetPosition(x, y);
}

void dae::TextComponent::SetText(std::string text)
{
	m_TextObject->SetText(text);
}