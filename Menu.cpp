#include "Menu.h"

Menu :: Menu(float width, float height)
{
	/*sf::Texture texture;
    if(!texture.loadFromFile("/home/aeinsara/Desktop/menu/menu1.png")){}
    sf::Sprite sprite(texture);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
	window.draw(sprite);*/
	
	if (!font.loadFromFile("/home/aeinsara/Desktop/menu/B Nazanin+ Black.ttf"))
	{
		//std::cout << "ERROR !\n";
	}
	
	menu[0].setFont(font);
	menu[0].setCharacterSize(50);
	menu[0].setColor(sf::Color(243, 156, 18));
	menu[0].setString("     Play");
	menu[0].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEM + 1) * 1.5));
	
	menu[1].setFont(font);
	menu[1].setCharacterSize(50);
	menu[1].setColor(sf::Color :: Black);
	menu[1].setString("Continue");
	menu[1].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEM + 1) * 2));
	
	menu[2].setFont(font);
	menu[2].setCharacterSize(50);
	menu[2].setColor(sf::Color :: Black);
	menu[2].setString("     Exit");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAX_NUMBER_OF_ITEM + 1) * 2.5));
	
	selectedItemIndex = 0;
}
	
void Menu :: draw(sf::RenderWindow &window )
{
	//window.draw(sprite);
	
	for (int i = 0; i < MAX_NUMBER_OF_ITEM; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu :: moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setColor(sf::Color :: Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(sf::Color(243, 156, 18));	
	}
}

void Menu :: moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEM )
	{
		menu[selectedItemIndex].setColor(sf::Color :: Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(sf::Color(243, 156, 18));	
	}
}

int Menu :: getPressedItem()
{
	return selectedItemIndex;
}

Menu :: ~Menu()
{
		
}
