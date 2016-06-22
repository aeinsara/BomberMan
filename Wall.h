#include "Position.cpp"

class Wall
{
protected:
	Position *pos;
public:
	Wall();
	void setPosition(float x, float y);	
	Position *getPosition();
};
