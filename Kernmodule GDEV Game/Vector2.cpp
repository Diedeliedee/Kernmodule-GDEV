#include <iostream>
#include <cmath>
#include "Structs.h"

Vector::Vector()
{

}

Vector::Vector(float x, float y)
{
	this->x = x;
	this->y = y;
	//std::cout << "New Vector2 created! (" << this->x << ", " << this->y << ")." << std::endl;
}

Vector::Vector(sf::Vector2f vec)
{
	x = vec.x;
	y = vec.y;
}

/*
Vector2::Vector2(const Vector2& other)
{
	x = other.x;
	y = other.y;
}
*/

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
