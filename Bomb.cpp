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
/*Brick** Bomb::Explosion(Wall **wall, Brick **brick, int i, int j)
{

	for( int m = i-degree; m <=i+degree ;m++)
	for( int n = j-degree; n <=j+ degree ;n++)
			if(wall[m][n] == &brick[m][n] && (m == i || n == j))
				brick[m][n].setType("null") ;
				
		
		return brick;	
}
*/
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
