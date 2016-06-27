#include "BomberMan.h"
#include <ctime>
#include <iostream>
using namespace std;
class Bomb
{
	private:
		Position *position;
		time_t time;
		int degree;
	public:
	Bomb();
	void setPosition(float x, float y, string direction);
	void setDegree(int degree);
	//Brick **Explosion(Wall ***wall, Brick **brick, int i, int j);
	//void setTime(time_t time);
	
	Position *getPosition();
	int getDegree();	
	//time_t getTime();

};
