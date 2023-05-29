#include "Objects.h"

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
}

void Object::move(float xOffset, float yOffset)
{
	position.x += xOffset;
	position.y += yOffset;
}

void Object::draw(sf::RenderWindow& window)
{
	sprite->draw(window, position.x, position.y);
}