#include "Managers.h"

EntityManager::EntityManager(float screenWidth, float screenHeight)
{
	m_player = Player(Vector(screenWidth / 2, screenHeight * 0.75f));
	m_enemy = Enemy(screenWidth / 2, Vector(0, 0));

	m_screenBounds = Bounds(screenWidth, screenHeight);
}

void EntityManager::tick(float deltaTime)
{
	m_player.tick(deltaTime);
	m_enemy.tick(deltaTime);
}

void EntityManager::draw(sf::RenderWindow& window)
{
	m_player.draw(window);
	m_enemy.draw(window);
}