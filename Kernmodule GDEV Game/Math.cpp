#include <cmath>
#include <iomanip>
#include <numbers>
#include "Math.h"
#include "Structs.h"

///	IMPORTANT: Does not work as intended. Requires more research.
Vector Math::getNetForce(Vector force, Vector velocity, float drag)
{
	auto fFriction	= ((velocity.squared() / 2) * drag);
	auto netForce	= force - fFriction;

	return netForce;
}

float Math::dotProduct(Vector a, Vector b)
{
	return a.x * b.x + a.y * b.y;
}

float Math::lerp(float a, float b, float t)
{
	return a + t * (b - a);
}

float Math::smoothLerp(float a, float b, float t)
{
	//	Rushed attempt at making an ease curve out of a cosine wave:
	auto perc = -(std::cos((t * 3.14f) / 1) / 2) + 0.5f;

	return lerp(a, b, perc);
}