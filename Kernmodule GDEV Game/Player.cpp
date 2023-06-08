#include <iostream>
#include "GameObjects.h"

Player::Player() 
{

}

Player::Player(Vector pos)
{
	m_sprite = new Square(100, 20);

	setPosition(pos);

	m_speed = 500;
	m_grip = 6;
}

void Player::tick(float deltaTime)
{
	Vector input = m_controls.getInput();

	m_desiredVelocity.x = input.x * m_speed;
	iterateMovement(deltaTime);

	//std::cout << "Input: " << input.x << ". Speed: " << speed << ". Delta time: " << deltaTime << "." << std::endl;
}