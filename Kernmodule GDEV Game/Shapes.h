#pragma once
#include "SFML\Graphics.hpp"
#include "Structs.h"

class Shape
{
public:
	Bounds bounds = Bounds();

	Shape();

	virtual void draw(sf::RenderWindow& window, Vector pos);
};



class Square : public Shape
{
protected:
	sf::RectangleShape m_shape = sf::RectangleShape();

public:
	Square(int w, int h);

	Square& operator=(const Square& other);

	void draw(sf::RenderWindow& window, Vector pos) override;
};

class Text : public Shape
{
protected:
	sf::Text m_text = sf::Text();
	sf::Font m_font;;

public:
	Text(sf::String text, int size);

	Text& operator=(const Text& other);

	sf::String setContent(sf::String contents);

	void draw(sf::RenderWindow& window, Vector pos) override;
};
