#include "Manager_client.h"
#include "Client.h"
//#include "SocketException.h"
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
	
////////////////////	
std::string client_data = " ";
//////////////////////

void Manager::handleGame()
{
	Position *posUp = world->getupMan()->getPosition();
	Position *posDown = world->getdownMan()->getPosition();
		
		//............................................ * client *...................................

		
		ClientSocket client_socket ( "172.18.208.192", 30000 );
		
		 //try
		//{
			std::string server_data;

			//try
			//{
				client_socket << client_data;
				client_socket >> server_data;
			//}
			//catch ( SocketException& ) {}

		std::cout << "We received this response from the server : \t" << server_data << "\n";

		//}
		//catch ( SocketException& e )
		//{
		//	std::cout << "Exception was caught:" << e.description() << "\n";
		//}
	
		//............................................ * end of client *...................................	


		//............................................* Down Man (server)*...........................................
		
		if(server_data == "Down")
		{
			bool a = interface(world->getWall(), world->getdownMan()->getPosition(), world->getAry());
			if(a == true)
				posDown->y+=5;

			world->getdownMan()->setFace("front");
		}
		
		if(server_data == "Up")
		{
			bool a2 = interface2(world->getWall(), world->getdownMan()->getPosition(), world->getAry());
			if(a2 == true)
				posDown->y-=5;

			world->getdownMan()->setFace("back");				
		}
		
		if(server_data == "Right")
		{
			bool a3 = interface3(world->getWall(), world->getdownMan()->getPosition(), world->getAry());	
			if(a3 == true)				
				posDown->x+=5;	

			world->getdownMan()->setFace("right");									
		}
		
		if(server_data == "Left")
		{
			bool a4 = interface4(world->getWall(), world->getdownMan()->getPosition(), world->getAry());
			if(a4 == true)
				posDown->x-=5;

			world->getdownMan()->setFace("left");					
		}
		
				
		if(server_data == "Bomb")
		{
			world->getdownBomb()->setPosition(posDown->x, posDown->y);
			int i = getX(world->getWall(), world->getdownMan()->getPosition());
			int j = getY(world->getWall(), world->getdownMan()->getPosition());
			world->getdownBomb()->Explosion(world->getAry(), i, j);
			cout<<posDown->x<<"   "<<posDown->y<<endl;
			cout<<"i  "<<i<<"  j   "<<j<<endl;
				
			//client_data = "Bomb";	
		}
			
			
		world->getdownMan()->setPosition(posDown->x, posDown->y);
				
		//....................................* Up Man (client)*......................................
		
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				bool a = interface(world->getWall(), world->getupMan()->getPosition(), world->getAry());
				if(a == true)
					posUp->y+=5;
					
				client_data = "Down";
					
				world->getupMan()->setFace("front");
			}
			
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				bool a2 = interface2(world->getWall(), world->getupMan()->getPosition(), world->getAry());
				if(a2 == true)
					posUp->y-=5;
					
				client_data = "Up";
					
				world->getupMan()->setFace("back");
			}
			
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				bool a3 = interface3(world->getWall(), world->getupMan()->getPosition(), world->getAry());	
				if(a3 == true)				
					posUp->x+=5;
					
				client_data = "Right";
					
				world->getupMan()->setFace("right");				
			}
			
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				bool a4 = interface4(world->getWall(), world->getupMan()->getPosition(), world->getAry());
				if(a4 == true)
					posUp->x-=5;
					
				client_data = "Left";
					
				world->getupMan()->setFace("left");	
				
			}
			
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				world->getupBomb()->setPosition(posUp->x, posUp->y);
				int i = getX(world->getWall(), world->getupMan()->getPosition());
				int j = getY(world->getWall(), world->getupMan()->getPosition());
				world->getupBomb()->Explosion(world->getAry(), i, j);
				cout<<posUp->x<<"   "<<posUp->y<<endl;
				cout<<"i  "<<i<<"  j   "<<j<<endl;
				
				client_data = "Bomb";	
			}
			
			else
			{
				client_data = " ";
			}
			
		world->getupMan()->setPosition(posUp->x, posUp->y);
		
		
		//............................................ * client *...................................
		// try
		//{

			//ClientSocket client_socket ( "172.18.208.192", 30000 );

			//std::string server_data;

			//try
			//{
				client_socket << client_data;
				client_socket >> server_data;
			//}
			//catch ( SocketException& ) {}

		//std::cout << "We send this response : \t " << client_data << "\n";;

		//}
		//catch ( SocketException& e )
		//{
			//std::cout << "Exception was caught:" << e.description() << "\n";
		//}
		

		//............................................ * end of client *...................................	

		
	}

