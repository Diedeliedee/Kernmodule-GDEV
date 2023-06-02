#include <iostream>
#include <cmath>
#include "Math.h"

Vector2::Vector2()
{

}

Vector2::Vector2(float x, float y) 
{
	this->x = x;
	this->y = y;
	std::cout << "New Vector2 created! (" << this->x << ", " << this->y << ")." << std::endl;
}

float Vector2::magnitude()
{
	return sqrtf(sqrMagnitude());
}

float Vector2::sqrMagnitude()
{
	return x * x + y * y;
}

Vector2 Vector2::rounded()
{
	return Vector2(roundf(x), roundf(y));
}

Vector2 Vector2::normalized()
{
	float mag = magnitude();

	return Vector2(x / mag, y / mag);
}

sf::Vector2f Vector2::cast()
{
	return sf::Vector2f(x, y);
}
