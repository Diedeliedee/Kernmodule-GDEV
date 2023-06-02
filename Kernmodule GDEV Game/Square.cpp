#include "SFML/Graphics.hpp"
#include "Shapes.h"

Square::Square(int w, int h)
{
	m_width = w;
	m_height = h;
	m_shape.setSize(Vector2(m_width, m_height).cast());
}

Vector2 Square::getBounds()
{
	return Vector2(m_width, m_height);
}

void Square::draw(sf::RenderWindow& window, Vector2 pos)
{
	m_shape.setPosition(Vector2(pos.x - m_width	/ 2, pos.y - m_height / 2).cast());
	window.draw(m_shape);
}