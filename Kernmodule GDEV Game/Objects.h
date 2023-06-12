#pragma once
#include <cmath>
#include "SFML/Graphics.hpp"
#include "Shapes.h"

class Object
{
protected:
	Vector m_position = Vector();

	/// Without this being a pointer, polymorphism will not work.
	Shape* m_sprite = nullptr;

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
	Vector m_velocity = Vector();

public:
	DynamicObject();

	DynamicObject(Shape* shape, Vector pos, Vector vel);

	virtual void iterateMovement(float deltaTime);
};



class PhysicsObject : public DynamicObject
{
protected:
	float m_mass = 1;
	float m_drag = 0;
	float m_gravity = 0;

	Vector m_acceleration = Vector();

public:
	PhysicsObject();

	PhysicsObject(Shape* shape, Vector pos, Vector vel);

	void addForce(Vector force);

	void iterateMovement(float deltaTime) override;
};

class InputObject : public DynamicObject
{
protected:
	float m_speed = 0;
	float m_grip = 0;

	Vector m_desiredVelocity = Vector();

public:
	InputObject();

	InputObject(Shape* shape, Vector pos, Vector vel);

	void iterateMovement(float deltaTime) override;
};