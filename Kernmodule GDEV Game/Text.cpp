#include "SFML/Graphics.hpp"
#include "Shapes.h"

Text::Text(sf::String text, int size)
{
	bounds = Bounds(size, size);
	m_font.loadFromFile("D:\\Projects\\HKU\\Jaar 1\\Blok 4\\Kernmodule GDEV ++\\[Git] Project\\Kernmodule GDEV Game\\Resources\\Fonts\\IVORG.ttf");
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
	m_text.setPosition(pos.cast());
	window.draw(m_text);
}