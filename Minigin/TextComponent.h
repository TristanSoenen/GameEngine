#pragma once
#include "Component.h"
#include <memory>
namespace dae
{
	class Font;
	class TextObject;
	class GameObject;

	class TextComponent : public Component
	{
	public:
		TextComponent(GameObject* pOwner, std::string text, std::shared_ptr<Font> font);
		~TextComponent() = default;
		void Render() override;
		void SetPosition(float x, float y);
		void SetText(std::string text);
	private:
		std::unique_ptr<TextObject> m_TextObject;
	};
}