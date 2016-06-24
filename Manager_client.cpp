#include "Manager_client.h"
#include "Client.h"
#include "SocketException.h"
#include <iostream>
#include <string>

//#include "World.h"


bool interface(Wall **wall, Position * pos, int**ary)
{
	bool flag = false;
	for(int i=0 ; i<17 ;i++)
	{
		for(int j=0 ; j<17 ;j++)
		{
			if((wall[i][j].getPosition()->y <= pos->y &&   pos->y < (wall[i][j].getPosition()->y)+32 
				&& (wall[i][j].getPosition()->x )-10<= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+23 ))
			{
				//cout<<"position  "<<i<<"  "<<j<<"  wall   "<<wall[i][j].getPosition()->x<<"  "<<wall[i][j].getPosition()->y<<endl;
				if(ary[i+1][j] == 0 )
				flag = true;
			}
		}
	}
	
	return flag;
}
bool interface2(Wall **wall, Position * pos, int**ary)
{
	bool flag = false;
	for(int i=0 ; i<17 ;i++)
	{
		for(int j=0 ; j<17 ;j++)
		{
			if((wall[i][j].getPosition()->y <= pos->y &&   pos->y < (wall[i][j].getPosition()->y)+32 
				&& (wall[i][j].getPosition()->x )-10<= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+23 ))
			{
			
				if(ary[i][j] == 0 )
				flag = true;
			}
		}
	}
	
		return flag;
}

bool interface3(Wall **wall, Position * pos, int**ary)
{
	bool flag = false;
	for(int i=0 ; i<17 ;i++)
	{
		for(int j=0 ; j<17 ;j++)
		{
			if(wall[i][j].getPosition()->y-23 <= pos->y &&   pos->y < (wall[i][j].getPosition()->y)+8 
				&& (wall[i][j].getPosition()->x )-10<= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+33 )
			{
			
				if(ary[i][j+1] == 0 )
				flag = true;
			}
		}
	}
		return flag;
}

bool interface4(Wall **wall, Position * pos, int**ary)
{
	bool flag = false;
	for(int i=0 ; i<17 ;i++)
	{
		for(int j=0 ; j<17 ;j++)
		{
			if(wall[i][j].getPosition()->y-23 <= pos->y &&   pos->y < (wall[i][j].getPosition()->y)+8 
				&& (wall[i][j].getPosition()->x )-5<= pos->x &&   pos->x <= (wall[i][j].getPosition()->x)+33 )
			{
			
				if(ary[i][j] == 0 )
				flag = true;
			}
		}
	}
		return flag;
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
				
				//std::cout<<pos->x<<"   "<<pos->y<<endl<<"a   "<<a<<endl;
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			bool a2 = interface2(world->getWall(), world->getupMan()->getPosition(), world->getAry());
			if(a2 == true)
				pos->y-=5;
				
				std::cout<<pos->x<<"  "<<pos->y<<endl;
				
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bool a3 = interface3(world->getWall(), world->getupMan()->getPosition(), world->getAry());	
			if(a3 == true)				
				pos->x+=5;
				std::cout<<pos->x<<"  "<<pos->y<<endl;	
								
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bool a4 = interface4(world->getWall(), world->getupMan()->getPosition(), world->getAry());
			if(a4 == true)
				pos->x-=5;
				std::cout<<pos->x<<"  "<<pos->y<<endl;	
					
		}
		
			
		world->getupMan()->setPosition(pos->x, pos->y);
		
		//............................................ * client *...................................
		
		 try
		{

			ClientSocket client_socket ( "localhost", 30000 );

			std::string reply;

			try
			{
				client_socket << "Test message.";
				client_socket >> reply;
			}
			catch ( SocketException& ) {}

		std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;

		}
		catch ( SocketException& e )
		{
			std::cout << "Exception was caught:" << e.description() << "\n";
		}
	
	
		//............................................ * end of client *...................................	
}

