#include "Objects.h"

PhysicsObject::PhysicsObject() : DynamicObject()
{

}

PhysicsObject::PhysicsObject(Shape* shape, Vector2 pos, Vector2 vel) : DynamicObject(shape, pos, vel)
{

}

void PhysicsObject::iterateMovement(float deltaTime)
{
	m_acceleration.x = (m_force.x -= (powf(m_velocity.x, 2) / 2 * m_drag)) / m_mass;
	m_acceleration.y = (m_force.y -= (powf(m_velocity.y, 2) / 2 * m_drag)) / m_mass;
	
	m_velocity.x += m_acceleration.x * deltaTime;
	m_velocity.y += m_acceleration.y * deltaTime;
	
	move(m_velocity * deltaTime);
}