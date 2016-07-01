#include "Brick.h"
#include <ctime>
#include <iostream>

using namespace std;

class Bomb
{
private:
	Position *position;
	int degree;
public:
	Bomb();
	void setPosition(float x, float y, string direction);
	void setDegree();
	int getDegree();	
	bool Explosion(Wall ***wall, Position *manPosition);	
	Position *getPosition();
	


};
