#pragma once
#include "SFML\Graphics.hpp"
#include "Math.h"

class Shape
{
public:
	virtual Vector2 getBounds();

	virtual void draw(sf::RenderWindow& window, Vector2 pos);
};



class Square : public Shape
{
protected:
	int m_width;
	int m_height;

	sf::RectangleShape m_shape;

public:
	Square(int w, int h);

	Vector2 getBounds() override;

	void draw(sf::RenderWindow& window, Vector2 pos) override;
};
