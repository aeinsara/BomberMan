#include "Manager.h"
//#include "World.h"
bool interface(Wall **wall, Position * pos, int**ary)
{
	bool flag = false;
	for(int i=0 ; i<17 ;i++)
	for(int j=0 ; j<17 ;j++)
	{
		if((wall[i][j].getPosition()->y-10 <= pos->y &&   pos->y < (wall[i][j].getPosition()->y)+22 
		&& (wall[i][j].getPosition()->x )-10<= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+23 ))
		{
			//cout<<"position  "<<i<<"  "<<j<<"  wall   "<<wall[i][j].getPosition()->x<<"  "<<wall[i][j].getPosition()->y<<endl;
				if(ary[i+1][j] == 0 )
				flag = true;
		}
	}
	
		return flag;
}
bool interface2(Wall **wall, Position * pos, int**ary)
{
	bool flag = false;
	for(int i=0 ; i<17 ;i++)
	for(int j=0 ; j<17 ;j++)
	{
		if((wall[i][j].getPosition()->y-10 <= pos->y &&   pos->y < (wall[i][j].getPosition()->y)+22 
		&& (wall[i][j].getPosition()->x )-10<= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+23 ))
		{
			
				if(ary[i][j] == 0 )
				flag = true;
		}
	}
	
		return flag;
}
bool interface3(Wall **wall, Position * pos, int**ary)
{
	bool flag = false;
	for(int i=0 ; i<17 ;i++)
	for(int j=0 ; j<17 ;j++)
	{
		if(wall[i][j].getPosition()->y-23 <= pos->y &&   pos->y < (wall[i][j].getPosition()->y)+8 
		&& (wall[i][j].getPosition()->x )-10<= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+33 )
		{
			
				if(ary[i][j+1] == 0 )
				flag = true;
		}
	}
	
		return flag;
}
bool interface4(Wall **wall, Position * pos, int**ary)
{
	bool flag = false;
	for(int i=0 ; i<17 ;i++)
	for(int j=0 ; j<17 ;j++)
	{
		if(wall[i][j].getPosition()->y-23 <= pos->y &&   pos->y < (wall[i][j].getPosition()->y)+8 
		&& (wall[i][j].getPosition()->x )-5<= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+33 )
		{
			
				if(ary[i][j] == 0 )
				flag = true;
		}
	}
	
		return flag;
}
int getX(Wall **wall, Position * pos)
{
	for(int i=0 ; i<17 ;i++)
	for(int j=0 ; j<17 ;j++)
	{
		if(wall[i][j].getPosition()->x<= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+33 &&
		wall[i][j].getPosition()->y -13<= pos->y &&   pos->y < wall[i][j].getPosition()->y+19)
			{return i;
				
			}
	}
	
}
int getY(Wall **wall, Position * pos)
{
	for(int i=0 ; i<17 ;i++)
	for(int j=0 ; j<17 ;j++)
	{
		if(wall[i][j].getPosition()->y-13<= pos->y &&   pos->y < wall[i][j].getPosition()->y+19 &&
		wall[i][j].getPosition()->x<= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+33 )
				return j;
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
		}
		gui->close();
	}


	void Manager::handleGame()
	{
		Position *pos = world->getupMan()->getPosition();
		
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				bool a = interface(world->getWall(), world->getupMan()->getPosition(), world->getAry());
				if(a == true)
					pos->y+=5;
				world->getupMan()->setFace("front");
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				bool a2 = interface2(world->getWall(), world->getupMan()->getPosition(), world->getAry());
				if(a2 == true)
					pos->y-=5;
				world->getupMan()->setFace("back");
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				bool a3 = interface3(world->getWall(), world->getupMan()->getPosition(), world->getAry());	
				if(a3 == true)				
					pos->x+=5;
				world->getupMan()->setFace("right");				
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				bool a4 = interface4(world->getWall(), world->getupMan()->getPosition(), world->getAry());
				if(a4 == true)
					pos->x-=5;
				world->getupMan()->setFace("left");	
				//int i = getX(world->getWall(), world->getupMan()->getPosition());
				//int j = getY(world->getWall(), world->getupMan()->getPosition());
				//cout<<"i  "<<i<<"  j   "<<j<<endl;	
			}
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				world->getupBomb()->setPosition(pos->x, pos->y);
				int i = getX(world->getWall(), world->getupMan()->getPosition());
				int j = getY(world->getWall(), world->getupMan()->getPosition());
				world->getupBomb()->Explosion(world->getAry(), i, j);
				cout<<pos->x<<"   "<<pos->y<<endl;
				cout<<"i  "<<i<<"  j   "<<j<<endl;	
			}
			
		world->getupMan()->setPosition(pos->x, pos->y);
		
	}

