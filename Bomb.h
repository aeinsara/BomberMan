#include "BomberMan.h"
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
	void setDegree(int degree);
	int getDegree();	
	Wall ***Explosion(Wall ***wall);
	Position *getPosition();
	void drawExplosion();

};
