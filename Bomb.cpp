#include "Bomb.h"

Bomb::Bomb()
{
	position = new Position();
}
void Bomb::setPosition(float x, float y)
{
	position->x = x;
	position->y = y;
}
void Bomb::setDegree(int degree)
{
	this->degree = degree;
}
int** Bomb::Explosion(int **ary, int i, int j)
{

	for( int m = i-degree; m <=i+degree ;m++)
	for( int n = j-degree; n <=j+ degree ;n++)
			if(ary[m][n] == 2 && (m == i || n == j))
				ary[m][n] = 0;
				
		
		return ary;	
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
