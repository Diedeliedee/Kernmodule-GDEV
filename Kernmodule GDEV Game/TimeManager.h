#pragma once

class TimeManager
{
private:
	bool m_recover = true;
	float m_desiredTimeScale = 1;
	float m_recoveryRate = 2;

public:
	float timeScale = 1;

	void tick(float deltaTime);

	float getScaledDeltaTime(float deltaTime);
};