#pragma once
#include "TextObject.h"
#include "Component.h"
#include "Observer.h"
#include "Structs.h"
#include "glm/glm.hpp"
#include <iostream>
#include <memory>
#include <string>

namespace dae
{
	class GameObject;
	class Texture2D;
	class TextObject;
	class LivesUIComponent :public Component, public Observer
	{
	public:
		LivesUIComponent(GameObject* pOwner);
		~LivesUIComponent() = default;
		void Render() override;
		void PlayerDied();
		void Notify(Event eventFunction) override;
	private:
		int m_AmountOfLives = 3;
		std::string m_LivesText = "# lives : " + std::to_string(m_AmountOfLives);
		std::shared_ptr<TextObject> m_TextObject;
		glm::vec2 m_Pos;
	};
}