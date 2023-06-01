#pragma once
#include "SFML/Graphics.hpp"

class PlayerInput
{
private:
	sf::Vector2i dpad;

public:
	sf::Vector2f getInput();
};