#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include "Objects.h"

InputObject::InputObject() : DynamicObject() 
{

}

InputObject::InputObject(Shape* shape, sf::Vector2f pos, float sp, float gr) : DynamicObject(shape, pos.x, pos.y, 0, 0)
{
	speed = sp;
	grip = gr;
}

void InputObject::iterateMovement(float deltaTime)
{
	sf::Vector2f steering = desiredVelocity - velocity;
	float gripFactor = grip * deltaTime;

	if (gripFactor > 1) gripFactor = 1;
	steering *= gripFactor;
	velocity += steering;
	move(velocity.x * deltaTime, velocity.y * deltaTime);
}