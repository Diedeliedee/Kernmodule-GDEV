#pragma once
#include "Objects.h"
#include "PlayerInput.h"

class Player : public InputObject
{
private:
	const float m_width = 100;
	const float m_height = 20;

	PlayerInput m_controls;

public:
	Player();

	Player(Vector pos);

	void tick(float deltaTime);
};



class Enemy : public PhysicsObject
{
private:
	const float m_width = 10;
	const float m_height = 10;

public:
	int id;

	Enemy(int id);

	Enemy(int id, float xPos);

	void tick(float deltaTime);
};