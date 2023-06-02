#include <algorithm>
#include <cstdint>
#include <iomanip>
#include <iostream>
#include "Objects.h"

InputObject::InputObject() : DynamicObject() 
{

}

InputObject::InputObject(Shape* shape, Vector2 pos, Vector2 vel) : DynamicObject(shape, pos, vel)
{

}

void InputObject::iterateMovement(float deltaTime)
{
	Vector2 steering = m_desiredVelocity - m_velocity;
	float gripFactor = m_grip * deltaTime;

	if (gripFactor > 1) gripFactor = 1;

	steering.x *= gripFactor;
	steering.y *= gripFactor;

	m_velocity.x += steering.x;
	m_velocity.y += steering.y;

	move(m_velocity * deltaTime);
}