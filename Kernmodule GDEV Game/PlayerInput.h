#pragma once
#include "Structs.h"

class PlayerInput
{
private:
	Vector dpad = Vector();

public:
	Vector getInput();
};