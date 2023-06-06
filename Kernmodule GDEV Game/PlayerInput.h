#pragma once
#include "Structs.h"

class PlayerInput
{
private:
	Vector2 dpad;

public:
	Vector2 getInput();
};