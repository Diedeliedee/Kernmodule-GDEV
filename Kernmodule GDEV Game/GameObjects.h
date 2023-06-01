#pragma once
#include "Objects.h"
#include "PlayerInput.h"

class Player : public PhysicsObject
{
private:
	PlayerInput controls;

	int width = 100;
	int height = 20;

	float speed = 10;
	float mass = 10;
	float drag = 10;

public:
	Player(int xPos, int yPos);

	void tick(float deltaTime);
};