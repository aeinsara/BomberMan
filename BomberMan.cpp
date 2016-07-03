#include "BomberMan.h"

BomberMan::BomberMan()
{
	position = new Position();
	numberBomb = 1;
}
void BomberMan::setPosition(float x, float y)
{
	position->x = x;
	position->y = y;
}
void BomberMan::setFace(string face)
{
	this->face = face;
}
void BomberMan::setLife(int life)
{
	this->life = life;
}
void BomberMan::setVelocity(float velocity)
{
	this->velocity = velocity;
}
Position* BomberMan::getPosition()
{
	return position;
}
int BomberMan::getLife()
{
	return life;
}
string BomberMan::getFace()
{
	return face;
}
float BomberMan::getVelocity()
{
	return velocity;
}

int BomberMan::setGift(Brick **brick, Bomb *bomb)
{	
	for(int i=0 ;i<17 ;i++)
		for(int j=0 ;j<17 ;j++)
		{
			if(position->x+28 <= brick[i][j].getPosition()->x+32 && position->x >= brick[i][j].getPosition()->x &&
				position->y+28 <= brick[i][j].getPosition()->y+32 && position->y >= brick[i][j].getPosition()->y)
				{
					if(brick[i][j].getType() == "bomb")
					{
						brick[i][j].setType("null");
						numberBomb++;
					}
		
					if(brick[i][j].getType() == "fire")
					{
						brick[i][j].setType("null");
						for(int i =0; i<numberBomb ; i++)
							bomb[i].setDegree();
					}

					if(brick[i][j].getType() == "veloc")
					{
						brick[i][j].setType("null");
						velocity = 8;
					}
				}
			}

		return numberBomb;
}

int BomberMan::getNumBomb()
{
	return numberBomb;
}
void BomberMan::motion(Wall ***wall , string side)
{
	if(side == "down")
	{
		position->y += 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(wall[i][j]->greeting(position, 1) == true)
					position->y -= velocity;
			}
			face = "front";
	}
	else if(side == "up")
	{
		position->y -= 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(wall[i][j]->greeting(position, 1) == true)
					position->y +=  velocity;
			}
		face = "back";
	}
	else if(side == "right")
	{
		position->x += 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(wall[i][j]->greeting(position, 1) == true)
					position->x -= velocity;
			}
		face = "right";
	}
	else if(side == "left")
	{
		position->x -= 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(wall[i][j]->greeting(position, 1) == true)
					position->x +=  velocity;
			}
			face = "left";
				
	}
}


