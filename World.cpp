#include "World.h" 
World::World()
{
	ary = new int*[17];
	for(int i=0; i<17;i++)
		ary[i] = new int[17];

	for(int i=1 ;i<16 ;i++)
	{
		for(int j=1 ;j<16 ;j++)
		{
			if(j%2 == 0)
				ary[i][j] = 2;
			else
			{
				if(i%2 == 0)
					ary[i][j] = 1;
				else
					ary[i][j] = 2;
			}
		}
	}
		
	for(int i =0 ;i<17 ;i++)
		ary[0][i] = 1;
			
	for(int i =0 ;i<17 ;i++)
		ary[16][i] = 1;
			
	for(int i =0 ;i<17 ;i++)
		ary[i][0] = 1;
			
	for(int i =0 ;i<17 ;i++)
		ary[i][16] = 1;		
		
	wall = new Wall*[17];

	for(int i =0 ;i<17 ;i++)
	{
		wall[i] = new Wall[17];
	}
				
	int m=0;
	int n=0;
	
	for(int i =0 ;i<17 ;i++)
	{
		wall[0][i].getPosition()->x = m;
		wall[0][i].getPosition()->y = n;
		m+=33;
	}	
	m=0;
	
	for(int i =0 ;i<17 ;i++)
	{
		wall[16][i].getPosition()->x = m;
		wall[16][i].getPosition()->y = 512;
		m+=33;			
	}
	n =0;

	for(int i =0 ;i<17 ;i++)
	{
		wall[i][16].getPosition()->x = 528;
		wall[i][16].getPosition()->y = n;
		n+=32;			
	}
	n =0;
	
	for(int i =0 ;i<17 ;i++)
	{
		wall[i][0].getPosition()->x = 0;
		wall[i][0].getPosition()->y = n;
		n+=32;			
	}
	
	m = 33;
	n = 32;

	for(int i=1 ; i<16;i++)
	{
		for(int j=1; j<16;j++)
		{
			wall[i][j].getPosition()->x = m;
			wall[i][j].getPosition()->y = n;
			m+=33;
		}
		n+=32;
		m=33;
	}
	ary[1][1] = 0;
	ary[1][2] = 0;
	ary[2][1] = 0;
	ary[2][2] = 0;

///////////
	ary[15][15] = 0;
	ary[14][15] = 0;
	ary[14][14] = 0;
	ary[15][14] = 0;
//////////
	
	mWorldLength = 100.0f;
	mWorldWidth = 100.0f;
		
	upMan = new BomberMan();
	upMan->setPosition(34, 33);
	upMan->setFace("front");
	upMan->setVelocity(4);
	upMan->setLife(100);
		
	downMan = new BomberMan();
	downMan->setPosition(495, 470);
	downMan->setFace("front");
	downMan->setVelocity(4);
	downMan->setLife(100);
		
	upBomb = new Bomb();
	upBomb->setPosition(100, 100);
	upBomb->setDegree(1);
	upBomb->Explosion(ary,3, 3);
	//upBomb->setTime(Null);
		
	downBomb = new Bomb();
	downBomb->setPosition(570, 570);
	downBomb->setDegree(1);
	downBomb->Explosion(ary,3, 3);
	//downBomb->setTime(Null);

		
}
void ::World::setAry(int **ary)
{
	this->ary = ary;
}
int** World::getAry()
{
	return ary;
}
	
Wall** World::getWall()
{
	return wall;
}
		
BomberMan* World::getupMan()
{
	return upMan;
}
	
BomberMan* World::getdownMan()
{
	return downMan;
}
		
Bomb* World::getupBomb()
{
	return upBomb;
}

Bomb* World::getdownBomb()
{
	return downBomb;
}
