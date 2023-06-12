#include "SceneManager.h"
#include "GameManager.h"

SceneManager::SceneManager(Vector screenSize)
{
	m_leftCurtain	= new Curtain(screenSize, -1);
	m_rightCurtain	= new Curtain(screenSize, 1);

	m_statusText = new Text("", 72);
	m_detailsText = new Text("", 18);
}

SceneManager::~SceneManager()
{
	delete m_leftCurtain;
	delete m_rightCurtain;

	delete m_statusText;
	delete m_detailsText;
}

void SceneManager::setCurtainValue(float value)
{
	m_leftCurtain	->setState(value);
	m_rightCurtain	->setState(value);
	m_curtainValue	= value;
}

bool SceneManager::hasClosed(float deltaTime)
{
	auto hasClosed = false;

	if (m_curtainValue <= 0) return true;
	m_curtainValue -= (m_curtainSpeed * deltaTime);
	if (m_curtainValue <= 0)
	{
		hasClosed = true;
		m_curtainValue = 0;
	}
	setCurtainValue(m_curtainValue);
	return hasClosed;
}

bool SceneManager::hasOpened(float deltaTime)
{
	auto hasOpened = false;

	if (m_curtainValue >= 1) return true;
	m_curtainValue += (m_curtainSpeed * deltaTime);
	if (m_curtainValue >= 1)
	{
		hasOpened = true;
		m_curtainValue = 1;
	}
	setCurtainValue(m_curtainValue);
	return hasOpened;
}

void SceneManager::setEndScreen(sf::String status, sf::String details)
{
	m_statusText->setContent(status);
	m_detailsText->setContent(details);
}

void SceneManager::displayEndScreen() {
	m_canDrawEndScreen = true;
}

void SceneManager::draw(sf::RenderWindow& window)
{
	auto screenSize = Vector(GameManager::instance()->screenWidth, GameManager::instance()->screenHeight);

	if (m_canDrawEndScreen)
	{
		m_statusText->draw(window, Vector(screenSize.x / 2, screenSize.y / 4));
		m_detailsText->draw(window, screenSize / 2);
	}

	if (m_curtainValue < 1)
	{
		m_leftCurtain->draw(window);
		m_rightCurtain->draw(window);
	}
}