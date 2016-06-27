#include "Bomb.h"

Bomb::Bomb()
{
	position = new Position();
}

void Bomb::setPosition(float x, float y, string direction)
{
	switch(direction[0])
	{
		case 'f':
			y -= (int)y % 32;
			break;
		case 'b':
			if ((int)y % 32 != 0)
				y += (32 - ((int)y % 32));
			break;
		case 'l':
			if ((int)x % 32 != 0)
				x += (32 - ((int)x % 32));
			break;
		case 'r':
			x -= (int)x % 32;
			break;
	}
		
	position->x = x;
	position->y = y;
}

void Bomb::setDegree(int degree)
{
	this->degree = degree;
}

Position* Bomb::getPosition()
{
	return position;
}
int Bomb::getDegree()
{
	return degree;
}
/*time_t Bomb::getTime()
{
	return time;
}
*/
