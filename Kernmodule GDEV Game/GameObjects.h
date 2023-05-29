#pragma once
#include "Objects.h"

class Player : public PhysicsObject
{
private:
	int width = 100;
	int height = 20;

	float mass;
	float drag;

public:
	Player(int xPos, int yPos);
};