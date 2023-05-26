#include "Objects.h"

DynamicObject::DynamicObject(Shape shape, float xPos, float yPos, float xVel, float yVel) : Object(shape, xPos, yPos)
{
	velocity.x = xPos;
	velocity.y = yPos;
}

void DynamicObject::iterateMovement(float deltaTime)
{
	move(velocity.x * deltaTime, velocity.y * deltaTime);
}