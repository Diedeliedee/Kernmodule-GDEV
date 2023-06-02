#include "GameObjects.h"

Enemy::Enemy(float xPos, Vector2 vel)
{
	//setPosition(Vector2(xPos, 0 - m_height / 2));
	setPosition(Vector2(50, 50));
	m_sprite = new Square(m_width, m_height);

	m_velocity = vel;

	m_mass = 1;
	m_drag = 0;
}

void Enemy::tick(float deltaTime)
{
	m_force.y = 1000;
	iterateMovement(deltaTime);
}
