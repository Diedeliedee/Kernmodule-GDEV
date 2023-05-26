#include "Objects.h"

Object::Object(Shape shape, float xPos, float yPos)
{
	setPosition(xPos, yPos);
	this->shape = shape;		//	This creates a shallow copy.
}

void Object::setPosition(float xPos, float yPos) 
{
	position.x = xPos;
	position.y = yPos;
}

void Object::move(float xOffset, float yOffset)
{
	position.x += xOffset;
	position.y += yOffset;
}

void Object::draw(sf::RenderWindow& window)
{
	shape.draw(window, position.x, position.y);
}