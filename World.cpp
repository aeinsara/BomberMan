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
	
	mWorldLength = 100.0f;
	mWorldWidth = 100.0f;
		
	upMan = new BomberMan();
	upMan->setPosition(30, 20);
	upMan->setFace("right");
	upMan->setVelocity(4);
	upMan->setLife(100);
		
	downMan = new BomberMan();
	downMan->setPosition(570, 570);
	downMan->setFace("right");
	downMan->setVelocity(4);
	downMan->setLife(100);
		
	upBomb = new Bomb();
	downBomb = new Bomb();
		
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
