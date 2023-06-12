#include "Objects.h"

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
	auto dragForce = ((m_velocity.squared() / 2) * m_drag);
	auto fFriction = Vector(0, -m_gravity).multipliedScalars(dragForce);
	auto netForce = force - fFriction;

	m_acceleration = m_acceleration + (netForce / m_mass);
}

void PhysicsObject::iterateMovement(float deltaTime)
{
	///	Applying gravity to the acceleration.
	m_acceleration = m_acceleration + Vector(0, m_gravity);

	//	Adding acceleration to the velocity.
	m_velocity = m_velocity + (m_acceleration * deltaTime);
	
	move(m_velocity * deltaTime);
}