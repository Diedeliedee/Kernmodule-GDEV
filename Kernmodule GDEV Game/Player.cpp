#include <iostream>
#include "GameObjects.h"
#include "GameManager.h"

Player::Player() 
{

}

Player::Player(Vector pos)
{
	m_sprite = new Square(m_width, m_height);
	setPosition(pos);

	m_speed = 750;
	m_grip = 8;
}

void Player::tick(float deltaTime)
{
	auto input = m_controls.getInput();
	auto halfWidth = m_width / 2;
	auto screenWidth = GameManager::instance()->screenWidth;

	//	Iterating movement.
	m_desiredVelocity.x = input.x * m_speed;
	iterateMovement(deltaTime);

	//	Detecting, and reacting to bouncing to the walls.
	if (m_position.x - halfWidth <= 0)
	{
		m_position.x = 0 + halfWidth;
		bounce();
	}
	else if (m_position.x + halfWidth >= screenWidth)
	{
		m_position.x = screenWidth - halfWidth;
		bounce();
	}

	//std::cout << "Input: " << input.x << ". Speed: " << speed << ". Delta time: " << deltaTime << "." << std::endl;
}

void Player::bounce()
{
	m_velocity.x = -m_velocity.x * m_bounceFactor;
}