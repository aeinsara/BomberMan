#include "Brick.h"

Brick::Brick() : Wall()
{
	type = 0;
}
	
void Brick::set_type(int type)
{
	this->type = type;
}
	
int Brick::get_type()
{
	return type;
}	

