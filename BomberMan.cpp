#include <iostream>
#include <fstream>
#include "Vector.cpp"
class BomberMan
{
	private:
		int life;
		Vector *position;
		float velocity;
		string face;
	public:
		Man();
		void setPosition(float x, float y)
		{
			position->x = x;
			position->y = y;
		}
		void setFace(string face)
		{
			this->face = face;
		}
		void setLife(int life)
		{
			this->life = life;
		}
		void setVelocity(float velocity)
		{
			this->velocity = velocity;
		}
		
		Vector *getPosition()
		{
			return position;
		}
		int getLife()
		{
			return life;
		}
		string getFace()
		{
			return face;
		}
		float getVelocity()
		{
			return velocity;
		}
		
}

