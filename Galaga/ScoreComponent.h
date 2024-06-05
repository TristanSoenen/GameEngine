#pragma once
#include <Component.h>
#include "Observer.h"

namespace dae
{
	class Font;
	class TextComponent;
	class ScoreComponent : public Component, Observer
	{
	public:
		ScoreComponent(GameObject* pOwner, std::shared_ptr<Font> font);
		~ScoreComponent() = default;
		void Notify(Event event);
		Observer* GetObserver() { return this; }//m_Observer.get(); }
	private:
		std::shared_ptr<TextComponent> m_TextComp;
		std::shared_ptr<Font> m_font;
		//std::unique_ptr<Observer> m_Observer;
		int m_Score = 0;
	};
}