#pragma once
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "GameObjects.h"

class EnemyManager
{
private:
	const float m_minSpawnInterval = 0.5f;
	const float m_maxSpawnInterval = 1;
	float m_spawnTimer = 0;

	std::list<Enemy*> m_enemies = std::list<Enemy*>();
	int m_idCounter = 0;

public:
	void tick(Player& player, float deltaTime);

	void spawn(float xPos);

	std::list<Enemy*>::iterator despawn(Enemy& enemy);

	void draw(sf::RenderWindow& window);
};