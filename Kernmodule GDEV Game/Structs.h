#pragma once
#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <ctime>

class Vector
{
public:
	float x = 0;
	float y = 0;

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

	Vector multipliedScalars(const Vector& other);

	Vector clamped(float length);

	Vector rounded();

	Vector normalized();

	Vector squared();

	Vector inverted();

	sf::Vector2f cast();

	static Vector random();
};



class Bounds
{
public:
	float width = 0;
	float height = 0;

	Bounds();

	Bounds(float w, float h);

	Bounds(const Bounds& other);

	Bounds& operator=(const Bounds& other);

	Vector getOffset(Vector pos, Vector off);

	bool collidesWith(Bounds& other, Vector pos, Vector otherPos);
};