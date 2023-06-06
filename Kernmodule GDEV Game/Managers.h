#pragma once
#include <list>
#include "SFML/Graphics.hpp"
#include "GameObjects.h"

class EntityManager
{
private:
	Player m_player;
	Enemy m_enemy;

	Bounds m_screenBounds;

public:
	EntityManager(float screenWidth, float screenHeight);

	void tick(float deltaTime);

	void draw(sf::RenderWindow& window);
};