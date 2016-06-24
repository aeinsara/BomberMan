#include "Manager_server.h"
#include <iostream>
#include "Server.h"
#include "SocketException.h"
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
	
	
	
	//.....................................* server *.....................................
	
	std::string serverData = " ";
	std::string clientData ;
	
	ServerSocket new_sock;
/*
	std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server ( 30000 );


	  server.accept ( new_sock );

	  try
	    {
		  new_sock >> clientData;
		  new_sock << serverData;
	    }
	  catch ( SocketException& ) {}

	
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }
	*/
	//.................................* end of server *..................................
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			bool a = interface(world->getWall(), world->getupMan()->getPosition(), world->getAry());
			if(a == true)
				pos->y+=5;
				
				//std::cout<<pos->x<<"   "<<pos->y<<endl<<"a   "<<a<<endl;
				serverData = "Down";
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			bool a2 = interface2(world->getWall(), world->getupMan()->getPosition(), world->getAry());
			if(a2 == true)
				pos->y-=5;
				
//				std::cout<<pos->x<<"  "<<pos->y<<endl;	
				serverData = "Up";				
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			bool a3 = interface3(world->getWall(), world->getupMan()->getPosition(), world->getAry());	
			if(a3 == true)				
				pos->x+=5;
//				std::cout<<pos->x<<"  "<<pos->y<<endl;	
				serverData = "Right";										
		}
		
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			bool a4 = interface4(world->getWall(), world->getupMan()->getPosition(), world->getAry());
			if(a4 == true)
				pos->x-=5;
//				std::cout<<pos->x<<"  "<<pos->y<<endl;	
				serverData = "Left";						
		}
		
			
		world->getupMan()->setPosition(pos->x, pos->y);
		
		
		

	//.....................................* server *.....................................
/*	
	std::string serverData = " ";
	std::string clientData ;
	
	ServerSocket new_sock;
*/
	std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server ( 30000 );


	  server.accept ( new_sock );

	  try
	    {
		  new_sock >> clientData;
		  new_sock << serverData;
	    }
	  catch ( SocketException& ) {}

	
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }
	
	//.................................* end of server *..................................
				
}

