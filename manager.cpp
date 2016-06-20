#include "Gui.cpp"

class Manager
{
private:
	World *world;
	GUI *gui;

public:
	Manager()
	{
		world = new World();
		gui = new GUI();
	}

	void run()
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


	void handleGame()
	{
		Vector *pos = world->getupMan()->getPosition();
		
			if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
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
		
	}
};
