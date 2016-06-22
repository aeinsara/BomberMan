#include "Manager.h"
bool interface(Wall **wall, Vector * pos, int**ary)
{
  for(int i=0 ; i<17 ;i++)
  for(int j=0 ; j<17 ;j++)
  {
    if(wall[i][j].getPosition()->y <= pos->y &&   pos->y < (wall[i][j].getPosition()->y)+32 
    && wall[i][j].getPosition()->x <= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+33 )
    {
      cout«"position  "<<i«"  "«j«"  wall   "«wall[i][j].getPosition()->x«"  "«wall[i][j].getPosition()->y«endl;
        if(ary[i+1][j] == 0 )
        return true;
    }
      
    else 
      return false;
  }
}


Manager::Manager()
{
	world = new World();
	gui = new GUI();
}

void Manager::run()
{
	bool running = true;
	
	while (running)
	{
		while (gui->pollEvent())
		{
			if (gui->getEventType() == sf::Event::Closed)
				running = false;
		
		}
			handleGame();
			gui->show(world);
			//sf::sleep(sf::milliseconds(world->getCycleTime()));
	}
	gui->close();
}

void Manager::handleGame()
{
	Position *pos = world->getupMan()->getPosition();
		
		//................................................. motion ....................................................
		
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		bool a = interface(world->getWall(), world->getupMan()->getPosition(), world->getAry());
		pos->y+=4;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		pos->y-=4;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		pos->x+=4;
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		pos->x-=4;
	}
		/*if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				dir1+=4;
				handleGame2(dir, dir1);
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				handleGameRT(dir, dir1);
				if(b==0)
				handleGameRB(dir1, b);
			}*/
			
	world->getupMan()->setPosition(pos->x, pos->y);
		
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		world->upBomb->setPosition(world->getupBomberMan()->getPosition()->x, world->getupBomberMan()->getPosition()->y);
		world->upBomb->setTime();
		t0 = world->upBomb->getTime();																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																								
	}
	
	if(t0 > 2 && t < 3){
		world->upBomb = NULL;
		world->upBomb->burstFlag = 1;
	}		
}
