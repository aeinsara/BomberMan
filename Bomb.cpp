#include "Bomb.h"

Bomb::Bomb()
{
	position = new Position();
	degree = 1;
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

void Bomb::setDegree()
{
	degree++;
	if(degree>=3)
		degree = 3;
}

Position* Bomb::getPosition()
{
	return position;
}

int Bomb::getDegree()
{
	return degree;
}


//.................................* Explosion *...................................

bool Bomb::Explosion(Wall ***wall, Position *manPosition)
{
	Brick *brick;
	bool explosion = true;
	string type ;
		
	int j = position->x/32;
	int i = position->y/32;

	//................* check up *................

	for(int m = i-1; m >= i-degree && m >= 0 && m <= 16; m--)
	{		
		brick = dynamic_cast <Brick*> (wall[m][j]);

		if(brick != NULL)
		{
			type = brick->getType();
			if(type != "fire" && type != "bomb" && type !="veloc")
			   brick->setType("f");
		}
		else
			break;
			
		if(brick != NULL && wall[m][j]->getIsempty() == 0)
		{
			wall[m][j]->setIsempty(1);

			if(type != "fire" && type != "bomb" && type !="veloc")
				brick->setType("f");

			break;
		}
		
		if(wall[m][j]->greeting(manPosition, 0) == true)	//dead Man
			explosion = false;			
	}

	//................* check down *................
		
	for(int m = i+1 ; m <= i+degree && m >= 0 && m <= 16 ; m++)
	{	
		brick = dynamic_cast <Brick*> (wall[m][j]);

		if(brick != NULL)
		{
			type = brick->getType();
			if(type != "fire" && type != "bomb" && type !="veloc")
				brick->setType("f");			
		}
		else
			break;
		
		if(brick != NULL &&  wall[m][j]->getIsempty() == 0)
		{		
			wall[m][j]->setIsempty(1);
			
			if(type != "fire" && type != "bomb" && type !="veloc")
				brick->setType("f");
			
			break;
		}
		
		if(wall[m][j]->greeting(manPosition, 0) == true)	//dead Man
			explosion = false;

	}	

	//................* check left *................	
	
	for(int m = j-1 ; m >= j-degree && m >= 0 && m <= 16; m--)
	{		
		brick = dynamic_cast <Brick*> (wall[i][m]);

		if(brick != NULL)
		{
			type = brick->getType();
			if(type != "fire" && type != "bomb" && type !="veloc")
				brick->setType("f");
		}
		
		else
			break;
			
		if(brick != NULL && wall[i][m]->getIsempty() == 0)
		{
			wall[i][m]->setIsempty(1);

			if(type != "fire" && type != "bomb" && type !="veloc")
				brick->setType("f");

			break;
		}
		
		if(wall[i][m]->greeting(manPosition,0) == true)		//dead Man
			explosion = false;
		
	}

	//................* check right *................
		
	for(int m = j+1 ; m <= j+degree && m >= 0 && m <= 16; m++)
	{		
		brick = dynamic_cast <Brick*> (wall[i][m]);

		if(brick != NULL)
		{
			type = brick->getType();
			if(type != "fire" && type != "bomb" && type !="veloc")
				brick->setType("f");
		}
		
		else
			break;
							
		if(brick != NULL && wall[i][m]->getIsempty() == 0)
		{
			wall[i][m]->setIsempty(1);
			
			if(type != "fire" && type != "bomb" && type !="veloc")
				brick->setType("f");

			break;
		}
		
		if(wall[i][m]->greeting(manPosition, 0) == true)	//dead Man
			explosion = false;
		
	}

	return explosion;	
}
//..............................* end of Explosion *...................................
