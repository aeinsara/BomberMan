#include "Brick.h"

Brick::Brick()
{
}
void Brick::setType(string type)
{
	this->type = type;
}
string Brick::getType()
{
	return type;
}
void Brick::setPosition(float x, float y)
{
	pos->x = x;
	pos->y = y;
}

Position* Brick::getPosition()
{
	return pos;
}
void Brick::setIsempty(bool kind)
{
	isempty = kind;
}
bool Brick::getIsempty()
{
	return isempty;
}
