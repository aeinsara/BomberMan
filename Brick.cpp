#include "Wall.cpp"

class Brick : public Wall
{
private:
	int type;
public:
	Brick() : Wall()
	{
		type = 0;
	}
	
	void set_type(int type)
	{
		this->type = type;
	}
	
	int get_type()
	{
		return type;
	}
	
	
};
