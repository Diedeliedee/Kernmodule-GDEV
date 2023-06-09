#pragma once
#include "SFML/Graphics.hpp"

class Vector
{
public:
	float x;
	float y;

	Vector();

	Vector(float x, float y);

	Vector(const Vector& other);

	Vector(const sf::Vector2f& other);

	Vector& operator=(const Vector& other);

	Vector operator+(const Vector& other);

	Vector operator-(const Vector& other);

	Vector operator*(const float other);

	Vector operator/(const float other);

	float magnitude();

	float sqrMagnitude();

	Vector rounded();

	Vector normalized();

	sf::Vector2f cast();
};



class Bounds
{
public:
	float width;
	float height;

	Bounds();

	Bounds(float w, float h);

	Bounds(const Bounds& other);

	Bounds& operator=(const Bounds& other);

	Vector getOffset(Vector pos, Vector off);

	bool collidesWith(Bounds& other, Vector pos, Vector otherPos);
};