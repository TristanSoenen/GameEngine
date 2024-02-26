#pragma once
#include "Component.h"
#include "TextObject.h"
#include <string>
#include <memory>

namespace dae
{
	class FPSComponent : public Component
	{
	public:
		FPSComponent();
		~FPSComponent() = default;
		void Update() override;
		void Render() override;
		float getFramesPerSecond() const { return m_Frames_Per_Second; }
	private:
		float m_Frames_Per_Second;
		std::string m_fpsText;
		std::shared_ptr<dae::TextObject> m_TextObject;
		std::shared_ptr<Texture2D> m_texture{};
	};
}
