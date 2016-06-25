//#pragma ones

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEM 3

class Menu
{
private:
	int selectedItemIndex;
	
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEM]; 
	
public:
	Menu (float width, float height);
	~Menu();
	
	void draw(sf::RenderWindow &window );
	void moveUp();
	void moveDown();
	int getPressedItem();


};
