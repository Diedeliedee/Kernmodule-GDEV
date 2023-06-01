#include <iostream>
#include "GameObjects.h"

Player::Player(int xPos, int yPos) : DynamicObject()
{
	sprite = new Square(width, height);
	setPosition(xPos, yPos);
}

void Player::tick(float deltaTime)
{
	sf::Vector2f input = controls.getInput();

	velocity.x = input.x * speed;
	iterateMovement(deltaTime);

	//std::cout << "Input: " << input.x << ". Speed: " << speed << ". Delta time: " << deltaTime << "." << std::endl;
}