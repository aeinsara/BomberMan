#ifndef __GUI_H__
#define __GUI_H__

#include <SFML/Graphics.hpp>
#include <SFML/Window/Export.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Audio.hpp>
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

	int drawMenu();
	
	void drawPause(int flag);
	
	void drawAbout(int flag);
	
	void drawWinner(int flag);
		
	void drawWall(Wall ***wall);
	
	void drawGift(Brick **brick);

	void drawBomberman(BomberMan *Man, bool iself);
	
	void drawBomb(Bomb* bomb);

	//void playMusic();
	
	void show(World *world, int flag);

	bool pollEvent();
	
	sf::Event::EventType getEventType();

	void close();
};
#endif
