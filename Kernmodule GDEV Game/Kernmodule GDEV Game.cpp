#include <iostream>
#include "SFML\Graphics.hpp"
#include "GameObjects.h"

int main()
{
	int screenWidth = 512;
	int screenHeight = 512;
	float frameRate = 60;
	float deltaTime = 1 / frameRate;

	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "I have no idea what I'm doing.");


#pragma region Test

	Player player(Vector2(screenWidth / 2, screenHeight * 0.75f));
	Enemy enemy (screenWidth / 2, Vector2(0, 0));

#pragma endregion


	window.setFramerateLimit(frameRate);	//  Setting a limit on the framerate.
	while (window.isOpen())					//  Main loop.
	{
		sf::Event event;

		//  Loop through all the events??
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();					//  Close window if X is pressed.
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();	//	Close window if escape is pressed.
		}

		//	Drawing.
		window.clear();
		player.tick(deltaTime);
		//enemy.iterateMovement(deltaTime);
		//enemy.draw(window);
		player.draw(window);
		window.display();
	}
	return 0;
}