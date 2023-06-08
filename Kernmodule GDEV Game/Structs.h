#pragma once
#include "SFML/Graphics.hpp"

class Vector
{
public:
	float x;
	float y;

	Vector();

	Vector(float x, float y);

	Vector(sf::Vector2f vec);

	//Vector2(const Vector2& other);

	float magnitude();

	float sqrMagnitude();

	Vector rounded();

	Vector normalized();

	sf::Vector2f cast();

	//	This should be an assignment operator, but this doesn't work.
	/*
	Vector2 operator=(const Vector2& other)
	{
		///	This is supposedly protection against a phenomenon called 'self assignment'.
		/// I suppose making an object a copy of itself is bad in some way, but I can't precisely figure out why.
		if (this == &other) return *this;

		return Vector2(other.x, other.y);
	}
	*/

	Vector operator+(const Vector& other)
	{
		return Vector(x + other.x, y + other.y);
	}

	Vector operator-(const Vector& other)
	{
		return Vector(x - other.x, y - other.y);
	}

	Vector operator*(const float other)
	{
		return Vector(x * other, y * other);
	}

	Vector operator/(const float other)
	{
		return Vector(x / other, y / other);
	}
};



class Bounds
{
public:
	float width;
	float height;

	Bounds();

	Bounds(float w, float h);

	Vector getOffset(Vector pos, Vector off);

	bool collidesWith(Bounds& other, Vector pos, Vector otherPos);
};