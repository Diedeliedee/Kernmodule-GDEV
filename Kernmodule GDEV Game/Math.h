#pragma once
#include "SFML/Graphics.hpp"

class Vector2
{
public:
	float x;
	float y;

	Vector2();

	Vector2(float x, float y);

	//Vector2(const Vector2& other);

	float magnitude();

	float sqrMagnitude();

	Vector2 rounded();

	Vector2 normalized();

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

	Vector2 operator+(const Vector2& other)
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 operator-(const Vector2& other)
	{
		return Vector2(x - other.x, y - other.y);
	}

	Vector2 operator*(const float other)
	{
		return Vector2(x * other, y * other);
	}

	Vector2 operator/(const float other)
	{
		return Vector2(x / other, y / other);
	}
};