#include "Objects.h"

PhysicsObject::PhysicsObject(Shape* shape, sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f accel) : DynamicObject(shape, pos.x, pos.y, vel.x, vel.y)
{
	acceleration.x = accel.y;
	acceleration.y = accel.y;
}

PhysicsObject::PhysicsObject(Shape* shape, sf::Vector2f pos, float ma, float dra) : DynamicObject(shape, pos.x, pos.y, 0, 0)
{
	mass = ma;
	drag = dra;
}

PhysicsObject::PhysicsObject(Shape* shape, float xPos, float yPos) : DynamicObject(shape, xPos, yPos, 0, 0)
{

}

void PhysicsObject::iterateMovement(float deltaTime)
{
	acceleration.x = (force.x -= (powf(velocity.x, 2) / 2 * drag)) / mass;
	acceleration.y = (force.y -= (powf(velocity.y, 2) / 2 * drag)) / mass;
	
	velocity.x += acceleration.x * deltaTime;
	velocity.y += acceleration.y * deltaTime;
	
	move(velocity.x * deltaTime, velocity.y * deltaTime);
}