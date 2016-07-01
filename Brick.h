#ifndef __BRICK_H__
#define __BRICK_H__
#include "Wall.h"
#include <iostream>
#include <string>

using namespace std;
class Brick:public Wall
{
	private:
		string type;
	public:
		Brick();
		void setPosition(float x, float y);	
		Position *getPosition();
		void setIsempty(bool kind);
		bool getIsempty();
		void setType(string type);
		string getType();
};

#endif
