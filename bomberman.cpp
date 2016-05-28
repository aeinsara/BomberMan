#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#define SFML_KEYBOARD_HPP
#include <SFML/Window/Export.hpp>
using namespace std;


class Vector
{
public:
	float x;
	float y;
	
	Vector()
	{
		x = 0;
		y = 0;
		
	}
};

class Wall
{
private:
	Vector *position;
public:
	Wall()
	{
		position = new Vector();
	}
	void setPosition(float x, float y)
	{
		position->x = x;
		position->y = y;
	}
	Vector *getPosition()
	{
		return position;
	}
};
class World
{
private:
	Wall *wall;

	float mWorldLength;
	float mWorldWidth;

public:
	World()
	{

		wall = new Wall[40];
		int m = 40;
		int n = 40;
		for(int i=0 ;i<40 ;i++)
		{
			if(i%6 == 0){
				n+=150;
				m = 40;
			}
			wall[i].setPosition(m, n);
			m+=150;
		}

		mWorldLength = 100.0f;
		mWorldWidth = 100.0f;

		//mCycleTime = 20; 
	}


	Wall *getWall()
	{
		return wall;
	}
};

class GUI
{
private:
	int monitorLength;
	int monitorWidth;

	sf::RenderWindow *window;
	sf::Event event;

public:
	GUI()
	{
		monitorLength = 1200;
		monitorWidth = 800;

		window = new sf::RenderWindow(sf::VideoMode(monitorLength, monitorWidth), "Tanks");
	}

	void drawTank(Wall *wall, bool isLeft)
	{
		

		
		
		sf::RectangleShape line(sf::Vector2f(20 , 30));
		for(int i=0;i<40 ;i++)
		{
			sf::Texture texture1;
			if(!texture1.loadFromFile("/home/fateme/Pictures/7.jpeg")){}
			sf::Sprite texture1sprite1(texture1);
			texture1sprite1.setTexture(texture1);
			texture1sprite1.setPosition(wall[i].getPosition()->x, wall[i].getPosition()->y );
			window->draw(texture1sprite1);
			//line.setPosition(wall[i].getPosition()->x , wall[i].getPosition()->y);
		
		//	window->draw(line);
		}
	}


	void show(World *world)
	{
		window->clear();

		drawTank(world->getWall(), true);
		window->display();
	}

	bool pollEvent()
	{
		if (window->pollEvent(event))
			return true;
	}

	sf::Event::EventType getEventType()
	{
		return event.type;
	}

	void close()
	{
		window->close();
	}
};


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
			
			gui->show(world);
			//sf::sleep(sf::milliseconds(world->getCycleTime()));
		}
		gui->close();
	}

};


int main()
{
	Manager manager = Manager();
	manager.run();
	return 0;
}
