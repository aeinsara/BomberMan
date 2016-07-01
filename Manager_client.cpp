#include "Manager_client.h"
#include "Client.h"
//#include <SFML/Audio.hpp>




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
	
	if(!menuMusic.openFromFile("/home/aeinsara/Desktop/game_gift/bombrMan_image/menu.ogg")){}
	if(!gameMusic.openFromFile("/home/aeinsara/Desktop/game_gift/bombrMan_image/play_game.ogg")){ }
	if(!aboutMusic.openFromFile("/home/aeinsara/Desktop/game_gift/bombrMan_image/play_game.ogg")){ }
	
	menuMusic.play();
	menuMusic.setLoop(true);	
	

		
	switch (gui->drawMenu())
	{
		case 1:
			menuMusic.stop();
			aboutMusic.stop();
			
			while (true)
			{

					
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
	
	
std::string client_data = " ";



time_t time_pause;
time_t time_winner;
time_t time_client[4];
time_t time_server[4];

//int counter;

void Manager::handleGame()
{
	Position *posUp = world->getupMan()->getPosition();
	Position *posDown = world->getdownMan()->getPosition();
	
	
	//std::string server_data;
	

		
	//....................................... * client *.....................................

		
	ClientSocket client_socket ( "172.18.208.192", 30000 );

	std::string server_data;
	
	client_socket << client_data;
	client_socket >> server_data;

	std::cout << "We received this response from the server : \t" << server_data << "\n";


	//...................................... * end of client *.................................
	

	//......................................* Down Man (server)*...............................
		
	if(server_data == "Down")
	{
		posDown->y += 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posDown, 1) == true)
					posDown->y -= 4;
			}		
		world->getdownMan()->setFace("front");
	}	
		
	if(server_data == "Up")
	{
		posDown->y -= 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posDown, 1) == true)
					posDown->y += 4;
			}
		world->getdownMan()->setFace("back");				
	}
		
	if(server_data == "Right")
	{
		posDown->x += 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posDown, 1) == true)
					posDown->x -= 4;
			}
		world->getdownMan()->setFace("right");									
	}
		
	if(server_data == "Left")
	{
		posDown->x -= 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posDown, 1) == true)
					posDown->x += 4;
			}
		world->getdownMan()->setFace("left");					
	}
		
				
	else if(server_data == "Bomb")
	{
		for(int i=0; i< world->getdownMan()->getNumBomb(); i++)
		{
			if(world->getdownBomb()[i].getPosition()->x == 512 && world->getdownBomb()[i].getPosition()->y == 512)
			{
				time_server[i] = time(0);
				world->getdownBomb()[i].setPosition(posDown->x, posDown->y, world->getdownMan()->getFace());
				break;
			}
		}
	}	
		
	for(int i = 0; i < 4 ;i++)
	{
		if(time(0) - time_server[i] >= 3)
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
			
			world->getdownBomb()[i].setPosition(512, 512, "front");		
		}
	}	
	
	world->getdownMan()->setGift(world->getBrick(), world->getdownBomb());	
				
	world->getdownMan()->setPosition(posDown->x, posDown->y);


	
				
	//....................................* Up Man (client)*......................................
		

	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		posUp->y += 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posUp, 1) == true)
					posUp->y -= 4;
			}		
		client_data = "Down";			
		world->getupMan()->setFace("front");
	}
	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		posUp->y -= 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posUp, 1) == true)
					posUp->y += 4;
			}					
		client_data = "Up";		
		world->getupMan()->setFace("back");
	}
			
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		posUp->x += 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posUp, 1) == true)
					posUp->x -= 4;
			}							
		client_data = "Right";					
		world->getupMan()->setFace("right");				
	}
			
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		posUp->x -= 4;
		for(int i=0 ;i<17 ;i++)	
			for(int j=0 ;j<17 ;j++)
			{
				if(world->getWall()[i][j]->greeting(posUp, 1) == true)
					posUp->x += 4;
			}			
		client_data = "Left";			
		world->getupMan()->setFace("left");	
				
	}
	
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{

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
		
	 
	//......................................... * client *...................................

	client_socket << client_data;
	client_socket >> server_data;

	//...................................... * end of client *...............................
	
	}

