#include "Manager_server.h"
#include "Server.h"
//#include <SFML/Audio.hpp>

//#include <string>



Manager::Manager()
{
	world = new World();
	gui = new GUI();
}

void Manager::run()
{
	bool running = true;
	
	//............................* run musics *................................
	
	sf::Music menuMusic;
	sf::Music gameMusic;
	sf::Music aboutMusic;
	
	if(!menuMusic.openFromFile("/home/samin/Desktop/firstNetwork/game_sara/bombrMan_image/menu.ogg")){}
	if(!gameMusic.openFromFile("/home/samin/Desktop/firstNetwork/game_sara/bombrMan_image/play_game.ogg")){ }
	if(!aboutMusic.openFromFile("/home/samin/Desktop/firstNetwork/game_sara/bombrMan_image/back.ogg")){ }
	
	menuMusic.play();
	menuMusic.setLoop(true);	
	

		
	switch (gui->drawMenu())
	{
		case 1:
			menuMusic.stop();
			aboutMusic.stop();
			while (true)
			{
				gui->show(world, 2);	
								
				while (gui->pollEvent())
				{
					if (gui->getEventType() == sf::Event::Closed)
					{
						gui->close();
					}
				}
			
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					aboutMusic.stop();
					run();
					break;
				}
			}
			break;
			
		case 0:	
			menuMusic.stop();
			gameMusic.play();     
			gui->show(world,0);
		
			while (running)
			{
				while (gui->pollEvent())
				{
					if (gui->getEventType() == sf::Event::Closed)
						running = false;
				}
				handleGame();
				gui->show(world, 0);
			}
			gui->close();
			break;
	}

	gui->show(world, 0);
}
	
	
std::string client_data;



time_t time_pause;
time_t time_winner;
time_t time_client[4];
time_t time_server[4];

std::string server_data = " ";

void Manager::handleGame()
{
	Position *posUp = world->getupMan()->getPosition();
	Position *posDown = world->getdownMan()->getPosition();
		
	//..........................................* server *.....................................
	std::string client_data;
	ServerSocket new_sock;

	std::cout << "running....\n";

    ServerSocket server ( 30000 );
  
	server.accept ( new_sock );
	  
	new_sock >> client_data;
	new_sock << server_data;
	

	//.........................................* end of server *......................................


	//...........................................* Up Man (client)*...............................
		
	if(client_data == "Down")
	{
		posUp->y += 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posUp, 1) == true)
					posUp->y -= 4;
			}		
		world->getupMan()->setFace("front");
	}	
		
	if(client_data == "Up")
	{
		posUp->y -= 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posUp, 1) == true)
					posUp->y += 4;
			}
		world->getupMan()->setFace("back");				
	}
		
	if(client_data == "Right")
	{
		posUp->x += 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posUp, 1) == true)
					posUp->x -= 4;
			}
		world->getupMan()->setFace("right");									
	}
		
	if(client_data == "Left")
	{
		posUp->x -= 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posUp, 1) == true)
					posUp->x += 4;
			}
		world->getupMan()->setFace("left");					
	}
		
				
	else if(client_data == "Bomb")
	{
		for(int i=0; i< world->getupMan()->getNumBomb(); i++)
		{
			if(world->getupBomb()[i].getPosition()->x == 0 && world->getupBomb()[i].getPosition()->y == 0)
			{
				time_client[i] = time(0);
				world->getupBomb()[i].setPosition(posUp->x, posUp->y, world->getupMan()->getFace());
				break;
			}
		}
	}	
		
	for(int i = 0; i < 4 ;i++)
	{
		if(time(0) - time_client[i] >= 3)
		{	
			if (world->getupBomb()[i].Explosion(world->getWall(), posUp) == false )
			{
				world->getupBomb()[i].setPosition(0, 0, "front");
				world->getupMan()->setPosition(577, 577);
				
				gui->show(world, 0);
				time_winner = time(0);
				
				while(true)
				{
					if (time(0) - time_winner >= 2)
						break;
				}
							
				while (true)
				{	
					gui->show(world,4);
					
					while (gui->pollEvent())
					{
						if (gui->getEventType() == sf::Event::Closed)
						{
							gui->close();
						}
					}
						
					if (time(0) - time_winner >= 6)
					{
						time_winner = time(0);
						run();
					}
				}
			}
			
			world->getupBomb()[i].setPosition(0, 0, "front");		
		}
	}	
	
	world->getupMan()->setGift(world->getBrick(), world->getupBomb());	
				
	world->getupMan()->setPosition(posUp->x, posUp->y);


				
	//....................................* Down Man (server)*......................................
		

	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		posDown->y += 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posDown, 1) == true)
					posDown->y -= 4;
			}		
		server_data = "Down";			
		world->getdownMan()->setFace("front");
	}
	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		posDown->y -= 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posDown, 1) == true)
					posDown->y += 4;
			}					
		server_data = "Up";		
		world->getdownMan()->setFace("back");
	}
			
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		posDown->x += 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posDown, 1) == true)
					posDown->x -= 4;
			}							
		server_data = "Right";					
		world->getdownMan()->setFace("right");				
	}
			
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		posDown->x -= 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posDown, 1) == true)
					posDown->x += 4;
			}			
		server_data = "Left";			
		world->getdownMan()->setFace("left");	
				
	}
	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		for(int i=0; i < world->getdownMan()->getNumBomb(); i++)
		{
			if(world->getdownBomb()[i].getPosition()->x == 512 && world->getdownBomb()[i].getPosition()->y == 512)
			{
				server_data = "Bomb";	
				time_client[i] = time(0);
				world->getdownBomb()[i].setPosition(posDown->x, posDown->y, world->getdownMan()->getFace());
				break;
			}
		}
	
	}
	
	else
	{
		server_data = " ";
	}

	for(int i = 0; i < 4 ;i++)
	{
		if(time(0) - time_client[i] >= 3)
		{	
			if (world->getdownBomb()[i].Explosion(world->getWall(), posDown) == false )
			{
				world->getdownBomb()[i].setPosition(512, 512, "front");
				world->getdownMan()->setPosition(577, 577);
				
				gui->show(world, 0);
				time_winner = time(0);
				
				while(true)
				{
					if (time(0) - time_winner >= 2)
						break;
				}
							
				while (true)
				{	
					gui->show(world,3);
					
					while (gui->pollEvent())
					{
						if (gui->getEventType() == sf::Event::Closed)
						{
							gui->close();
						}
					}
						
					if (time(0) - time_winner >= 6)
					{
						time_winner = time(0);
						run();
					}
				}
			}
			
			world->getdownBomb()[i].setPosition(512, 512, "front");		
		}
	}
		
	world->getdownMan()->setGift(world->getBrick(), world->getdownBomb());	
	
	world->getdownMan()->setPosition(posDown->x, posDown->y);

	//....................................* PAUSE *.....................................
				
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && 	(time(0) - time_pause >= 1))//////////////////////////
	{	
		time_pause = time(0);/////////////////////////////////////////////////////////////////
		while (true)
		{			
			gui->show(world,1);
					
			while (gui->pollEvent())
			{
				if (gui->getEventType() == sf::Event::Closed)
				{
					gui->close();
				}
			}
						
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && (time(0) - time_pause >= 1))
			{
				time_pause = time(0);
				break;
			}
		}			
	}

	//.........................................* end of PAUSE *...................................
		
		
	 
	//.....................................* server *.....................................

	new_sock >> client_data;
	new_sock << server_data;

	cout << server_data << "\n";	   

	//.................................* end of server *..................................
	
	}

