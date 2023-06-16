#pragma once
#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>
#include "GameObjects.h"

class EnemyManager
{
private:
	//	Properties:
	const float m_minSpawnInterval = 0.15f;
	const float m_maxSpawnInterval = 0.6f;
	const int m_maxSpawnHeight = 100;

	//	Run-time:
	std::list<Enemy*> m_enemies = std::list<Enemy*>();
	float m_spawnTimer = 0;
	int m_idCounter = 0;

public:
	void tick(Player& player, float deltaTime);

	void regulateSpawning(float deltaTime);

	void regulateEnemies(Player& player, float deltaTime);

	void spawn(Vector pos);

	std::list<Enemy*>::iterator despawn(Enemy& enemy);

	void draw(sf::RenderWindow& window);
};