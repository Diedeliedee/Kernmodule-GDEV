#pragma once
#include "Structs.h"

class PlayerInput
{
private:
	Vector dpad;

public:
	Vector getInput();
};