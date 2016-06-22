#include <time.h>
#include "Position.cpp"

class Bomb{
 private:
	Position* pos;
	int power;
	time_t t;
 public:
	bool burstFlag = 0; ///////////////////// for bursting
	
	Bomb(int power);
	
	Position* getPosition();
	int getPower();
	
	void setPosition(int x, int y);
	void setPower(int power);
	
	void setTime();
	time_t getTime();
}
