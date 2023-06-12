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

	entities	= new EntityManager();
	score		= new ScoreManager(Vector(screenWidth, screenHeight));
	camera		= new CameraManager();
	time		= new TimeManager();
}

GameManager::~GameManager()
{
	delete entities;
	delete score;
	delete camera;
	delete time;

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

	srand(seed);

	time		->tick(deltaTime);
	score		->tick(deltaTime);
	entities	->tick(scaledDeltaTime);
	camera		->tick(scaledDeltaTime);
}

std::list<Enemy*>::iterator GameManager::onEnemyCaught(Enemy& enemy)
{
	std::cout << "Enemy has been hit!" << std::endl;

	camera->startShake();
	if (score->reachedScoreGoal(1))
	{
		//	Finish game.
	}

	return entities->getEnemies().despawn(enemy);
}

std::list<Enemy*>::iterator GameManager::onEnemyEscaped(Enemy& enemy)
{
	std::cout << "An enemy has escaped!" << std::endl;

	time->timeScale = 0;
	if (score->depletedAllTries(1))
	{
		//	Lose game.
	}

	return entities->getEnemies().despawn(enemy);
}

void GameManager::draw()
{
	activeWindow	->clear();
	score			->draw(*activeWindow);
	entities		->draw(*activeWindow);
	activeWindow	->display();
}
