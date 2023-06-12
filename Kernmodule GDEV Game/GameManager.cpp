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

	entities = new EntityManager();
	score = new ScoreManager();
	camera = new CameraManager();
}

GameManager::~GameManager()
{
	delete entities;
	delete score;
	delete camera;

	///	Since the memory the 'activeWindow' member holds, is one layer above the GameManager,
	/// I suppose the memory won't get leaked if the manager gets deleted.
	/// In fact, we probably don't automatically want the window to be deleted after the manager is gone.
	//delete activeWindow;

	///	I believe since m_instance is a reference to the class it's in,
	/// The memory it holds should clear on it's own, if the class it's references to gets deleted.
}

GameManager* GameManager::instance()
{
	return m_instance;
}

void GameManager::tick()
{
	auto epochTime = std::chrono::system_clock::now().time_since_epoch();
	auto seed = std::chrono::duration_cast<std::chrono::milliseconds>(epochTime).count();

	srand(seed);

	entities->tick(deltaTime);
	camera->tick(deltaTime);
}

void GameManager::draw()
{
	activeWindow->clear();
	entities->draw(*activeWindow);
	score->draw(*activeWindow);
	activeWindow->display();
}
