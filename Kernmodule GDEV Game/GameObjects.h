#pragma once
#include "Objects.h"
#include "PlayerInput.h"

class Player : public InputObject
{
private:
	PlayerInput controls;

	int width = 100;
	int height = 20;

public:
	Player(int xPos, int yPos);

	void tick(float deltaTime);
};