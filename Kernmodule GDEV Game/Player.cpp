#include "GameObjects.h"

Player::Player(int xPos, int yPos) : PhysicsObject(new Square(width, height), sf::Vector2f(xPos, yPos), mass, drag)
{

}