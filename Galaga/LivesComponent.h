#pragma once
#include <Component.h>
#include <Observer.h>

namespace dae
{
	class Font;
	class TextComponent;
	class LivesComponent final: public Component, Observer
	{
	public:
		LivesComponent(GameObject* pOwner, int lives, std::shared_ptr<Font> font);
		~LivesComponent() = default;
		void Notify(Event event);
		Observer* GetObserver() { return this; }
	private:
		std::shared_ptr<TextComponent> m_TextComp;
		std::shared_ptr<Font> m_font;
		int m_lives;
		const std::string m_text = "Lives Left: ";
	};
}