#include "Structs.h"

Bounds::Bounds()
{

}


Bounds::Bounds(float w, float h)
{
	width = w;
	height = h;
}

Vector Bounds::getOffset(Vector pos, Vector off)
{
	return Vector(pos.x + off.x * (width / 2), pos.y + off.y * (height / 2));
}

bool Bounds::collidesWith(Bounds& other, Vector pos, Vector otherPos)
{
	Vector topLeft			= getOffset(pos, Vector(-1, -1));
	Vector bottomRight		= getOffset(pos, Vector(1, 1));

	Vector otherTopLeft		= other.getOffset(otherPos, Vector(-1, -1));
	Vector otherBottomRight	= other.getOffset(otherPos, Vector(1, 1));

	return	(bottomRight.x >= otherTopLeft.x && topLeft.x <= otherBottomRight.x) &&
			(bottomRight.y >= otherTopLeft.y && topLeft.y <= otherBottomRight.y);
}