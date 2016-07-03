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

	wall[15][15]->setIsempty(1);
	wall[15][14]->setIsempty(1);
	wall[14][15]->setIsempty(1);

	
	brick[6][3].setType("bomb");
	brick[9][5].setType("fire");		
	brick[13][1].setType("veloc");
	brick[3][6].setType("fire");
	brick[13][11].setType("fire");
	brick[7][11].setType("fire");
	brick[3][10].setType("bomb");
	brick[5][14].setType("veloc");
	brick[12][7].setType("bomb");
	brick[10][13].setType("bomb");
	
	
	wall[1][1]->setIsempty(1);
	wall[1][2]->setIsempty(1);
	wall[2][1]->setIsempty(1);
	wall[3][2]->setIsempty(1);
	wall[4][1]->setIsempty(1);
	wall[3][1]->setIsempty(1);	

	wall[15][15]->setIsempty(1);
	wall[15][14]->setIsempty(1);
	wall[14][15]->setIsempty(1);
	
	
	wall[1][7]->setIsempty(1);
	wall[1][11]->setIsempty(1);		
	wall[1][14]->setIsempty(1);
	wall[1][15]->setIsempty(1);
	wall[2][15]->setIsempty(1);
	
	wall[3][5]->setIsempty(1);
	wall[4][5]->setIsempty(1);
	wall[5][5]->setIsempty(1);
	wall[6][9]->setIsempty(1);
	wall[7][9]->setIsempty(1);
	
	wall[8][9]->setIsempty(1);
	wall[10][9]->setIsempty(1);
	wall[11][9]->setIsempty(1);
	wall[7][8]->setIsempty(1);
	wall[7][9]->setIsempty(1);
	
	wall[9][7]->setIsempty(1);
	
	wall[9][9]->setIsempty(1);
	wall[7][10]->setIsempty(1);
	wall[9][11]->setIsempty(1);
	wall[9][8]->setIsempty(1);
	wall[10][7]->setIsempty(1);
	
	wall[11][3]->setIsempty(1);
	wall[12][3]->setIsempty(1);
	wall[13][3]->setIsempty(1);
	wall[14][3]->setIsempty(1);
	wall[13][4]->setIsempty(1);
	
	wall[9][14]->setIsempty(1);
	wall[9][15]->setIsempty(1);
	wall[8][15]->setIsempty(1);
	wall[7][15]->setIsempty(1);
	//wall[13][4]->setIsempty(1);
	
	mWorldLength = 100.0f;
	mWorldWidth = 100.0f;
		
	upMan = new BomberMan();
	upMan->setPosition(32, 32);
	upMan->setFace("front");
	upMan->setVelocity(4);
	upMan->setLife(100);
		
	downMan = new BomberMan();
	downMan->setPosition(480, 480);
	downMan->setFace("front");
	downMan->setVelocity(4);
	downMan->setLife(100);
		
	upBomb = new Bomb[4];
	for(int i =0 ;i<4 ;i++)
	{
		upBomb[i].setPosition(0, 0, "front");
	}	
	//.........................*creat explotion*
	//upBomb->Explosion(wall);
	downBomb = new Bomb[4];
	for(int i =0 ;i<4 ;i++)
	{
		downBomb[i].setPosition(512, 512, "front");
	}
	//..............creat explotion ----  fateme--	
	//downBomb->Explosion(wall)
}
void World::setBrick(Brick **brick)
{
	this->brick = brick;
}
	
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

