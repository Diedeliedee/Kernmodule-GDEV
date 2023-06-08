#pragma once
#include <cmath>
#include "SFML/Graphics.hpp"
#include "Shapes.h"

class Object
{
protected:
	Vector m_position;

	/// This needs to be a pointer, for when creating an object, we want polymorphism when passing in the sprite.
	/// Without this being a pointer, virtual functions will not work.
	/// Must do more research on preventing memory leaks with pointers.
	Shape* m_sprite;

public:
	Object();

	Object(Shape* shape, Vector pos);

	~Object();

	bool collidesWith(Object& other);

	void setPosition(Vector pos);

	void move(Vector offset);

	void draw(sf::RenderWindow& window);
};



class DynamicObject : public Object
{
protected:
	Vector m_velocity;

public:
	DynamicObject();

	DynamicObject(Shape* shape, Vector pos, Vector vel);

	virtual void iterateMovement(float deltaTime);
};



class PhysicsObject : public DynamicObject
{
protected:
	float m_mass;
	float m_drag;

	Vector m_acceleration;
	Vector m_force;

public:
	PhysicsObject();

	PhysicsObject(Shape* shape, Vector pos, Vector vel);

	void iterateMovement(float deltaTime) override;
};

class InputObject : public DynamicObject
{
protected:
	float m_speed;
	float m_grip;

	Vector m_desiredVelocity;

public:
	InputObject();

	InputObject(Shape* shape, Vector pos, Vector vel);

	void iterateMovement(float deltaTime) override;
};