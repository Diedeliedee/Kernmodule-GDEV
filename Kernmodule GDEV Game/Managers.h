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
	Enemy* m_enemy;

	Bounds m_screenBounds;

public:
	EntityManager(float screenWidth, float screenHeight);

	~EntityManager();

	void tick(float deltaTime);

	void draw(sf::RenderWindow& window);
};