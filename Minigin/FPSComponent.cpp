#include "FPSComponent.h"
#include "iostream"
#include "DeltaTime.h"
#include "TextObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

dae::FPSComponent::FPSComponent()
	: Component{},
	m_Frames_Per_Second{ 0.0f },
	m_fpsText{ "" }
{
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	m_TextObject = std::make_shared<dae::TextObject>(m_fpsText, font);
}
	
void dae::FPSComponent::Update()
{
	m_Frames_Per_Second = std::round(1.0f / DeltaTime::GetInstance().GetDeltaTime());
	m_fpsText = std::to_string(int(m_Frames_Per_Second));
	m_TextObject->SetText(m_fpsText + "fps");
	m_TextObject->Update();
}

void dae::FPSComponent::Render()
{
	m_TextObject->Render();
}