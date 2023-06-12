#pragma once
#include "Objects.h"
#include "PlayerInput.h"

class Player : public InputObject
{
private:
	const float m_width = 128;
	const float m_height = 32;

	const float m_bounceFactor = 0.5f;

	PlayerInput m_controls = PlayerInput();

public:
	Player();

	Player(Vector pos);

	void tick(float deltaTime);

	void regulateBounce();
};



class Enemy : public PhysicsObject
{
private:
	const int m_minSwitchInterval = 10;
	const int m_maxSwitchInterval = 50;
	const int m_maxForceRange = 400;

	float m_actingForce = 0;
	float m_chosenTime = 0;
	float m_timer = 0;

public:
	int id = 0;

	Enemy(int id);

	Enemy(int id, Vector pos);

	void tick(float deltaTime);

	void regulateBounce();

	void regulateForce(float deltaTime);

	bool escaped();
};