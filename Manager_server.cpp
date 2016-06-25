#include "Manager_server.h"
#include "Server.h"
#include "SocketException.h"
#include <iostream>
#include <string>
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
	

	std::string server_data = " ";

	void Manager::handleGame()
	{
	
	//.....................................* server *.....................................
	
	std::string client_data ;
			
	ServerSocket new_sock;
	
	std::cout << "running....\n";

  try
    {
      // Create the socket
      ServerSocket server ( 30000 );


	  server.accept ( new_sock );

	  try
	    {
		  new_sock >> client_data;
		  new_sock << server_data;
	    }
	  catch ( SocketException& ) {}

	
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }
	
	std::cout << client_data << "\n";
		
	//.................................* end of server *......................................
	
		Position *posUp = world->getupMan()->getPosition();
		Position *posDown = world->getdownMan()->getPosition();
		
//............................................* Up Man *...........................................
    
    if(client_data == "Down")
    {
      bool a = interface(world->getWall(), world->getupMan()->getPosition(), world->getAry());
      if(a == true)
        posUp->y+=5;
        
		world->getupMan()->setFace("front");
        

    }
    
    if(client_data == "Up")
    {
      bool a2 = interface2(world->getWall(), world->getupMan()->getPosition(), world->getAry());
      if(a2 == true)
        posUp->y-=5;
        
 		world->getupMan()->setFace("back");
       
        
    }
    
    if(client_data == "Right")
    {
      bool a3 = interface3(world->getWall(), world->getupMan()->getPosition(), world->getAry());  
      if(a3 == true)        
        posUp->x+=5;  
        
		world->getupMan()->setFace("right");
                
    }
    
    if(client_data == "Left")
    {
      bool a4 = interface4(world->getWall(), world->getupMan()->getPosition(), world->getAry());
      if(a4 == true)
        posUp->x-=5;
          
		world->getupMan()->setFace("left");
          
    }
    
        
    if(client_data == "Bomb")
    {
      world->getupBomb()->setPosition(posUp->x, posUp->y);
      int i = getX(world->getWall(), world->getupMan()->getPosition());
      int j = getY(world->getWall(), world->getupMan()->getPosition());
      world->getupBomb()->Explosion(world->getAry(), i, j);
 //     std::cout « posUp->x « "   " « posUp->y « endl;
   //   std::cout « "i  " « i « "  j   " « j « endl;
        
   //   server_data = "Bomb";  
    }
      
      
    world->getupMan()->setPosition(posUp->x, posUp->y);		
		
		
		
		
	// ................................* Down man (server) *...................................
		
		
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				bool a = interface(world->getWall(), world->getdownMan()->getPosition(), world->getAry());
				if(a == true)
					posDown->y+=5;
					
				server_data = "Down";	
					
				world->getdownMan()->setFace("front");
			}
			
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				bool a2 = interface2(world->getWall(), world->getdownMan()->getPosition(), world->getAry());
				if(a2 == true)
					posDown->y-=5;
					
				server_data = "Up";
				
				world->getdownMan()->setFace("back");
			}
			
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				bool a3 = interface3(world->getWall(), world->getdownMan()->getPosition(), world->getAry());	
				if(a3 == true)				
					posDown->x+=5;
					
				server_data = "Right";
				
				world->getdownMan()->setFace("right");				
			}
			
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				bool a4 = interface4(world->getWall(), world->getdownMan()->getPosition(), world->getAry());
				if(a4 == true)
					posDown->x-=5;
				
				server_data = "Left";
				
				world->getdownMan()->setFace("left");	
				//int i = getX(world->getWall(), world->getupMan()->getPosition());
				//int j = getY(world->getWall(), world->getupMan()->getPosition());
				//cout<<"i  "<<i<<"  j   "<<j<<endl;	
			}
			
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				world->getupBomb()->setPosition(posDown->x, posDown->y);
				int i = getX(world->getWall(), world->getdownMan()->getPosition());
				int j = getY(world->getWall(), world->getdownMan()->getPosition());
				world->getupBomb()->Explosion(world->getAry(), i, j);
	//			cout<<posDown->x<<"   "<<posDown->y<<endl;
		//		cout<<"i  "<<i<<"  j   "<<j<<endl;
				
				server_data = "Bomb";	
			}
			
			else
			{
				server_data = " ";
			}
			
		world->getdownMan()->setPosition(posDown->x, posDown->y);		
		
	//.....................................* server *.....................................

	std::cout << "running....\n";

  try
    {
      // Create the socket
 //     ServerSocket server ( 30000 );


//	  server.accept ( new_sock );

	  try
	    {
		  new_sock >> client_data;
		  new_sock << server_data;
	    }
	  catch ( SocketException& ) {}

	
    }
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }
	
//	std::cout << client_data << "\n";
//	std::cout << server_data << "\n";
	
//	server_data = " ";
	
	//.................................* end of server *..................................
				
		
	}

