#include "Wall.h"
#include "Bomb.h"

class World
{
private:
	Wall **wall;
	
	BomberMan *upMan;
	BomberMan *downMan;
	
	Bomb* upBomb(0);
	Bomb* downBomb(0);
	
	int **ary;
	float mWorldLength;
	float mWorldWidth;

public:
	World();

	int **getAry();
	
	Wall **getWall();
	
	BomberMan *getupMan();
	BomberMan *getdownMan();
	
	Bomb *getupBomb();
	Bomb *getdownBomb();
};
