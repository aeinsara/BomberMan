#include "Manager_server.h"
#include "Server.h"
#include "SocketException.h"
#include <iostream>
#include <string>
//#include "World.h"
/*
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
}*/
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
	

	std::string server_data = " ";

	void Manager::handleGame()
	{
	
	//.....................................* server *.....................................
	
	std::string client_data ;
			
	ServerSocket new_sock;
	
	std::cout << "running....\n";

      // Create the socket
    ServerSocket server ( 30000 );

	server.accept ( new_sock );

	new_sock >> client_data;
	new_sock << server_data;

	std::cout << client_data << "\n";
		
	//.................................* end of server *......................................
	
		Position *posUp = world->getupMan()->getPosition();
		Position *posDown = world->getdownMan()->getPosition();
		
//............................................* Up Man *...........................................
    
    if(client_data == "Down")
    {
        posUp->y+=4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getupMan()->greeting(world->getWall()[i][j]) == true)
					posUp->y-=4;
			}
		world->getupMan()->setFace("front");
        

    }
    
    else if(client_data == "Up")
    {
        posUp->y-=4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getupMan()->greeting(world->getWall()[i][j]) == true)
					posUp->y+=4;
			}
        
 		world->getupMan()->setFace("back");
       
        
    }
    
    else if(client_data == "Right")
    {
 		posUp->x+=4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getupMan()->greeting(world->getWall()[i][j]) == true)
					posUp->x-=4;
			}		
				
		world->getupMan()->setFace("right");
                
    }
    
    else if(client_data == "Left")
    {
		posUp->x-=4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getupMan()->greeting(world->getWall()[i][j]) == true)
					posUp->x+=4;
			}					
          
		world->getupMan()->setFace("left");
          
    }
    
        
    else if(client_data == "Bomb")
    {
		world->getupBomb()->setPosition(posUp->x, posUp->y, world->getupMan()->getFace());
    }
      
      
    world->getupMan()->setPosition(posUp->x, posUp->y);		
		
		
		
		
	// ................................* Down man (server) *...................................
		
				
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		posDown->y+=4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getdownMan()->greeting(world->getWall()[i][j]) == true)
					posDown->y-=4;
			}
					
		server_data = "Down";	
		
		world->getdownMan()->setFace("front");
	}
			
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		posDown->y-=4;
			for(int i=0 ;i<17 ;i++)	
				for(int j=0 ;j<17 ;j++)
				{
					if(world->getdownMan()->greeting(world->getWall()[i][j]) == true)
						posDown->y+=4;
				}
						
		server_data = "Up";	
					
		world->getdownMan()->setFace("back");
	}
			
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{				
		posDown->x+=4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getdownMan()->greeting(world->getWall()[i][j]) == true)
					posDown->x-=4;
			}	
					
		server_data = "Right";	
					
		world->getdownMan()->setFace("right");				
	}
			
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
	posDown->x-=4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getdownMan()->greeting(world->getWall()[i][j]) == true)
					posDown->x+=4;
			}					
		server_data = "Left";					
						
		world->getdownMan()->setFace("left");		
	}
	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		world->getdownBomb()->setPosition(posDown->x, posDown->y, world->getdownMan()->getFace());
		
		server_data = "Bomb";							
	}

	else 
	{
		server_data = " ";							
	}		

			
	world->getdownMan()->setPosition(posDown->x, posDown->y);		
		
	//.....................................* server *.....................................

	std::cout << "running....\n";

	new_sock >> client_data;
	new_sock << server_data;

	//.................................* end of server *..................................
				
		
	}

