#include "Manager_client.h"
#include "Client.h"
//#include <SFML/Audio.hpp>

void Manager::new_world()
{
	world = new World();
}

Manager::Manager()
{
	world = new World();
	gui = new GUI();
}

sf::Music gameMusic;

bool Manager::run()
{
	bool running = true;

	//............................* run musics *................................

	sf::Music menuMusic;
	sf::Music aboutMusic;
	
	if(!menuMusic.openFromFile("/home/samin/Desktop/BomberManProject/bomberMan_client/bombrMan_image/menu.ogg")){}
	if(!gameMusic.openFromFile("/home/samin/Desktop/BomberManProject/bomberMan_client/bombrMan_image/play_game.ogg")){ }
	if(!aboutMusic.openFromFile("/home/samin/Desktop/BomberManProject/bomberMan_client/bombrMan_image/play_game.ogg")){ }
	
	gameMusic.stop();	
	menuMusic.play();
	menuMusic.setLoop(true);	
	

	
	switch (gui->drawMenu())
	{
		case 1:
			menuMusic.stop();
			aboutMusic.stop();
			
			while (true)
			{
				gui->show(world,2);
					
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
					gameMusic.play();     
					
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
					{
						running = false;
					}

				}
				if (handleGame() == false )
					return false;
				gui->show(world, 0);
			}
			gui->close();
			break;
	}

	gui->show(world, 0);
	
}
	
	
std::string client_data = " ";

std::string server_data;///////////////////////////////////////

time_t time_pause;
time_t time_winner;
time_t time_client[4];
time_t time_server[4];



bool Manager::handleGame()
{
	Position *posUp = world->getupMan()->getPosition();
	Position *posDown = world->getdownMan()->getPosition();
	
/*	//....................................... * client *.....................................
	
	ClientSocket client_socket ( "192.168.43.87", 30000 );
//	std::string server_data;

	client_socket << client_data;
	client_socket >> server_data;

	std::cout << "We received this response from the server : \t" << server_data << "\n";
	

*/	//......................................* Down Man (server)*...............................
		
	if(server_data == "Down")
	{
		world->getdownMan()->motion(world->getWall(), "down");
	}	
		
	if(server_data == "Up")
	{
		world->getdownMan()->motion(world->getWall(), "up");			
	}
		
	if(server_data == "Right")
	{
		world->getdownMan()->motion(world->getWall(), "right");										
	}
		
	if(server_data == "Left")
	{
		world->getdownMan()->motion(world->getWall(), "left");			
	}
		
				
	else if(server_data == "Bomb")
	{
		for(int i = 0; i < world->getdownMan()->getNumBomb(); i++)
		{
			if(world->getdownBomb()[i].getPosition()->x == 512 && world->getdownBomb()[i].getPosition()->y == 512)
			{
				time_server[i] = time(0);
				world->getdownBomb()[i].setPosition(posDown->x, posDown->y, world->getdownMan()->getFace());
				break;
			}
		}
	}	
	
	world->getdownMan()->setGift(world->getBrick(), world->getdownBomb());	
				
	world->getdownMan()->setPosition(posDown->x, posDown->y);
			
	//....................................* Up Man (client)*......................................
		

	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		world->getupMan()->motion(world->getWall(), "down");	
		client_data = "Down";			
	}
	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		world->getupMan()->motion(world->getWall(), "up");				
		client_data = "Up";		
	}
			
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		world->getupMan()->motion(world->getWall(), "right");	
		client_data = "Right";									
	}
			
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		world->getupMan()->motion(world->getWall(), "left");	
		client_data = "Left";			
				
	}
	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (time(0) - time_pause >= 1))
	{
		time_pause = time(0);
		for(int i=0; i < world->getupMan()->getNumBomb(); i++)
		{
			if(world->getupBomb()[i].getPosition()->x == 0 && world->getupBomb()[i].getPosition()->y == 0)
			{	
				client_data = "Bomb";
				time_client[i] = time(0);
				world->getupBomb()[i].setPosition(posUp->x, posUp->y, world->getupMan()->getFace());
				break;
			}
		}
	
	}
	
	else
	{
		client_data = " ";
	}

	for(int i = 0; i < 4 ;i++)
	{
		if(time(0) - time_client[i] >= 3)
		{	
			if (world->getupBomb()[i].Explosion(world->getWall(), posUp) == false )
			{
				world->getupBomb()[i].setPosition(0, 0, "front");
				world->getupMan()->setPosition(577, 577);
			
//				client_socket << "lose";
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
						client_data = " ";
						return false;
					}
				}
			}
			
			world->getupBomb()[i].setPosition(0, 0, "front");		
		}
	}
		
	world->getupMan()->setGift(world->getBrick(), world->getupBomb());	
	
	world->getupMan()->setPosition(posUp->x, posUp->y);

	//....................................* PAUSE *.....................................
				
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P) && 	(time(0) - time_pause >= 1))
	{	
		time_pause = time(0);
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
		
	 
/*	//......................................... * client *...................................
	
	client_socket << client_data;
	client_socket >> server_data;
	
*/	//...................................... * end of client *...............................
	
		for(int i = 0; i < 4 ;i++)
	{
		if(time(0) - time_server[i] >= 3)
		{	
			world->getdownBomb()[i].Explosion(world->getWall(), posDown);
			if(server_data == "lose")
		//	if (world->getdownBomb()[i].Explosion(world->getWall(), posDown) == false )
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
						return false;
					}
				}
			}
			
			world->getdownBomb()[i].setPosition(512, 512, "front");		
		}
	}	
	return true;
}

