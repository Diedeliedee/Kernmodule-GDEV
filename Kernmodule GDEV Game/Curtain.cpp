#include "GameObjects.h"
#include "Math.h"

Curtain::Curtain(Vector screenSize, int side)
{
	auto halfScreenWidth = screenSize.x / 2;
	auto quarterScreenWidth = screenSize.x / 4;

	auto halfScreenHeight = screenSize.y / 2;

	m_closedXPos = halfScreenWidth + (side * quarterScreenWidth);
	m_openXPos = m_closedXPos + (side * halfScreenWidth);
	m_sprite = new Square(halfScreenWidth, screenSize.y);
	setPosition(Vector(halfScreenWidth + (side * quarterScreenWidth), halfScreenHeight));
}

void Curtain::setState(float value)
{
	setPosition(Vector(Math::smoothLerp(m_closedXPos, m_openXPos, value), m_position.y));
}