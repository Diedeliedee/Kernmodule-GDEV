#pragma once
#include "Objects.h"
#include "PlayerInput.h"

class Player : public InputObject
{
private:
	const float m_width = 150;
	const float m_height = 20;

	const float m_bounceFactor = 0.5f;

	PlayerInput m_controls = PlayerInput();

public:
	Player();

	Player(Vector pos);

	void tick(float deltaTime);

	void bounce();
};



class Enemy : public PhysicsObject
{
private:
	const float m_width = 20;
	const float m_height = 20;

	const int m_minSwitchInterval = 10;
	const int m_maxSwitchInterval = 50;
	const int m_maxForceRange = 400;

	float m_actingForce = 0;
	float m_chosenTime = 0;
	float m_timer = 0;

public:
	int id = 0;

	Enemy(int id);

	Enemy(int id, float xPos);

	void tick(float deltaTime);

	void bounce();
};