#include "GameObjects.h"
#include <iostream>

Player::Player(int xPos, int yPos) : PhysicsObject(new Square(width, height), sf::Vector2f(xPos, yPos), mass, drag)
{
	
}

void Player::tick(float deltaTime)
{
	sf::Vector2i input = controls.getInput();

	std::cout << position.x << std::endl;
	acceleration.x = input.x;
	iterateMovement(deltaTime);
}