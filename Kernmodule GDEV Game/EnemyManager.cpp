#include <iostream>
#include "EnemyManager.h"
#include "GameManager.h"

void EnemyManager::tick(Player& player, float deltaTime)
{
	regulateSpawning(deltaTime);
	regulateEnemies(player, deltaTime);
}

void EnemyManager::regulateSpawning(float deltaTime)
{
	m_spawnTimer += deltaTime;
	if (m_spawnTimer < m_maxSpawnInterval) return;

	auto spawnPos = Vector(rand() % GameManager::instance()->screenWidth, -(rand() % m_maxSpawnHeight));

	spawn(spawnPos);
	m_spawnTimer = 0;
}

void EnemyManager::regulateEnemies(Player& player, float deltaTime)
{
	for (auto it = m_enemies.begin(); it != m_enemies.end();)
	{
		(*it)->tick(deltaTime);

		if ((*it)->collidesWith(player))
		{
			//	The double star looks weird, but I guess having to dereference a "pointer" to a pointer call for measures like these.
			it = GameManager::instance()->onEnemyCaught(*(*it));
			break;
		}
		if ((*it)->escaped())
		{
			it = GameManager::instance()->onEnemyEscaped(*(*it));
			break;
		}

		//	Only iterate forward if the enemy in this iteration has not been deleted.
		it++;
	};
}

void EnemyManager::spawn(Vector pos)
{
	m_enemies.push_front(new Enemy(m_idCounter++, pos));
}

std::list<Enemy*>::iterator EnemyManager::despawn(Enemy& enemy)
{
	auto it = m_enemies.begin();
	for (it; it != m_enemies.end(); it++)
	{
		if (enemy.id != (*it)->id) continue;
		break;
	}
	delete (*it);
	return m_enemies.erase(it);
}

void EnemyManager::draw(sf::RenderWindow& window)
{
	for (auto it = m_enemies.begin(); it != m_enemies.end(); it++)
	{
		(*it)->draw(window);
	}
}
