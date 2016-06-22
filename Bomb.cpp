#include "Bomb.h"
Bomb::Bomb(int power){
	pos = new Position();
	this->power = power;
}
	
Position* Bomb::getPosition(){
	return pos;
}
	
int Bomb::getPower(){
	return power;
}
	
void Bomb::setPosition(int x, int y){
	pos->x = x;
	pos->y = y;
}
	
void Bomb::setPower(int power){
	this->power = power;
}

void Bomb::setTime(){
	t = time(0);
}
time_t Bomb::getTime(){
	return t;
}
