#include "FPSComponent.h"
#include "iostream"
#include "DeltaTime.h"
#include "TextObject.h"
#include "ResourceManager.h"
#include <memory>

dae::FPSComponent::FPSComponent()
	: Component{},
	m_Frames_Per_Second{ 0.0f },
	m_fpsText{ "" }
{
	//empty
}
	
void dae::FPSComponent::Update()
{
	m_Frames_Per_Second = 1.0f / DeltaTime::GetInstance().GetDeltaTime();
	m_fpsText = std::to_string(m_Frames_Per_Second);
}

void dae::FPSComponent::Render()
{
	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto text = std::make_unique<dae::TextObject>("fps", font);
	text->SetPosition(20, 20);
}