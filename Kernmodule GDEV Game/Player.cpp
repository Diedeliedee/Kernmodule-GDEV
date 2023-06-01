#include <iostream>
#include "GameObjects.h"

Player::Player(int xPos, int yPos) : InputObject()
{
	sprite = new Square(width, height);
	setPosition(xPos, yPos);
	speed = 500;
	grip = 6;
}

void Player::tick(float deltaTime)
{
	sf::Vector2f input = controls.getInput();

	desiredVelocity.x = input.x * speed;
	iterateMovement(deltaTime);

	//std::cout << "Input: " << input.x << ". Speed: " << speed << ". Delta time: " << deltaTime << "." << std::endl;
}