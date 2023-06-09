#pragma once
#include "SFML\Graphics.hpp"
#include "Structs.h"

class Shape
{
public:
	Bounds bounds;

	Shape();

	virtual void draw(sf::RenderWindow& window, Vector pos);
};



class Square : public Shape
{
protected:
	sf::RectangleShape m_shape;

public:
	Square(int w, int h);

	Square& operator=(const Square& other);

	void draw(sf::RenderWindow& window, Vector pos) override;
};
