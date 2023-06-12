#include "EntityManager.h"
#include "GameManager.h"

EntityManager::EntityManager()
{
	auto game = GameManager::instance();

	m_player = new Player(Vector(game->screenWidth / 2, game->screenHeight * 0.75f));
}

EntityManager::~EntityManager()
{
	delete m_player;
}

void EntityManager::tick(float deltaTime)
{
	m_player->tick(deltaTime);
	m_enemyManager.tick(*m_player, deltaTime);
}

void EntityManager::draw(sf::RenderWindow& window)
{
	m_player->draw(window);
	m_enemyManager.draw(window);
}