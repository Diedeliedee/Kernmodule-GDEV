#pragma once
#include "Structs.h"

static class Math
{
public:
	static Vector getNetForce(Vector force, Vector velocity, float drag);

	static float dotProduct(Vector a, Vector b);

	static float lerp(float a, float b, float t);

	static float smoothLerp(float a, float b, float t);
};