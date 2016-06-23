#ifndef __WALL_H__
#define __WALL_H__
#include "BomberMan.h"
class Wall
{
protected:
	Position *pos;
public:
	Wall();
	void setPosition(float x, float y);	
	Position *getPosition();
};
#endif
