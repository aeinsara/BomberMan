#include "BomberMan.h"

BomberMan::BomberMan()
{
	position = new Position();
}
void BomberMan::setPosition(float x, float y)
{
	position->x = x;
	position->y = y;
}
void BomberMan::setFace(string face)
{
	this->face = face;
}
void BomberMan::setLife(int life)
{
	this->life = life;
}
void BomberMan::setVelocity(float velocity)
{
	this->velocity = velocity;
}
Position* BomberMan::getPosition()
{
	return position;
}
int BomberMan::getLife()
{
	return life;
}
string BomberMan::getFace()
{
	return face;
}
float BomberMan::getVelocity()
{
	return velocity;
}
bool BomberMan::greeting(Wall *wall)
{
	if(((position->x +32 <= wall->getPosition()->x ||
		position->x >= wall->getPosition()->x+32  ||
		position->y >= wall->getPosition()->y+32  ||
		position->y +32 <= wall->getPosition()->y) && 
		wall->getIsempty() == 0) || wall->getIsempty() == 1 )
				return false;
	cout << "samin\n";
	cout<<"wall  "<< wall->getPosition()->x <<"   "<< wall->getPosition()->y<<endl;
	cout<<"man	"<<position->x<<"	"<<position->y<<endl;
	
	
	return true;
	
		
}	


