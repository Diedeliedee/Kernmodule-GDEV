#pragma once
#include "Objects.h"
#include "PlayerInput.h"

class Player : public InputObject
{
private:
	PlayerInput m_controls;

public:
	Player();

	Player(Vector2 pos);

	void tick(float deltaTime);
};



class Enemy : public PhysicsObject
{
private:
public:
	Enemy();

	Enemy(float xPos, Vector2 vel);

	void tick(float deltaTime);
};