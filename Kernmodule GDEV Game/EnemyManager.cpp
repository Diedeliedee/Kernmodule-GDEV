#include <iostream>
#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
	m_enemies = std::list<Enemy*>();
}

void EnemyManager::tick(sf::RenderWindow& window, Player& player, float deltaTime)
{
	//	Updating the enemies.
	auto it = m_enemies.begin();
	for (auto it = m_enemies.begin(); it != m_enemies.end(); it++)
	{
		(*it)->tick(deltaTime);

		///	Putting and '*' in front of a pointer like this means you're passing in the contents of the pointer,
		/// and not the pointer itself.
		if ((*it)->collidesWith(player))
		{
			std::cout << "Enemy has been hit!" << std::endl;
			//despawn(**it);
		}
	};

	//	Regulating enemy spawning
	m_spawnTimer += deltaTime;

	if (m_spawnTimer < m_maxSpawnInterval) return;
	spawn(100);
	m_spawnTimer = 0;
}

void EnemyManager::spawn(float xPos)
{
	m_enemies.push_front(new Enemy(m_idCounter++, xPos));
}

void EnemyManager::despawn(Enemy& enemy)
{
	auto it = m_enemies.begin();
	for (it; it != m_enemies.end(); it++)
	{
		if (enemy.id != (*it)->id) continue;
		break;
	}
	delete (*it);
	m_enemies.erase(it);
}

void EnemyManager::draw(sf::RenderWindow& window)
{
	for (auto it = m_enemies.begin(); it != m_enemies.end(); it++)
	{
		(*it)->draw(window);
	}
}
