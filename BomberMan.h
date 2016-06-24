#ifndef __BOMBERMAN_H__
#define __BOMBERMAN_H__
#include "Position.h"
#include <iostream>
#include <string.h>
using namespace std;
class BomberMan
{
	private:
		int life;
		Position *position;
		float velocity;
		string face;
	public:
		BomberMan();
		void setPosition(float x, float y);
		
		void setFace(string face);

		void setLife(int life);

		void setVelocity(float velocity);
		
		Position *getPosition();

		int getLife();
	
		string getFace();

		float getVelocity();

		
};
#endif
