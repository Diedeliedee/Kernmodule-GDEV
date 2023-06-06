#pragma once
#include "SFML\Graphics.hpp"
#include "Structs.h"

class Shape
{
public:
	Bounds bounds;

	virtual void draw(sf::RenderWindow& window, Vector2 pos);
};



class Square : public Shape
{
protected:
	sf::RectangleShape m_shape;

public:
	Square(int w, int h);

	void draw(sf::RenderWindow& window, Vector2 pos) override;
};
