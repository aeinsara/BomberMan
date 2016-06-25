#include <SFML/Graphics.hpp>
#include <SFML/Window/Export.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "Menu.h"

int main()
{
	sf::RenderWindow window (sf::VideoMode(587, 544), "* SFML *");
	Menu menu(window.getSize().x, window.getSize().y);

	sf::Texture texture;
    if(!texture.loadFromFile("/home/aeinsara/Desktop/menu/menu1.png")){}
    sf::Sprite sprite(texture);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
	window.draw(sprite);

	while (window.isOpen())
	{
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event :: KeyReleased :
			
				switch (event.key.code)
				{
				case sf::Keyboard :: Up :
					menu.moveUp();
					break;
					
				case sf::Keyboard :: Down :
					menu.moveDown();
					break;
					
				case sf::Keyboard :: Return :
					switch (menu.getPressedItem())
					{
					case 0:
						std::cout << "Play\n";
						break;
	
					case 1:
						std::cout << "Countinue\n";
						break;

					case 2:
						window.close();
						break;					
						
					}
					
					break;
				}
					
				break;
				
			case sf::Event :: Closed:
				window.close();
				break;
				
			}
		}
		
		window.clear();
		window.draw(sprite);
		menu.draw(window);
	
		window.display();
	}
	
	
	

}
