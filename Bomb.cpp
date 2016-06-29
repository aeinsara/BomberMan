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

Wall*** Bomb::Explosion(Wall ***wall)
{
	Brick * b;
	int j = position->x/32;
	int i = position->y/32;
	for(int m = i-1 ; m>=i-degree ; m--)
	{		
		b= dynamic_cast <Brick*>(wall[m][j]);
		if(b != NULL && wall[m][j]->getIsempty() == 0)
		{
			wall[m][j]->setIsempty(1);
			break;
		}
		if(b == NULL)
			break;
	}
	for(int m = i+1 ; m<=i+degree ; m++)
	{		
		b= dynamic_cast <Brick*>(wall[m][j]);
		if(b != NULL &&  wall[m][j]->getIsempty() == 0)
		{		
			wall[m][j]->setIsempty(1);
			break;
		}
		if(b == NULL)
			break;		
	}	
	
	for(int m = j-1 ; m>=j-degree ; m--)
	{		
		b= dynamic_cast <Brick*>(wall[i][m]);
		if(b != NULL && wall[i][m]->getIsempty() == 0)
		{
			wall[i][m]->setIsempty(1);
			break;
		}
		if(b == NULL)
			break;
	}
	for(int m = j+1 ; m<=j+degree ; m++)
	{		
		b= dynamic_cast <Brick*>(wall[i][m]);
		if(b != NULL && wall[i][m]->getIsempty() == 0)
		{
			wall[i][m]->setIsempty(1);
			break;
		}
		if(b == NULL)
			break;
	}					
		
		return wall;	
}
