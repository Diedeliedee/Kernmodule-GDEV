#include <iostream>
#include "SFML\Graphics.hpp"
#include "GameManager.h"

int main()
{
	GameManager game = GameManager();
	sf::RenderWindow window(sf::VideoMode(game.screenWidth, game.screenHeight), game.windowName);

	game.activeWindow = &window;
	window.setFramerateLimit(game.frameRate);	//  Setting a limit on the framerate.

	while (window.isOpen())						//  Main loop.
	{
		sf::Event event;

		//  Loop through all the events??
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();					//  Close window if X is pressed.
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();	//	Close window if escape is pressed.
		}

		game.tick();
		game.draw();
	}
	return 0;
}