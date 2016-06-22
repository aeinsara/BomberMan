#include "GUI.h"
#include "World.h"
class Manager
{
private:
	World *world;
	GUI *gui;

public:
	Manager();
	void run();
	void handleGame();
};
