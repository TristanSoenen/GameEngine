#include "FPSComponent.h"
#include "GameObject.h"
#include "iostream"
#include "DeltaTime.h"
#include "TextObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::FPSComponent::FPSComponent(dae::GameObject* pOwner, int test)
	: dae::Component{pOwner},
	m_Frames_Per_Second{ 0.0f },
	m_fpsText{ "" },
	m_FrameCounter{ test },
	m_Delay{ 0.0f },
	m_MaxDelay{0.3f}
{
	
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	m_TextObject = std::make_shared<dae::TextObject>(m_fpsText, font);
	
}

void dae::FPSComponent::Update()
{
	m_Delay += DeltaTime::GetInstance().GetDeltaTime();
	m_FrameCounter++;
	if (m_Delay >= m_MaxDelay)
	{
		m_Frames_Per_Second = std::round(float(m_FrameCounter / m_MaxDelay));
		m_fpsText = std::to_string(m_Frames_Per_Second);
		m_TextObject->SetText(std::format("{:.1f}", m_FrameCounter / m_Delay));
		m_TextObject->Update();
		m_FrameCounter = 0;
		m_Delay = 0.0f;
	}
}

void dae::FPSComponent::Render()
{
	m_TextObject->Render();
}