#include "GameComponent.h"
#include "HelperFunctions.h"
#include "SceneManager.h"
#include "EnemyComponent.h"
#include "ScoreComponent.h"
#include "EnemyManagerComponent.h"
#include "Scene.h"

dae::GameComponent::GameComponent(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{

}

void dae::GameComponent::Notify(Event event)
{
	switch (event.type)
	{
	case GAME_OVER:
	
		break;
	case HIT:
		++m_Hits;
		break;
	case FIRED:
		++m_TotalShotsFired;
		break;
	case LEVEL_COMPLETE:
		if (m_CurrentLevel == 1) CreateLevel3();
		if (m_CurrentLevel == 0) CreateLevel2();
		break;
	}
}

void dae::GameComponent::CreateGameOverScreen()
{

}

void dae::GameComponent::CreateLevel1()
{

}

void dae::GameComponent::CreateLevel2()
{
	auto scene = dae::SceneManager::GetInstance().GetCurrentScene();
	auto currentscenegameObjects = scene->GetAllObjects();

	auto nextScene = dae::SceneManager::GetInstance().GetSceneAtIndex(1);

	std::shared_ptr<dae::ScoreComponent>scoreComp;
	std::shared_ptr<dae::EnemyManagerComponent> enemyManagerComp;
	for (auto& currentSceneGameObject : currentscenegameObjects)
	{
	
		if (currentSceneGameObject->GetComponent<dae::EnemyManagerComponent>() != nullptr)
		{
			enemyManagerComp = currentSceneGameObject->GetComponent<dae::EnemyManagerComponent>();
		}
		if (currentSceneGameObject->GetComponent<dae::ScoreComponent>() != nullptr)
		{
			scoreComp = currentSceneGameObject->GetComponent<dae::ScoreComponent>();
		}
		nextScene->Add(currentSceneGameObject);
	}


	////adding enemies to the game with filepositions
	std::vector<glm::vec2> positions;
	ReadPositions(positions, "../Data/Formation1Bees.txt");
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto bee = std::make_shared<dae::GameObject>();
		bee->AddComponent(std::make_shared<dae::EnemyComponent>(bee.get(), positions[i], dae::EnemyTypes::BEE));
		auto beeComp2 = bee->GetComponent<dae::EnemyComponent>();
		beeComp2->AddObserverToEnemy(scoreComp->GetObserver());
		bee->SetPosition(-50.0f * i, 400);
		enemyManagerComp->AddEnemy(beeComp2.get());
		nextScene->Add(bee);
	}
	positions.clear();
	ReadPositions(positions, "../Data/Formation1Butterflies.txt");
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto btfly = std::make_shared<dae::GameObject>();
		btfly->AddComponent(std::make_shared<dae::EnemyComponent>(btfly.get(), positions[i], dae::EnemyTypes::BUTTERFLY));
		auto btlfyComp = btfly->GetComponent<dae::EnemyComponent>();
		btlfyComp->AddObserverToEnemy(scoreComp->GetObserver());
		btfly->SetPosition(-50.0f * i, 400);
		enemyManagerComp->AddEnemy(btlfyComp.get());
		nextScene->Add(btfly);
	}
	positions.clear();
	ReadPositions(positions, "../Data/Formation1Boss.txt");
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto bs = std::make_shared<dae::GameObject>();
		bs->AddComponent(std::make_shared<dae::EnemyComponent>(bs.get(), positions[i], dae::EnemyTypes::BOSS));
		auto bsComp = bs->GetComponent<dae::EnemyComponent>();
		bsComp->AddObserverToEnemy(scoreComp->GetObserver());
		bs->SetPosition(-50.0f * i, 400);
		enemyManagerComp->AddEnemy(bsComp.get());
		nextScene->Add(bs);
	}

	dae::SceneManager::GetInstance().SetCurrentScene(1);
	m_CurrentLevel = 1;
}

void dae::GameComponent::CreateLevel3()
{
	auto scene = dae::SceneManager::GetInstance().GetCurrentScene();
	auto currentscenegameObjects = scene->GetAllObjects();

	auto nextScene = dae::SceneManager::GetInstance().GetSceneAtIndex(2);

	std::shared_ptr<dae::ScoreComponent>scoreComp;
	std::shared_ptr<dae::EnemyManagerComponent> enemyManagerComp;
	for (auto& currentSceneGameObject : currentscenegameObjects)
	{

		if (currentSceneGameObject->GetComponent<dae::EnemyManagerComponent>() != nullptr)
		{
			enemyManagerComp = currentSceneGameObject->GetComponent<dae::EnemyManagerComponent>();
		}
		if (currentSceneGameObject->GetComponent<dae::ScoreComponent>() != nullptr)
		{
			scoreComp = currentSceneGameObject->GetComponent<dae::ScoreComponent>();
		}
		nextScene->Add(currentSceneGameObject);
	}


	////adding enemies to the game with filepositions
	std::vector<glm::vec2> positions;
	ReadPositions(positions, "../Data/Formation1Bees.txt");
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto bee = std::make_shared<dae::GameObject>();
		bee->AddComponent(std::make_shared<dae::EnemyComponent>(bee.get(), positions[i], dae::EnemyTypes::BEE));
		auto beeComp2 = bee->GetComponent<dae::EnemyComponent>();
		beeComp2->AddObserverToEnemy(scoreComp->GetObserver());
		bee->SetPosition(-50.0f * i, 400);
		enemyManagerComp->AddEnemy(beeComp2.get());
		nextScene->Add(bee);
	}
	positions.clear();
	ReadPositions(positions, "../Data/Formation1Butterflies.txt");
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto btfly = std::make_shared<dae::GameObject>();
		btfly->AddComponent(std::make_shared<dae::EnemyComponent>(btfly.get(), positions[i], dae::EnemyTypes::BUTTERFLY));
		auto btlfyComp = btfly->GetComponent<dae::EnemyComponent>();
		btlfyComp->AddObserverToEnemy(scoreComp->GetObserver());
		btfly->SetPosition(-50.0f * i, 400);
		enemyManagerComp->AddEnemy(btlfyComp.get());
		nextScene->Add(btfly);
	}
	positions.clear();
	ReadPositions(positions, "../Data/Formation1Boss.txt");
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto bs = std::make_shared<dae::GameObject>();
		bs->AddComponent(std::make_shared<dae::EnemyComponent>(bs.get(), positions[i], dae::EnemyTypes::BOSS));
		auto bsComp = bs->GetComponent<dae::EnemyComponent>();
		bsComp->AddObserverToEnemy(scoreComp->GetObserver());
		bs->SetPosition(-50.0f * i, 400);
		enemyManagerComp->AddEnemy(bsComp.get());
		nextScene->Add(bs);
	}

	dae::SceneManager::GetInstance().SetCurrentScene(2);
	m_CurrentLevel = 2;
}