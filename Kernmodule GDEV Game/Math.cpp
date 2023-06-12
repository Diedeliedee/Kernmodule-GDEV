#include <cmath>
#include <iomanip>
#include <numbers>
#include "Math.h"

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