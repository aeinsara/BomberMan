#include "GUI.h"
#include <iostream>

GUI::GUI()
{
	monitorLength = 544;
	monitorWidth = 544;

	window = new sf::RenderWindow(sf::VideoMode(monitorLength, monitorWidth), "BomberMan");
		
}
	
void GUI::drawWall(Wall ***wall, Brick **brick)
{
	for(int i=0;i<17 ;i++)
	{
		for(int j=0 ;j<17;j++)
		{
			if(wall[i][j] != &brick[i][j] && wall[i][j]->getIsempty() == 0)
			{		
				sf::Texture texture1;
				if(!texture1.loadFromFile("/home/samin/Desktop/firstNetwork/server7/q1.PNG")){}
				sf::Sprite texture1sprite1(texture1);
				texture1sprite1.setTexture(texture1);
				texture1sprite1.setPosition(wall[i][j]->getPosition()->x, wall[i][j]->getPosition()->y );
				window->draw(texture1sprite1);
			}
			
			if(wall[i][j] == &brick[i][j] && wall[i][j]->getIsempty() == 0){
			sf::Texture texture2;
			if(!texture2.loadFromFile("/home/samin/Desktop/firstNetwork/server7/q3.PNG")){}
			sf::Sprite texture1sprite2(texture2);
			texture1sprite2.setTexture(texture2);
			texture1sprite2.setPosition(wall[i][j]->getPosition()->x, wall[i][j]->getPosition()->y );
			window->draw(texture1sprite2);}
		}
	}
}
	
void GUI::drawBomberman(BomberMan *Man, bool iself)
{
	if(iself == true)
	{	
		sf::Texture texture1;
		string address[4];
		string face;
		address[0] = "/home/samin/Desktop/firstNetwork/server7/manFront.png";
		address[1] = "/home/samin/Desktop/firstNetwork/server7/manRight.png";
		address[2] = "/home/samin/Desktop/firstNetwork/server7/manLeft.png";
		address[3] = "/home/samin/Desktop/firstNetwork/server7/manBack.PNG";
		if("front" == Man->getFace())
			face = address[0];
		if("right" == Man->getFace())
			face = address[1];
		if("left" == Man->getFace())
			face = address[2];
		if("back" == Man->getFace())
			face = address[3];		
		if(!texture1.loadFromFile(face)){}
		sf::Sprite texture1sprite1(texture1);
		texture1sprite1.setTexture(texture1);
		texture1sprite1.setPosition(Man->getPosition()->x, Man->getPosition()->y);
		window->draw(texture1sprite1);
	}	
		
	else 
	{
		sf::Texture texture1;
		string address[4];
		string face;
		address[0] = "/home/samin/Desktop/firstNetwork/server7/manFront.png";
		address[1] = "/home/samin/Desktop/firstNetwork/server7/manRight.png";
		address[2] = "/home/samin/Desktop/firstNetwork/server7/manLeft.png";
		address[3] = "/home/samin/Desktop/firstNetwork/server7/manBack.PNG";
		if("front" == Man->getFace())
			face = address[0];
		if("right" == Man->getFace())
			face = address[1];
		if("left" == Man->getFace())
			face = address[2];
		if("back" == Man->getFace())
			face = address[3];		
		if(!texture1.loadFromFile(face)){}
		sf::Sprite texture1sprite1(texture1);
		texture1sprite1.setTexture(texture1);
		texture1sprite1.setPosition(Man->getPosition()->x, Man->getPosition()->y);
		window->draw(texture1sprite1);			
		}	
}
	
void GUI::drawBomb(Bomb* bomb)
{
	sf::Texture texture;
	if(!texture.loadFromFile("/home/samin/Desktop/firstNetwork/server7/bomb.png")){}
	sf::Sprite texture1sprite(texture);
	texture1sprite.setTexture(texture);
	texture1sprite.setPosition(bomb->getPosition()->x, bomb->getPosition()->y);
	window->draw(texture1sprite);	

}



int GUI::drawMenu(){
	Menu menu(window->getSize().x, window->getSize().y);

	sf::Texture texture;
    if(!texture.loadFromFile("/home/samin/Desktop/firstNetwork/server7/menu1.png")){}
    sf::Sprite sprite(texture);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
	window->draw(sprite);
	
	static bool flag = 0;

	while (true)
	{
		sf::Event event;
		
		while (window->pollEvent(event))
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
						if(flag == 1)
							return 0;
						flag = 1;
						break;
	
					case 1:
						return 1;
						break;

					case 2:
						window->close();
						break;					
						
					}
					
					break;
				}
					
				break;
				
			case sf::Event :: Closed:
				window->close();
				break;
				
			}
		}
		
		window->clear();
		window->draw(sprite);
		menu.draw(*window);
		window->display();
	
	}
	return 0;
}	
//.......................................*end of MENU *.......................................


//.........................................* PAUSE *.........................................    
    
void GUI::drawPause(int flag)
{
  if (flag == 1)
  {
    sf::Texture texture;
    if(!texture.loadFromFile("/home/samin/Desktop/firstNetwork/server7/pause.png")){}
    sf::Sprite sprite(texture);
    sprite.setTexture(texture);
    sprite.setPosition(160, 200);
    window->draw(sprite);
    
  }
  
}
    
//......................................* end of PAUSE *.....................................


//......................................* About *......................................

void GUI::drawAboat(int flag)
{ 
  if (flag == 2)
  {
    sf::Texture texture;
    if(!texture.loadFromFile("/home/samin/Desktop/firstNetwork/server7/menu1.png")){}
    sf::Sprite sprite(texture);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
    window->draw(sprite);
    
  }
}

//......................................* end of About *......................................
	
void GUI::show(World *world, int flag)
{
	window->clear(sf::Color(0,200,0));
	drawWall(world->getWall(), world->getBrick());
	
	drawBomb(world->getupBomb());
	drawBomb(world->getdownBomb());		
	
	drawBomberman(world->getupMan(), true);
	drawBomberman(world->getdownMan(), false);
		
	drawPause(flag);
	drawAboat(flag);
				
	window->display();
}

bool GUI::pollEvent()
{
	if (window->pollEvent(event))
		return true;
}

sf::Event::EventType GUI::getEventType()
{
	return event.type;
}

void GUI::close()
{
	window->close();
}

