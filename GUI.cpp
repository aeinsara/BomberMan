#include "GUI.h"
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#define SFML_KEYBOARD_HPP
#include <SFML/Window/Export.hpp>
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
	
	void drawWall(Wall **wall, int **ary)
	{
		
		sf::RectangleShape line(sf::Vector2f(20 , 30));

		for(int i=0;i<17 ;i++)
		{
			for(int j=0 ;j<17;j++)
			{

				if(ary[i][j] == 1)
				{		
					sf::Texture texture1;
					if(!texture1.loadFromFile("/home/fateme/Desktop/bomb/images/q1.PNG")){}
					sf::Sprite texture1sprite1(texture1);
					texture1sprite1.setTexture(texture1);
					texture1sprite1.setPosition(wall[i][j].getPosition()->x, wall[i][j].getPosition()->y );
					window->draw(texture1sprite1);
				}
			
				if(ary[i][j] == 2){
				sf::Texture texture2;
				if(!texture2.loadFromFile("/home/fateme/Desktop/bomb/images/q3.PNG")){}
				sf::Sprite texture1sprite2(texture2);
				texture1sprite2.setTexture(texture2);
				texture1sprite2.setPosition(wall[i][j].getPosition()->x, wall[i][j].getPosition()->y );
				window->draw(texture1sprite2);}
			}
		}
	}
	
	void drawBomberman(BomberMan *Man, bool iself)
	{
		if(iself == true)
		{		sf::Texture texture1;
				if(!texture1.loadFromFile("/home/fateme/Desktop/bomb/images/p3.png")){}
				sf::Sprite texture1sprite1(texture1);
				texture1sprite1.setTexture(texture1);
				texture1sprite1.setPosition(Man->getPosition()->x, Man->getPosition()->y);
				window->draw(texture1sprite1);
		}		
	}
	
	void drawBomb(Bomb* bomb)
	{
		sf::Texture texture1;
		if(!texture1.loadFromFile("/home/samin/Desktop/new_project/images/p13.png")){}
		sf::Sprite texture1sprite1(texture1);
		texture1sprite1.setTexture(texture1);
		texture1sprite1.setPosition(bomb->getPosition()->x, bomb->getPosition()->y);
		window->draw(texture1sprite1);	
	}	
				
	 ///////////////////////////////////////////////////////// just header
	void brusting(Bomb* bomb)
	{
		bomb->burstFlag = 0;
	} ///////////////////////////////////////////////////////////////////////// just header .... please write graphic part!!
	
	void show(World *world)
	{
		window->clear(sf::Color(255,255,255));
		drawWall(world->getWall(), world->getAry());
		
		drawBomberman(world->getupMan(), true);
		drawBomberman(world->getdownMan(), false);
		
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
