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
void Wall::setIsempty(bool kind)
{
	isempty = kind;
}
bool Wall::getIsempty()
{
	return isempty;
}

bool Wall::greeting(Position *position, bool flag)
{
	if((position->x +32 <= pos->x ||
		position->x >= pos->x+32  ||
		position->y >= pos->y+32  ||
		position->y +32 <= pos->y) && 
		isempty == 1 && flag == 0)
				return false;		
						
	if((((position->x +32 <= pos->x ||
		position->x >= pos->x+32  ||
		position->y >= pos->y+32  ||
		position->y +32 <= pos->y) && 
		isempty == 0) || isempty == 1) && flag == 1)
				return false;		
	
	return true;
	
}
