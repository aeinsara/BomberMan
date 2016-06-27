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
				if(!texture1.loadFromFile("/home/aeinsara/Desktop/gameMenu/game_pos/q1.PNG")){}
				sf::Sprite texture1sprite1(texture1);
				texture1sprite1.setTexture(texture1);
				texture1sprite1.setPosition(wall[i][j]->getPosition()->x, wall[i][j]->getPosition()->y );
				window->draw(texture1sprite1);
			}
			
			if(wall[i][j] == &brick[i][j] && wall[i][j]->getIsempty() == 0){
			sf::Texture texture2;
			if(!texture2.loadFromFile("/home/aeinsara/Desktop/gameMenu/game_pos/q3.PNG")){}
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
		address[0] = "/home/aeinsara/Desktop/gameMenu/game_pos/manFront.png";
		address[1] = "/home/aeinsara/Desktop/gameMenu/game_pos/manRight.png";
		address[2] = "/home/aeinsara/Desktop/gameMenu/game_pos/manLeft.png";
		address[3] = "/home/aeinsara/Desktop/gameMenu/game_pos/manBack.PNG";
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
		address[0] = "/home/aeinsara/Desktop/gameMenu/game_pos/manFront.png";
		address[1] = "/home/aeinsara/Desktop/gameMenu/game_pos/manRight.png";
		address[2] = "/home/aeinsara/Desktop/gameMenu/game_pos/manLeft.png";
		address[3] = "/home/aeinsara/Desktop/gameMenu/game_pos/manBack.PNG";
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
	if(!texture.loadFromFile("/home/aeinsara/Desktop/gameMenu/game_pos/bomb.png")){}
	sf::Sprite texture1sprite(texture);
	texture1sprite.setTexture(texture);
	texture1sprite.setPosition(bomb->getPosition()->x, bomb->getPosition()->y);
	window->draw(texture1sprite);	
}
	
void GUI::show(World *world)
{
	window->clear(sf::Color(0,200,0));
	drawWall(world->getWall(), world->getBrick());
		
	drawBomberman(world->getupMan(), true);
	drawBomberman(world->getdownMan(), false);
		
	drawBomb(world->getupBomb());
	drawBomb(world->getdownBomb());
			
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

