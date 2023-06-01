#include "Objects.h"

DynamicObject::DynamicObject() : Object()
{

}

DynamicObject::DynamicObject(Shape* shape, float xPos, float yPos, float xVel, float yVel) : Object(shape, xPos, yPos)
{
	velocity.x = xVel;
	velocity.y = yVel;
}

void DynamicObject::iterateMovement(float deltaTime)
{
	move(velocity.x * deltaTime, velocity.y * deltaTime);
}