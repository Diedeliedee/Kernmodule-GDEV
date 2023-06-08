#pragma once
#include <list>
#include "SFML/Graphics.hpp"
#include "GameObjects.h"

class EntityManager
{
private:
	/// These variables are pointers, as they are assigned in the stack of the manager's constructor.
	/// That data, since it's on the stack, and deleted once the scope is left, will probably disappear as well.
	/// That causes these variables to become "null" in plain C# terms.
	Player* m_player;

	EnemyManager* m_enemyManager;

public:
	EntityManager(sf::RenderWindow& window);

	~EntityManager();

	void tick(sf::RenderWindow& window, float deltaTime);

	void draw(sf::RenderWindow& window);
};



class EnemyManager
{
private:
	std::list<Enemy> m_enemies;

	int m_idCounter;

public:
	EnemyManager();

	EnemyManager(sf::RenderWindow& window);

	void tick(sf::RenderWindow& window, Player& player, float deltaTime);

	void spawn(float xPos);

	void despawn(Enemy& enemy);

	void draw(sf::RenderWindow& window);
};