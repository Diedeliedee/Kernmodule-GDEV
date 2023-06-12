#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Structs.h"

class CameraManager
{
private:
	float m_shakeMagnitude = 5;
	float m_decreaseAmount = 4;
	float m_state = 0;

public:
	float magnitude = 0;
	Vector offset = Vector(0, 0);

	void startShake();

	void tick(float deltaTime);
};