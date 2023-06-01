#include <iostream>
#include "Objects.h"

Object::Object()
{

}

Object::Object(Shape* shape, float xPos, float yPos)
{
	setPosition(xPos, yPos);
	sprite = shape;
}

Object::~Object()
{
	//	If the object is ever deleted, the sprite variable which is a reference to memory will get deleted as well.
	//	But the memory itself won't. Causing the Shape object to continue existing, without any reference to it.
	delete sprite;
}

void Object::setPosition(float xPos, float yPos) 
{
	position.x = xPos;
	position.y = yPos;
	std::cout << "Object has been set to: (" << position.x << "," << position.y << ") units." << std::endl;
}

void Object::move(float xOffset, float yOffset)
{
	setPosition(position.x + xOffset, position.y + yOffset);
	std::cout << "Object has been moved by: (" << xOffset << "," << yOffset << ") units." << std::endl;
}

void Object::draw(sf::RenderWindow& window)
{
	sprite->draw(window, position.x, position.y);
}