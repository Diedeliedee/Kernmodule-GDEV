#include "PlayerInput.h"

Vector2 PlayerInput::getInput()
{
	dpad = Vector2(0, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dpad.y++;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dpad.y--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dpad.x--;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dpad.x++;
	return dpad;
}