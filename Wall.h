#ifndef __WALL_H__
#define __WALL_H__
//#include "BomberMan.h"
#include "Position.h"
class Wall
{
protected:
	Position *pos;
	bool isempty;
public:
	Wall();
	virtual void setIsempty(bool kind);
	virtual bool getIsempty();
	virtual void setPosition(float x, float y);	
	virtual Position *getPosition();
	bool greeting(Position *position, bool flag);

};
#endif
