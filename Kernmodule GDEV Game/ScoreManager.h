#pragma once
#include "SFML/Graphics.hpp"
#include "Shapes.h"

class ScoreManager
{
private:

	Vector m_scorePosition = Vector(120, 60);
	Vector m_triesPosition = Vector(0, 0);

	Text* m_scoreDisplay = nullptr;
	Text* m_triesDisplay = nullptr;

	int m_triesOpacity = 0;
	float m_opacityDecreaseRate = 510;

public: 
	int scoreGoal = 25;
	int maxTries = 6;

	int score = 0;
	int triesLeft = maxTries;

	ScoreManager(Vector screenSize);

	~ScoreManager();

	void tick(float deltaTime);

	bool reachedScoreGoal(int addition);

	bool depletedAllTries(int omission);

	void draw(sf::RenderWindow& window);
};