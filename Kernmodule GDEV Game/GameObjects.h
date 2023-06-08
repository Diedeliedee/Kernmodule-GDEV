#pragma once
#include "Objects.h"
#include "PlayerInput.h"

class Player : public InputObject
{
private:
	PlayerInput m_controls;

public:
	Player();

	Player(Vector pos);

	void tick(float deltaTime);
};



class Enemy : public PhysicsObject
{
public:
	int id;

	Enemy(int id);

	Enemy(int id, float xPos, Vector vel);

	void tick(float deltaTime);
};