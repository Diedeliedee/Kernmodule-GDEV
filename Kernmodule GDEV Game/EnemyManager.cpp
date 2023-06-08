#include <iostream>
#include "Managers.h"

EnemyManager::EnemyManager(sf::RenderWindow& window)
{
	/*
	spawn(window.getSize().x / 2);
	*/
}

void EnemyManager::tick(sf::RenderWindow& window, Player& player, float deltaTime)
{
	/*
	auto it = m_enemies.begin();

	for (it; it != m_enemies.end(); it++)
	{
		it->tick(deltaTime);

		///	Putting and '*' in front of a pointer like this means you're passing in the contents of the pointer,
		/// and not the pointer itself.
		if (it->collidesWith(player))
		{
			std::cout << "Enemy has been hit!" << std::endl;
		}
	}
	*/
}

void EnemyManager::spawn(float xPos)
{
	/*
	m_enemies.push_front(Enemy(m_idCounter++, xPos, Vector(0, 0)));
	*/
}

void EnemyManager::despawn(Enemy& enemy)
{
	/*
	auto it = m_enemies.begin();

	for (it; it != m_enemies.end(); it++)
	{
		if (enemy.id == it->id);
	}
	*/
}

void EnemyManager::draw(sf::RenderWindow& window)
{
	/*
	auto it = m_enemies.begin();

	for (it; it != m_enemies.end(); it++)
	{
		it->draw(window);
	}
	*/
}
