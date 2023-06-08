#include <iostream>
#include "Managers.h"

EntityManager::EntityManager(sf::RenderWindow& window)
{
	m_player = new Player(Vector(window.getSize().x / 2, window.getSize().y * 0.75f));
	m_enemyManager = new EnemyManager(window);
}

EntityManager::~EntityManager()
{
	delete m_player;
	delete m_enemyManager;
}

void EntityManager::tick(sf::RenderWindow& window, float deltaTime)
{
	m_player->tick(deltaTime);
	m_enemyManager->tick(window, *m_player, deltaTime);
}

void EntityManager::draw(sf::RenderWindow& window)
{
	m_player->draw(window);
	m_enemyManager->draw(window);
}