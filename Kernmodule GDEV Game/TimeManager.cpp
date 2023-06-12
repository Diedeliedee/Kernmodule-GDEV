#include "TimeManager.h"

void TimeManager::tick(float deltaTime)
{
	if (!m_recover || timeScale >= 1) return;
	timeScale += m_recoveryRate * deltaTime;
	if (timeScale > 1) timeScale = 1;
}

float TimeManager::getScaledDeltaTime(float deltaTime)
{
	return deltaTime * timeScale;
}