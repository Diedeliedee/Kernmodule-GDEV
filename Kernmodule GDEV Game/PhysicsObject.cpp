#include "Objects.h"
#include "Math.h"

PhysicsObject::PhysicsObject() : DynamicObject()
{
	m_mass = 0;
	m_drag = 0;
}

PhysicsObject::PhysicsObject(Shape* shape, Vector pos, Vector vel) : DynamicObject(shape, pos, vel)
{
	m_mass = 0;
	m_drag = 0;
}

void PhysicsObject::addForce(Vector force)
{
	//force = Math::getNetForce(force, m_velocity, m_drag);
	m_acceleration = m_acceleration + (force / m_mass);
}

void PhysicsObject::iterateMovement(float deltaTime)
{
	//	Applying gravity to the velocity.
	m_velocity = m_velocity + (Vector(0, m_gravity) * deltaTime);

	//	Adding acceleration to the velocity.
	m_velocity = m_velocity + (m_acceleration * deltaTime);
	
	move(m_velocity * deltaTime);
}