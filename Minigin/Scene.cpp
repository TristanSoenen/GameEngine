#include "Scene.h"
#include "GameObject.h"
#include <algorithm>

using namespace dae;

unsigned int Scene::m_idCounter = 0;

Scene::Scene(const std::string& name) : m_name(name) {}

Scene::~Scene() = default;

void Scene::Add(std::shared_ptr<GameObject> object)
{
	m_objects.emplace_back(std::move(object));
}

void Scene::Remove(std::shared_ptr<GameObject> object)
{
	m_objects.erase(std::remove(m_objects.begin(), m_objects.end(), object), m_objects.end());
}

void Scene::RemoveAll()
{
	m_objects.clear();
}

void Scene::Fixed_Update()
{
	for (auto& object : m_objects)
	{
		object->Fixed_Update();
	}
}

void Scene::Update()
{
	for(auto& object : m_objects)
	{
		object->Update();
	}

	for (auto& object : m_objects)
	{
		if (object != nullptr)
		{
			if (object->GetMarkedForDead() == true)
			{
				object.reset();
				Remove(object);
			}
		}
	}
}

void Scene::Render() const
{
	for (const auto& object : m_objects)
	{
		object->Render();
	}
}