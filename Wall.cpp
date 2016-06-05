#include "Position.cpp"

class Wall
{
protected:
	Position *pos;
public:
	Wall()
	{
		pos = new Position();
	}
	
	void setPosition(float x, float y)
	{
		pos->x = x;
		pos->y = y;
	}
	
	Position *getPosition()
	{
		return pos;
	}

};
