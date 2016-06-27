#include "World.h" 
World::World()
{
	wall = new Wall**[17];
	brick = new Brick*[17];
	
	for(int i=0 ;i<17 ;i++)
	{
		wall[i] = new Wall*[17];
		brick[i] = new Brick[17];
	}
	for(int i=0 ;i<17 ;i++)
	{
		wall[0][i] = new Wall();
		wall[i][0] = new Wall();
		wall[16][i] = new Wall();
		wall[i][16] = new Wall();
	}
	for(int i=1;i<16;i++)
	for(int j=1;j<16;j++)
	{
		if(j%2 == 1)
			wall[i][j] = new Wall();
		if(j%2 == 0 && i%2==0)
			wall[i][j] = new Wall();			
		else
		{
			wall[i][j] = new Brick();
			wall[i][j] = &brick[i][j];
		}
	}
	int m=0;
	int n=0;
	
	for(int i =0 ;i<17 ;i++)
	{
		wall[0][i]->setPosition(m, n);
		wall[16][i]->setPosition(m, 512);	
		wall[i][16]->setPosition(512, m);
		wall[i][0]->setPosition(0, m);	
		m+=32;
	}	

	m = 32;
	n = 32;

	for(int i=1; i<16;i++)
	{
		for(int j=1; j<16;j++)
		{
			wall[i][j]->setPosition(m, n) ;
			m+=32;
		}
		n+=32;
		m=32;
	}
	for(int i=0 ;i<17 ;i++)
	for(int j=0 ;j<17 ;j++)
		wall[i][j]->setIsempty(0);
	
	wall[1][1]->setIsempty(1);
	wall[1][2]->setIsempty(1);
	wall[2][1]->setIsempty(1);
	wall[14][15]->setIsempty(1);	
	wall[15][15]->setIsempty(1);
	wall[15][14]->setIsempty(1);
	

	brick[6][3].setType("gift");
	brick[9][5].setType("gift");		
	brick[13][1].setType("gift");
	brick[3][6].setType("gift");
	brick[13][11].setType("gift");
	brick[7][11].setType("gift");
	brick[3][10].setType("gift");
	brick[5][14].setType("gift");
	brick[12][7].setType("gift");
	brick[10][13].setType("gift");
	mWorldLength = 100.0f;
	mWorldWidth = 100.0f;
		
	upMan = new BomberMan();
	upMan->setPosition(32, 32);
	upMan->setFace("front");
	upMan->setVelocity(4);
	upMan->setLife(100);
		
	downMan = new BomberMan();
	downMan->setPosition(480, 480);
	downMan->setFace("right");
	downMan->setVelocity(4);
	downMan->setLife(100);
		
	upBomb = new Bomb();
	upBomb->setPosition(100, 100, "front");
	upBomb->setDegree(1);	
	
	downBomb = new Bomb();
	downBomb->setPosition(100, 100, "front");
	downBomb->setDegree(1);		
}
void World::setBrick(Brick **brick)
{
	this->brick = brick;
}
/*int** World::getAry()
{
	return ary;
}*/
	
Wall*** World::getWall()
{
	return wall;
}
Brick** World::getBrick()
{
	return brick;
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
