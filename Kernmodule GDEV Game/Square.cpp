#include "SFML/Graphics.hpp"
#include "Shapes.h"

Square::Square(int w, int h)
{
	bounds = Bounds(w, h);
	m_shape.setSize(Vector(w, h).cast());
}

Square& Square::operator=(const Square& other)
{
	bounds = other.bounds;
	m_shape.setSize(sf::Vector2f(bounds.width, bounds.height));
	return *this;
}

void Square::draw(sf::RenderWindow& window, Vector pos)
{
	m_shape.setFillColor(m_color);
	m_shape.setPosition(bounds.getOffset(pos, Vector(-1, -1)).cast());
	window.draw(m_shape);
}