#include <iostream>
#include "Managers.h"

EntityManager::EntityManager(float screenWidth, float screenHeight)
{
	m_player = new Player(Vector(screenWidth / 2, screenHeight * 0.75f));
	m_enemy = new Enemy(screenWidth / 2, Vector(0, 0));

	m_screenBounds = Bounds(screenWidth, screenHeight);
}

EntityManager::~EntityManager()
{
	delete m_player;
	delete m_enemy;
}

void EntityManager::tick(float deltaTime)
{
	m_player->tick(deltaTime);
	m_enemy->tick(deltaTime);

	///	Putting and '*' in front of a pointer like this means you're passing in the contents of the pointer,
	/// and not the pointer itself.
	if (m_enemy->collidesWith(*m_player))
	{
		std::cout << "Enemy has been hit!" << std::endl;
	}
}

void EntityManager::draw(sf::RenderWindow& window)
{
	m_player->draw(window);
	m_enemy->draw(window);
}