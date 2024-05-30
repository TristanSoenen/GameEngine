#include "SceneManager.h"
#include "Scene.h"

void dae::SceneManager::Fixed_Update()
{
	//for (auto& scene : m_scenes)
	//{
	//	scene->Fixed_Update();
	//}
	m_scenes[m_CurrentScene]->Fixed_Update();
}

void dae::SceneManager::Update()
{
	//for(auto& scene : m_scenes)
	//{
	//	scene->Update();
	//}
	m_scenes[m_CurrentScene]->Update();
}

void dae::SceneManager::Render()
{
	//for (const auto& scene : m_scenes)
	//{
	//	scene->Render();
	//}
	m_scenes[m_CurrentScene]->Render();
}

void dae::SceneManager::SetCurrentScene(int sceneIndex)
{
	if (sceneIndex >= 0 && sceneIndex > int(m_scenes.size()))
	{
		m_CurrentScene = sceneIndex;
	}
}

dae::Scene& dae::SceneManager::CreateScene(const std::string& name)
{
	const auto& scene = std::shared_ptr<Scene>(new Scene(name));
	m_scenes.push_back(scene);
	return *scene;
}
