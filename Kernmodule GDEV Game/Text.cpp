#include "SFML/Graphics.hpp"
#include "Shapes.h"

Text::Text(sf::String text, int size)
{
	bounds = Bounds(size, size);
	m_font.loadFromFile("Resources\\Fonts\\IVORG.ttf");
	m_text = sf::Text(text, m_font, size);
}

Text& Text::operator=(const Text& other)
{
	bounds = other.bounds;
	m_text = other.m_text;
	return *this;
}

sf::String Text::setContent(sf::String contents)
{
	m_text.setString(contents);
	return contents;
}

void Text::draw(sf::RenderWindow& window, Vector pos)
{
	auto bounds = m_text.getGlobalBounds();

	m_text.setFillColor(m_color);
	m_text.setPosition(Vector(pos.x - bounds.width / 2, pos.y - bounds.height / 2).cast());
	window.draw(m_text);
}