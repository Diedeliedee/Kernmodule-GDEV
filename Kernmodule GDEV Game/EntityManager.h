#pragma once
#include <list>
#include "SFML/Graphics.hpp"
#include "GameObjects.h"
#include "EnemyManager.h"

class EntityManager
{
private:
	/// These variables are pointers, as they are assigned in the stack of the manager's constructor.
	/// That data, since it's on the stack, and deleted once the scope is left, will probably disappear as well.
	/// That causes these variables to become "null" in plain C# terms.
	Player* m_player = nullptr;

	EnemyManager m_enemyManager = EnemyManager();

public:
	EntityManager();

	~EntityManager();

	void tick(float deltaTime);

	Player& getPlayer();

	EnemyManager& getEnemies();

	void draw(sf::RenderWindow& window);
};