#pragma once
#include "Component.h"
#include "Transform.h"
#include <string>
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
	};
}
