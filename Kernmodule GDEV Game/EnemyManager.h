#pragma once
#include <iostream>
#include <list>
#include "GameObjects.h"

class EnemyManager
{
private:
	const float m_minSpawnInterval = 1;
	const float m_maxSpawnInterval = 5;
	float m_spawnTimer;

	std::list<Enemy*> m_enemies;
	int m_idCounter;

public:
	EnemyManager();

	void tick(sf::RenderWindow& window, Player& player, float deltaTime);

	void spawn(float xPos);

	void despawn(Enemy& enemy);

	void draw(sf::RenderWindow& window);
};