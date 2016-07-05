#ifndef __MANAGER_H__
#define __MANAGER_H__
#include "GUI.h"

class Manager
{
private:
	World *world;
	GUI *gui;

public:
	Manager();
	void new_world();
	bool run();
	bool handleGame();
};
#endif
