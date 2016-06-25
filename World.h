#ifndef __WORLD_H__
#define __WORLD_H__

#include "Wall.h"
//#include "Bomb.h"
class World
{
private:
	Wall **wall;
	
	BomberMan *upMan;
	BomberMan *downMan;
	
	Bomb* upBomb;
	Bomb* downBomb;
	
	int **ary;
	float mWorldLength;
	float mWorldWidth;

public:
	World();
	void setAry(int **ary);
	int **getAry();
	
	Wall **getWall();
	
	BomberMan *getupMan();
	BomberMan *getdownMan();
	
	Bomb *getupBomb();
	Bomb *getdownBomb();
};
#endif
