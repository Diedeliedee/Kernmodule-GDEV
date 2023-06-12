#include "GameManager.h"
#include <iostream>
#include <chrono>

GameManager* GameManager::m_instance;	//	I have to "define" the static member here in the CPP file, or I will get an error.

GameManager::GameManager()
{
	//	Setting up singleton.
	if (m_instance == nullptr)
	{
		m_instance = this;
	}

	auto screenSize = Vector(screenWidth, screenHeight);

	entities	= new EntityManager();
	score		= new ScoreManager(screenSize);
	camera		= new CameraManager();
	time		= new TimeManager();
	scene		= new SceneManager(screenSize);

	//	Start with the "curtains" closed.
	scene->setCurtainValue(0);
}

GameManager::~GameManager()
{
	delete entities;
	delete score;
	delete camera;
	delete time;
	delete scene;

	///	Since the memory the 'activeWindow' member holds, is one layer above the GameManager,
	/// I suppose the memory won't get leaked if the manager gets deleted.
	/// In fact, we probably don't automatically want the window to be deleted after the manager is gone.
	//delete activeWindow;

	///	I believe since m_instance is a reference to the class it's in,
	/// the memory it harbors should clear on it's own, if the class it references gets deleted.
}

GameManager* GameManager::instance()
{
	return m_instance;
}

void GameManager::tick()
{
	auto epochTime			= std::chrono::system_clock::now().time_since_epoch();
	auto seed				= std::chrono::duration_cast<std::chrono::milliseconds>(epochTime).count();
	float scaledDeltaTime	= time->getScaledDeltaTime(deltaTime);

	switch (m_state)
	{
	case 0:
		//	Startup phase:
		if (scene->hasOpened(deltaTime)) m_state = 1;
		break;

	case 1:
		//	Main game loop:
		srand(seed);

		time		->tick(deltaTime);
		score		->tick(deltaTime);
		entities	->tick(scaledDeltaTime);
		camera		->tick(scaledDeltaTime);
		break;

	case 2:
		//	Closing the curtains if player has either lost or won:
		score->tick(deltaTime);
		camera->tick(deltaTime);

		m_stateTimer += deltaTime;
		if (m_stateTimer < 1) return;

		if (scene->hasClosed(deltaTime))
		{
			m_state = 3;
			m_stateTimer = 0;
			scene->displayEndScreen();
		}
		break;

	case 3:
		//	Displaying endscreen.
		scene->hasOpened(deltaTime);
		break;
	}
}

std::list<Enemy*>::iterator GameManager::onEnemyCaught(Enemy& enemy)
{
	std::cout << "Enemy has been hit!" << std::endl;

	camera->startShake();
	if (score->reachedScoreGoal(1))
	{
		onWon();
	}
	return entities->getEnemies().despawn(enemy);
}

std::list<Enemy*>::iterator GameManager::onEnemyEscaped(Enemy& enemy)
{
	std::cout << "An enemy has escaped!" << std::endl;

	time->timeScale = 0;
	if (score->depletedAllTries(1))
	{
		onLost();
	}
	return entities->getEnemies().despawn(enemy);
}

void GameManager::onWon()
{
	m_state = 2;
	scene->setEndScreen("You Won!!", "You caught " + std::to_string(score->score) + " cubomycetes!");
}

void GameManager::onLost()
{
	m_state = 2;
	scene->setEndScreen("You Lost..", "You managed to catch " + std::to_string(score->score) + ".");
}

void GameManager::draw()
{
	activeWindow	->clear();
	switch (m_state)
	{
	default:
		//	Displaying main game loop:
		score			->draw(*activeWindow);
		entities		->draw(*activeWindow);
		scene			->draw(*activeWindow);
		break;

	case 3:
		//	Displaying end screen:
		scene			->draw(*activeWindow);
		break;
	}
	activeWindow	->display();
}
