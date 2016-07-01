#ifndef __BOMBERMAN_H__
#define __BOMBERMAN_H__
#include "Bomb.h"
#include <iostream>
#include <string>

using namespace std;

class BomberMan
{
	private:
		int life;
		Position *position;
		float velocity;
		string face;
		int numberBomb;
	public:
		BomberMan();
		void setPosition(float x, float y);
		void setFace(string face);
		void setLife(int life);
		void setVelocity(float velocity);
	//	void set(int numbomb);
		Position *getPosition();

		int getLife();
	
		string getFace();

		float getVelocity();
	//	bool greeting(Wall *wall, bool flag);
	
		int setGift(Brick **brick, Bomb *bomb);
		int getNumBomb();
		
};
#endif
