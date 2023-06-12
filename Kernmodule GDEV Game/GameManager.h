#pragma once
#include "EntityManager.h"
#include "ScoreManager.h"
#include "CameraManager.h"
#include "TimeManager.h"
#include "SceneManager.h"

class GameManager
{
private:
	//	To this day I'm not fully aware of all the downsides of using a singleton pattern.
	// Above that, I'm not aware of any downsides native to C++ of using this method.
	// For now the pros seem to outmatch the cons.
	static GameManager* m_instance;

	int m_state = 0;
	float m_stateTimer = 0;

public:
	//	Properties:
	int screenWidth					= 600;
	int screenHeight				= 800;
	float frameRate					= 60;
	sf::String windowName			= "EPIC DEFLECTION GAME 1.0!!";

	float deltaTime					= 1 / frameRate;

	//	References:
	sf::RenderWindow* activeWindow	= nullptr;

	//	Sub-managers:
	EntityManager* entities			= nullptr;	//	If this isn't a pointer, then the EntityManager will get created before the singleton reference.
	ScoreManager* score				= nullptr;
	CameraManager* camera			= nullptr;
	TimeManager* time				= nullptr;
	SceneManager* scene				= nullptr;

	//	Functions:
	GameManager();

	~GameManager();

	static GameManager* instance();

	void tick();

	void draw();

	//	Events:
	std::list<Enemy*>::iterator onEnemyCaught(Enemy& enemy);

	std::list<Enemy*>::iterator onEnemyEscaped(Enemy& enemy);

	void onWon();

	void onLost();
};