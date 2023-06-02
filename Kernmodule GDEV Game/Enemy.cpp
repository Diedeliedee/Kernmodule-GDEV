#include "GameObjects.h"

Enemy::Enemy(float xPos, Vector2 vel)
{
	m_sprite = new Square(m_width, m_height);
	setPosition(Vector2(xPos, 0 - m_height / 2));
	m_velocity = vel;
}