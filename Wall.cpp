#include "Wall.h"

Wall::Wall()
{
	pos = new Position();
}

void Wall::setPosition(float x, float y)
{
	pos->x = x;
	pos->y = y;
}

Position* Wall::getPosition()
{
	return pos;
}
