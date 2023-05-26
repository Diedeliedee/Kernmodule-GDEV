#include "Shapes.h"
#include "SFML/Graphics.hpp"

Square::Square(int w, int h)
{
	size.x = w;
	size.y = h;

	shape.setSize(size);
}

void Square::draw(sf::RenderWindow& window, int x, int y)
{
	shape.setPosition(x, y);
	window.draw(shape);
}