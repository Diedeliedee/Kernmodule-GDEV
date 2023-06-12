#include "GameManager.h"
#include "ScoreManager.h"

ScoreManager::ScoreManager(Vector screenSize)
{
	auto scoreFontSize = 125;
	auto triesFontSize = 250;

	m_triesPosition = Vector(screenSize.x / 2, screenSize.y / 4);

	m_scoreDisplay = new Text(sf::String(std::to_string(score)), scoreFontSize);
	m_triesDisplay = new Text(sf::String(std::to_string(triesLeft)), triesFontSize);
}

ScoreManager::~ScoreManager()
{
	delete m_scoreDisplay;
	delete m_triesDisplay;
}

void ScoreManager::tick(float deltaTime)
{
	if (m_triesOpacity <= 0) return;
	m_triesOpacity -= m_opacityDecreaseRate * deltaTime;
	if (m_triesOpacity < 0) m_triesOpacity = 0;
}

bool ScoreManager::reachedScoreGoal(int addition)
{
	score += addition;
	m_scoreDisplay->setContent(std::to_string(score));	//	sf::String only accepts an sf::Uint32 as applicable integer value.
	return score >= scoreGoal;
}

bool ScoreManager::depletedAllTries(int ommision)
{
	triesLeft -= ommision;
	if (triesLeft < 0) triesLeft = 0;
	m_triesDisplay->setContent(std::to_string(triesLeft));
	m_triesOpacity = 255;
	return triesLeft <= 0;
}

void ScoreManager::draw(sf::RenderWindow& window)
{
	m_scoreDisplay->draw(window, m_scorePosition);

	if (m_triesOpacity <= 0) return;

	auto perc = (float)triesLeft / maxTries;

	m_triesDisplay->setColor(sf::Color(255, 255 * perc, 255 * perc, m_triesOpacity));
	m_triesDisplay->draw(window, m_triesPosition);
}
