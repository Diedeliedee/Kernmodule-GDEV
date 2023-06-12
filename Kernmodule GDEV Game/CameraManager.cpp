#include "CameraManager.h"

void CameraManager::startShake()
{
	m_state = 1;
}

void CameraManager::tick(float deltaTime)
{
	if (m_state <= 0) return;

	magnitude = m_state * m_shakeMagnitude;
	offset = Vector::random() * magnitude;

	//	Decreasing the magnitude over time.
	m_state -= m_decreaseAmount * deltaTime;
	if (m_state <= 0)
	{
		m_state = 0;
		offset = Vector(0, 0);
		magnitude = 0;
	}
}