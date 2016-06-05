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
	Wall **wall;
	int **ary;
	float mWorldLength;
	float mWorldWidth;

public:
	World()
	{
		ary = new int*[17];
		for(int i=0; i<17;i++)
			ary[i] = new int[17];
		for(int i=1 ;i<16 ;i++)
		for(int j=1 ;j<16 ;j++)
		{
			if(j%2 == 0)
				ary[i][j] = 2;
			else
			{
				if(i%2 == 0)
					ary[i][j] = 1;
				else
					ary[i][j] = 2;
			}
		}
		for(int i =0 ;i<17 ;i++)
			ary[0][i] = 1;
		for(int i =0 ;i<17 ;i++)
			ary[16][i] = 1;
		for(int i =0 ;i<17 ;i++)
			ary[i][0] = 1;
		for(int i =0 ;i<17 ;i++)
			ary[i][16] = 1;		
		
		wall = new Wall*[17];
		for(int i =0 ;i<17 ;i++)
		{
			wall[i] = new Wall[17];
		}
				
		int m=0;
		int n=0;
		for(int i =0 ;i<17 ;i++)
		{
			wall[0][i].getPosition()->x = m;
			wall[0][i].getPosition()->y = n;
			m+=33;
		}	
		//n = 540;
		m=0;
		for(int i =0 ;i<17 ;i++)
		{
			wall[16][i].getPosition()->x = m;
			wall[16][i].getPosition()->y = 512;
			m+=33;			
		}
		n =0;
		for(int i =0 ;i<17 ;i++)
		{
			wall[i][16].getPosition()->x = 528;
			wall[i][16].getPosition()->y = n;
			n+=32;			
		}
		n =0;
		for(int i =0 ;i<17 ;i++)
		{
			wall[i][0].getPosition()->x = 0;
			wall[i][0].getPosition()->y = n;
			n+=32;			
		}
	
		m = 33;
		n = 32;

		for(int i=1 ; i<16;i++)
		{
			for(int j=1; j<16;j++)
			{
				wall[i][j].getPosition()->x = m;
				wall[i][j].getPosition()->y = n;
				m+=33;
			}
			n+=32;
			m=33;
		}
		mWorldLength = 100.0f;
		mWorldWidth = 100.0f;
	}

	int **getAry()
	{
		return ary;
	}
	Wall **getWall()
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
		monitorLength = 612;
		monitorWidth = 612;

		window = new sf::RenderWindow(sf::VideoMode(monitorLength, monitorWidth), "Tanks");
		
	}

	void drawTank(Wall **wall, int **ary)
	{
		
		sf::RectangleShape line(sf::Vector2f(20 , 30));

		for(int i=0;i<17 ;i++)
		for(int j=0 ;j<17;j++)
		{

			if(ary[i][j] == 1)
			{		
				sf::Texture texture1;
				if(!texture1.loadFromFile("/home/fateme/Desktop/images/q1.PNG")){}
				sf::Sprite texture1sprite1(texture1);
				texture1sprite1.setTexture(texture1);
				texture1sprite1.setPosition(wall[i][j].getPosition()->x, wall[i][j].getPosition()->y );
				window->draw(texture1sprite1);
			}
			
			if(ary[i][j] == 2){
			sf::Texture texture2;
			if(!texture2.loadFromFile("/home/fateme/Desktop/images/q3.PNG")){}
			sf::Sprite texture1sprite2(texture2);
			texture1sprite2.setTexture(texture2);
			texture1sprite2.setPosition(wall[i][j].getPosition()->x, wall[i][j].getPosition()->y );
			window->draw(texture1sprite2);}
			//line.setPosition(wall[i].getPosition()->x , wall[i].getPosition()->y);
		
		//	window->draw(line);
		}
	}


	void show(World *world)
	{
		window->clear(sf::Color(255,255,255));
		//window->Clear(sf::Color(200, 0, 0));
		drawTank(world->getWall(), world->getAry());
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
//g++ test1.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
//g++ -c test1.cpp
