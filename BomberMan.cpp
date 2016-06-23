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
		


