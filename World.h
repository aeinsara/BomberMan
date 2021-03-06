#ifndef __WORLD_H__
#define __WORLD_H__
#include "BomberMan.h"

class World
{
private:
	Wall ***wall;
	Brick **brick;
	BomberMan *upMan;
	BomberMan *downMan;
	
	Bomb* upBomb;
	Bomb* downBomb;
	
	float mWorldLength;
	float mWorldWidth;

public:
	World();
	void setBrick(Brick **brick);
	
	Wall ***getWall();
	Brick **getBrick();
	
	BomberMan *getupMan();
	BomberMan *getdownMan();
	
	Bomb *getupBomb();
	Bomb *getdownBomb();
};
#endif
