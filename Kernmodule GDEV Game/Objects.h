#pragma once
#include <cmath>
#include "SFML/Graphics.hpp"
#include "Shapes.h"

class Object
{
protected:
	sf::Vector2f position;

	/// This needs to be a pointer, for when creating an object, we want polymorphism when passing in the sprite.
	/// Without this being a pointer, virtual functions will not work.
	/// Must do more research on preventing memory leaks with pointers.
	Shape* sprite;

public:
	Object(Shape* shape, float xPos, float yPos);

	~Object();

	void setPosition(float xPos, float yPos);

	void move(float xOffset, float yOffset);

	void draw(sf::RenderWindow& window);
};



class DynamicObject : public Object
{
protected:
	sf::Vector2f velocity;

public:
	DynamicObject(Shape* shape, float xPos, float yPos, float xVel, float yVel);

	virtual void iterateMovement(float deltaTime);
};



class PhysicsObject : public DynamicObject
{
protected:
	sf::Vector2f acceleration;
	sf::Vector2f force;
	float mass;
	float drag;

public:
	PhysicsObject(Shape* shape, sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f acceleration);

	PhysicsObject(Shape* shape, sf::Vector2f pos, float ma, float dr);

	PhysicsObject(Shape* shape, float xPos, float yPos);

	void iterateMovement(float deltaTime) override;
};