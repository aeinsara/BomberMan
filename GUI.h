#ifndef __GUI_H__
#define __GUI_H__
//#define SFML_KEYBOARD_HPP
//#include <iostream>
//#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Export.hpp>
#include <SFML/Window/Mouse.hpp>
#include "World.h"

#include "Menu.h"

using namespace sf;
class GUI
{
private:
	int monitorLength;
	int monitorWidth;

	sf::RenderWindow *window;
	sf::Event event;

public:
	GUI();
	
	void drawWall(Wall ***wall, Brick **brick);
	
	void drawBomberman(BomberMan *Man, bool iself);
	
	void drawBomb(Bomb* bomb);
	
	int drawMenu();	
	
	void drawPause(int flag);
	
	void drawAboat(int flag);

	//void brusting(Bomb* bomb);
	
	void show(World *world, int flag);

	bool pollEvent();
	
	sf::Event::EventType getEventType();

	void close();
};
#endif
