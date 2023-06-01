#include "PlayerInput.h"

sf::Vector2i PlayerInput::getInput()
{
	dpad.x = 0;
	dpad.y = 0;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dpad.y++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dpad.y--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dpad.x--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dpad.x++;

	return dpad;
}