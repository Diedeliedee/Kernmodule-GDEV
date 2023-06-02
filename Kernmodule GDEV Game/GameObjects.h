#pragma once
#include "Objects.h"
#include "PlayerInput.h"

class Player : public DynamicObject
{
private:
	int m_width = 100;
	int m_height = 20;

	PlayerInput m_controls;

public:
	Player(Vector2 pos);

	void tick(float deltaTime);
};



class Enemy : public PhysicsObject
{
private:
	int m_width = 10;
	int m_height = 10;

public:
	Enemy(float xPos, Vector2 vel);
};