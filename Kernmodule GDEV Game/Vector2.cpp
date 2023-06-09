#include <iostream>
#include <cmath>
#include "Structs.h"

Vector::Vector()
{
	x = 0;
	y = 0;
}

Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
	//std::cout << "New Vector2 created! (" << this->x << ", " << this->y << ")." << std::endl;
}

Vector::Vector(const Vector& other)
{
	x = other.x;
	y = other.y;
}

Vector::Vector(const sf::Vector2f& other)
{
	x = other.x;
	y = other.y;
}

Vector& Vector::operator=(const Vector& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

Vector Vector::operator+(const Vector& other)
{
	return Vector(x + other.x, y + other.y);
}

Vector Vector::operator-(const Vector& other)
{
	return Vector(x - other.x, y - other.y);
}

Vector Vector::operator*(const float other)
{
	return Vector(x * other, y * other);
}

Vector Vector::operator/(const float other)
{
	return Vector(x / other, y / other);
}

float Vector::magnitude()
{
	return sqrtf(sqrMagnitude());
}

float Vector::sqrMagnitude()
{
	return x * x + y * y;
}

Vector Vector::rounded()
{
	return Vector(roundf(x), roundf(y));
}

Vector Vector::normalized()
{
	float mag = magnitude();

	return Vector(x / mag, y / mag);
}

sf::Vector2f Vector::cast()
{
	return sf::Vector2f(x, y);
}
