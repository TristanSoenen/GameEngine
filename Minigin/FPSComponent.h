#pragma once
#include "Component.h"
#include "TextObject.h"
#include <string>
#include <memory>
#include <chrono>

namespace dae
{
	class GameObject;

	class FPSComponent : public Component
	{
	public:
		FPSComponent(GameObject* pOwner, int test);
		~FPSComponent() = default;
		void Update() override;
		void Render() override;
		float getFramesPerSecond() const { return m_Frames_Per_Second; }
		
	private:
		float m_Frames_Per_Second;
		int m_FrameCounter;
		float m_Delay;
		const float m_MaxDelay;
		
		std::string m_fpsText;
		std::shared_ptr<dae::TextObject> m_TextObject;
		std::shared_ptr<Texture2D> m_texture{};
	};
}
