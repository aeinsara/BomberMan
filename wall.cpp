#include <iostream>
#include "BomberMan.cpp"
using namespace std;

class Wall
{
private:
	Vector *position;
public:
	Wall()
	{
		position = new Vector();
	}
	void setPosition(float x, float y)
	{
		position->x = x;
		position->y = y;
	}
	Vector *getPosition()
	{
		return position;
	}
};
