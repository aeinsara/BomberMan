#include "World.h"

class GUI
{
private:
	int monitorLength;
	int monitorWidth;

	sf::RenderWindow *window;
	sf::Event event;

public:
	GUI();
	
	void drawWall(Wall **wall, int **ary);
	
	void drawBomberman(BomberMan *Man, bool iself);
	
	void drawBomb(Bomb* bomb);

	void brusting(Bomb* bomb);
	
	void show(World *world);

	bool pollEvent();
	
	sf::Event::EventType getEventType();

	void close();
};

