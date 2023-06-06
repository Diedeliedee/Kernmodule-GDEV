#include "Structs.h"

Bounds::Bounds()
{

}


Bounds::Bounds(float w, float h)
{
	width = w;
	height = h;
}

Vector2 Bounds::getOffset(Vector2 pos, Vector2 off)
{
	return Vector2(pos.x + off.x * (width / 2), pos.y + off.y * (height / 2));
}

bool Bounds::collidesWith(Bounds& other, Vector2 pos, Vector2 otherPos)
{
	Vector2 topLeft				= getOffset(pos, Vector2(-1, -1));
	Vector2 bottomRight			= getOffset(pos, Vector2(1, 1));

	Vector2 otherTopLeft		= other.getOffset(otherPos, Vector2(-1, -1));
	Vector2 otherBottomRight	= other.getOffset(otherPos, Vector2(1, 1));

	return	bottomRight.x >= otherTopLeft.x || topLeft.x <= otherBottomRight.x &&
			bottomRight.y >= otherTopLeft.y || topLeft.y <= otherBottomRight.y;
}