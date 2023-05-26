#include <iostream>
#include "SFML\Graphics.hpp"
#include "Objects.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "I have no idea what I'm doing.");


#pragma region Test

	Object testObject(Square(50, 50), 100, 100);

#pragma endregion


	window.setFramerateLimit(60);   //  Setting a limit on the framerate.
	while (window.isOpen())         //  Main loop.
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
		testObject.draw(window);
		window.display();
	}
	return 0;
}