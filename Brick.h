#include "Wall.cpp"

class Brick : public Wall
{
private:
	int type;
public:
	Brick() : Wall();
	void set_type(int type);
	int get_type();	
};
