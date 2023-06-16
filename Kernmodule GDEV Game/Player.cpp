#include <iostream>
#include "GameObjects.h"
#include "GameManager.h"

Player::Player() 
{

}

Player::Player(Vector pos)
{
	m_sprite = new Sprite("TEX_Player.png");
	setPosition(pos);

	m_speed = 900;
	m_grip = 12;
}

void Player::tick(float deltaTime)
{
	//	Iterating movement.
	m_desiredVelocity.x = m_controls.getInput().x * m_speed;

	iterateMovement(deltaTime);
	regulateBounce();

	//std::cout << "Input: " << input.x << ". Speed: " << speed << ". Delta time: " << deltaTime << "." << std::endl;
}

void Player::regulateBounce()
{
	auto halfWidth = m_width / 2;
	auto screenWidth = GameManager::instance()->screenWidth;

	if (m_position.x - halfWidth <= 0)
	{
		m_position.x = 0 + halfWidth;
		m_velocity.x = -m_velocity.x * m_bounceFactor;
	}
	else if (m_position.x + halfWidth >= screenWidth)
	{
		m_position.x = screenWidth - halfWidth;
		m_velocity.x = -m_velocity.x * m_bounceFactor;
	}
}