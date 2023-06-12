#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
	m_scoreDisplay = new Text(sf::String("0"), m_fontSize);
}

ScoreManager::~ScoreManager()
{
	delete m_scoreDisplay;
}

void ScoreManager::updateScore(int addition)
{
	score += addition;

	//	sf::String only accepts an sf::Uint32 as applicable integer value.
	m_scoreDisplay->setContent(std::to_string(score));
}

void ScoreManager::draw(sf::RenderWindow& window)
{
	m_scoreDisplay->draw(window, m_displayPosition);
}
