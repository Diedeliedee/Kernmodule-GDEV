#pragma once
#include "SFML/Graphics.hpp"
#include "Shapes.h"

class ScoreManager
{
private:
	int m_fontSize = 100;
	Vector m_displayPosition = Vector(30, 30);

	Text* m_scoreDisplay = nullptr;

public: 
	int score;

	ScoreManager();

	~ScoreManager();

	void updateScore(int addition);

	void draw(sf::RenderWindow& window);
};