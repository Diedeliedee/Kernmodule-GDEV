#pragma once
#include "SFML\Graphics.hpp"

class Shape
{
public:
	virtual void draw(sf::RenderWindow& window, int x, int y);
};



class Square : public Shape
{
private:
	sf::RectangleShape shape;
	sf::Vector2f size;

public:
	Square(int w, int h);

	void draw(sf::RenderWindow& window, int x, int y) override;
};
