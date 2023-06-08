#include "GameObjects.h"

Enemy::Enemy(int id)
{
	this->id = id;
}

Enemy::Enemy(int id, float xPos, Vector vel)
{
	this->id = id;

	m_sprite = new Square(10, 10);

	setPosition(m_sprite->bounds.getOffset(Vector(xPos, 0), Vector(0, -1)));
	m_velocity = vel;

	m_mass = 1;
	m_drag = 0;
}

void Enemy::tick(float deltaTime)
{
	m_force.y = 1000;
	iterateMovement(deltaTime);
}
