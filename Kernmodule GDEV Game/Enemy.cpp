#include "GameObjects.h"

Enemy::Enemy()
{

}

Enemy::Enemy(float xPos, Vector2 vel)
{
	m_sprite = new Square(10, 10);

	setPosition(m_sprite->bounds.getOffset(Vector2(xPos, 0), Vector2(0, -1)));
	m_velocity = vel;

	m_mass = 1;
	m_drag = 0;
}

void Enemy::tick(float deltaTime)
{
	m_force.y = 1000;
	iterateMovement(deltaTime);
}
