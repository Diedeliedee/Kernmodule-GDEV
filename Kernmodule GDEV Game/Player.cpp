#include <iostream>
#include "GameObjects.h"

Player::Player(Vector2 pos)
{
	setPosition(pos);
	m_sprite = new Square(m_width, m_height);

	m_speed = 500;
	m_grip = 6;
}

void Player::tick(float deltaTime)
{
	Vector2 input = m_controls.getInput();

	m_desiredVelocity.x = input.x * m_speed;
	iterateMovement(deltaTime);

	//std::cout << "Input: " << input.x << ". Speed: " << speed << ". Delta time: " << deltaTime << "." << std::endl;
}