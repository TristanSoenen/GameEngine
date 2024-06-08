#pragma once
#include <Component.h>
#include "Observer.h"

namespace dae
{
	class Font;
	class TextComponent;
	class ScoreComponent final: public Component, Observer
	{
	public:
		ScoreComponent(GameObject* pOwner, std::shared_ptr<Font> font);
		~ScoreComponent() = default;
		void Notify(Event event);
		Observer* GetObserver() { return this; }
	private:
		std::shared_ptr<TextComponent> m_TextComp;
		std::shared_ptr<Font> m_font;
		int m_Score = 0;
		const std::string m_text = "Score: ";
	};
}