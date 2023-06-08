#include "Objects.h"

DynamicObject::DynamicObject() : Object()
{

}

DynamicObject::DynamicObject(Shape* shape, Vector pos, Vector vel) : Object(shape, pos)
{
	m_velocity = vel;
}

void DynamicObject::iterateMovement(float deltaTime)
{
	move(m_velocity * deltaTime);
}