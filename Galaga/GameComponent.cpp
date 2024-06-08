#include "GameComponent.h"
#include "HelperFunctions.h"
#include "SceneManager.h"
#include "EnemyComponent.h"
#include "ScoreComponent.h"
#include "EnemyManagerComponent.h"
#include "TextComponent.h"
#include "BackGround.h"
#include "Scene.h"
#include "ResourceManager.h"

dae::GameComponent::GameComponent(dae::GameObject* pOwner)
	:dae::Component(pOwner)
{

}

void dae::GameComponent::Notify(Event event)
{
	switch (event.type)
	{
	case GAME_OVER:
		CreateShotSFiredLevel();
		break;
	case HIT:
		++m_Hits;
		break;
	case FIRED:
		++m_TotalShotsFired;
		break;
	case LEVEL_COMPLETE:
		if (m_CurrentLevel == 2) CreateShotSFiredLevel();
		if (m_CurrentLevel == 1) CreateLevel("../Data/Formation3Bees.txt", "../Data/Formation3Butterflies.txt", "../Data/Formation3Boss.txt", 2);;
		if (m_CurrentLevel == 0) CreateLevel("../Data/Formation2Bees.txt", "../Data/Formation2Butterflies.txt", "../Data/Formation2Boss.txt", 1);
		break;
	}
}

void dae::GameComponent::Update()
{
	if (m_ShowResults == true)
	{
		if (m_GoToHighScoreLevel == true)
		{
			CreateScoreBoard();
			m_ShowResults = false;
		}
	}
}

void dae::GameComponent::CreateLevel(std::string beeFile, std::string butterflyFile, std::string bossFile, int levelidx)
{
	auto scene = dae::SceneManager::GetInstance().GetCurrentScene();
	auto currentscenegameObjects = scene->GetAllObjects();

	auto nextScene = dae::SceneManager::GetInstance().GetSceneAtIndex(levelidx);

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
	int halfindex = 0;
	int enemyCountLeft = 0;
	int enemyCountRight = 0;
	////adding enemies to the game with filepositions
	std::vector<glm::vec2> positions;
	ReadPositions(positions, beeFile);
	halfindex = int(positions.size() / 2) - 1;
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto bee = std::make_shared<dae::GameObject>();
		if (i > halfindex)
		{
			bee->AddComponent(std::make_shared<dae::EnemyComponent>(bee.get(), positions[i], dae::EnemyTypes::BEE, false));
			bee->SetPosition(400.0f + (50.0f * enemyCountRight), 400 + (50.0f * enemyCountRight));
			++enemyCountRight;
		}
		else
		{
			bee->AddComponent(std::make_shared<dae::EnemyComponent>(bee.get(), positions[i], dae::EnemyTypes::BEE, true));
			bee->SetPosition(-50.0f * enemyCountLeft, 400 + (50.0f * enemyCountLeft));
			++enemyCountLeft;
		}
		auto beeComp2 = bee->GetComponent<dae::EnemyComponent>();
		beeComp2->AddObserverToEnemy(scoreComp->GetObserver());
		enemyManagerComp->AddEnemy(beeComp2.get());
		nextScene->Add(bee);
	}
	halfindex = 0;
	positions.clear();
	ReadPositions(positions, butterflyFile);
	halfindex = int(positions.size() / 2) - 1;
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto btfly = std::make_shared<dae::GameObject>();

		if (i > halfindex)
		{
			btfly->AddComponent(std::make_shared<dae::EnemyComponent>(btfly.get(), positions[i], dae::EnemyTypes::BUTTERFLY, false));
			btfly->SetPosition(800.0f + (50.0f * enemyCountRight), 800 + (50.0f * enemyCountRight));
			++enemyCountRight;
		}
		else
		{
			btfly->AddComponent(std::make_shared<dae::EnemyComponent>(btfly.get(), positions[i], dae::EnemyTypes::BUTTERFLY, true));
			btfly->SetPosition( -400 -50.0f * enemyCountLeft, 800 + (50.0f * enemyCountLeft));
			++enemyCountLeft;
		}
		auto btlfyComp = btfly->GetComponent<dae::EnemyComponent>();
		btlfyComp->AddObserverToEnemy(scoreComp->GetObserver());
		enemyManagerComp->AddEnemy(btlfyComp.get());
		nextScene->Add(btfly);
	}
	halfindex = 0;
	positions.clear();
	ReadPositions(positions, bossFile);
	halfindex = int(positions.size() / 2) - 1;
	for (int i = 0; i < int(positions.size()); i++)
	{
		auto bs = std::make_shared<dae::GameObject>();
		if (i > halfindex)
		{
			bs->AddComponent(std::make_shared<dae::EnemyComponent>(bs.get(), positions[i], dae::EnemyTypes::BOSS, false));
			bs->SetPosition(1200.0f + (50.0f * enemyCountRight), 1200 +(50.0f * enemyCountRight));
			++enemyCountRight;
		}
		else
		{
			bs->AddComponent(std::make_shared<dae::EnemyComponent>(bs.get(), positions[i], dae::EnemyTypes::BOSS, true));
			bs->SetPosition(-800 -50.0f * enemyCountLeft, 1200 + (50.0f * enemyCountLeft));
			++enemyCountLeft;
		}
		auto bsComp = bs->GetComponent<dae::EnemyComponent>();
		bsComp->AddObserverToEnemy(scoreComp->GetObserver());
		enemyManagerComp->AddEnemy(bsComp.get());
		nextScene->Add(bs);
	}

	dae::SceneManager::GetInstance().SetCurrentScene(levelidx);
	++m_CurrentLevel;
}

void dae::GameComponent::CreateShotSFiredLevel()
{
	auto scene = dae::SceneManager::GetInstance().GetCurrentScene();
	auto currentscenegameObjects = scene->GetAllObjects();

	auto nextScene = dae::SceneManager::GetInstance().GetSceneAtIndex(3);

	for (auto& currentSceneGameObject : currentscenegameObjects)
	{
		if (currentSceneGameObject->GetComponent<dae::BackGround>() != nullptr)
		{
			nextScene->Add(currentSceneGameObject);
		}

		if (currentSceneGameObject->GetComponent<dae::GameComponent>() != nullptr)
		{
			nextScene->Add(currentSceneGameObject);
		}
	}

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 50);
	auto text1 = std::make_shared<dae::GameObject>();
	text1->AddComponent(std::make_shared<dae::TextComponent>(text1.get(), "--RESULTS--", font));
	text1->SetPosition(100, 50);
	nextScene->Add(text1);
	auto text2 = std::make_shared<dae::GameObject>();
	text2->AddComponent(std::make_shared<dae::TextComponent>(text2.get(), "SHOTSFIRED: " + std::to_string(m_TotalShotsFired), font));
	text2->SetPosition(10, 150);
	nextScene->Add(text2);
	auto text3 = std::make_shared<dae::GameObject>();
	text3->AddComponent(std::make_shared<dae::TextComponent>(text3.get(), "NUMBEROFHITS: " + std::to_string(m_Hits), font));
	text3->SetPosition(10, 200);
	nextScene->Add(text3);
	int percentage = 0;
	if (m_TotalShotsFired > 0)
	{
		percentage = int(float(m_Hits) / float(m_TotalShotsFired) * 100);
	}
	auto text4 = std::make_shared<dae::GameObject>();
	text4->AddComponent(std::make_shared<dae::TextComponent>(text4.get(), "HITMISSRATIO: %" + std::to_string(percentage), font));
	text4->SetPosition(10, 250);
	nextScene->Add(text4);
	m_ShowResults = true;
	dae::SceneManager::GetInstance().SetCurrentScene(3);
}

void dae::GameComponent::CreateScoreBoard()
{
	auto scene = dae::SceneManager::GetInstance().GetCurrentScene();
	auto currentscenegameObjects = scene->GetAllObjects();
	auto nextScene = dae::SceneManager::GetInstance().GetSceneAtIndex(4);
	for (auto& currentSceneGameObject : currentscenegameObjects)
	{
		if (currentSceneGameObject->GetComponent<dae::BackGround>() != nullptr)
		{
			nextScene->Add(currentSceneGameObject);
		}
	}

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 35);
	auto text1 = std::make_shared<dae::GameObject>();
	text1->AddComponent(std::make_shared<dae::TextComponent>(text1.get(), "--Highscores--", font));
	text1->SetPosition(100, 50);
	nextScene->Add(text1);
	std::vector<std::string> highscores;
	ReadHighscores(highscores, "../Data/highscores.txt");
	for (int i = 0; i < int(highscores.size()); i++)
	{
		auto text = std::make_shared<dae::GameObject>();
		text->AddComponent(std::make_shared<dae::TextComponent>(text.get(), highscores[i], font));
		text->SetPosition(10, 100 + 50.0f * i);
		nextScene->Add(text);
	}	

	dae::SceneManager::GetInstance().SetCurrentScene(4);
}