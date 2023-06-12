#pragma once
#include "GameObjects.h"
#include "Objects.h"
#include "Math.h"

class SceneManager
{
private:
	//	Curtain properties:
	Curtain* m_leftCurtain = nullptr;
	Curtain* m_rightCurtain = nullptr;

	float m_curtainSpeed = 1;
	float m_curtainValue = 1;

	//	End message properties:
	Text* m_statusText = nullptr;

	bool m_canDrawEndScreen = false;

public:
	SceneManager(Vector screenSize);

	~SceneManager();

	void tick(float deltaTime);

	void setCurtainValue(float value);

	bool hasClosed(float deltaTime);

	bool hasOpened(float deltaTime);

	void setEndScreen(sf::String status, sf::String details);

	void displayEndScreen();

	void draw(sf::RenderWindow& window);
};