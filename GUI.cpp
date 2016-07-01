#include "GUI.h"
#include <iostream>

GUI::GUI()
{
	monitorLength = 544;
	monitorWidth = 544;

	window = new sf::RenderWindow(sf::VideoMode(monitorLength, monitorWidth), "BomberMan");
		
}

//..............* draw walls *..................
	
void GUI::drawWall(Wall ***wall)
{
	for(int i=0;i<17 ;i++)
	{
		for(int j=0 ;j<17;j++)
		{
			Brick *brick = dynamic_cast<Brick*>(wall[i][j]);
			if(brick == NULL && wall[i][j]->getIsempty() == 0)
			{		
				sf::Texture texture1;
				if(!texture1.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/q1.PNG")){}
				sf::Sprite texture1sprite1(texture1);
				texture1sprite1.setTexture(texture1);
				texture1sprite1.setPosition(wall[i][j]->getPosition()->x, wall[i][j]->getPosition()->y );
				window->draw(texture1sprite1);
			}
			
			if(brick != NULL && wall[i][j]->getIsempty() == 0 && brick->getType() != "null"){
			sf::Texture texture2;
			if(!texture2.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/q3.PNG")){}
			sf::Sprite texture1sprite2(texture2);
			texture1sprite2.setTexture(texture2);
			texture1sprite2.setPosition(wall[i][j]->getPosition()->x, wall[i][j]->getPosition()->y );
			window->draw(texture1sprite2);}
		}
	}
}

//..............* draw gifts *..................

void GUI::drawGift(Brick **brick)
{
	for(int i =0 ;i<17 ;i++)
		for(int j =0 ;j<17 ;j++)
		{
			if(brick[i][j].getType()== "bomb")
			{
				sf::Texture texture;
				if(!texture.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/bombGift.png")){}
				sf::Sprite texture1sprite(texture);
				texture1sprite.setTexture(texture);
				texture1sprite.setPosition(brick[i][j].getPosition()->x, brick[i][j].getPosition()->y );
				window->draw(texture1sprite);
			}
			
			else if(brick[i][j].getType()== "fire")
			{
				sf::Texture texture;
				if(!texture.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/powerGift.png")){}
				sf::Sprite texture1sprite(texture);
				texture1sprite.setTexture(texture);
				texture1sprite.setPosition(brick[i][j].getPosition()->x, brick[i][j].getPosition()->y );
				window->draw(texture1sprite);				
			}
			
			else if(brick[i][j].getType()== "veloc")
			{
				sf::Texture texture;
				if(!texture.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/velocityGift.png")){}
				sf::Sprite texture1sprite(texture);
				texture1sprite.setTexture(texture);
				texture1sprite.setPosition(brick[i][j].getPosition()->x, brick[i][j].getPosition()->y );
				window->draw(texture1sprite);				
			}
			
			if(brick[i][j].getType()== "f")
			{
				sf::Texture texture;
				if(!texture.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/fire.PNG")){}
				sf::Sprite texture1sprite(texture);
				texture1sprite.setTexture(texture);
				texture1sprite.setPosition(brick[i][j].getPosition()->x, brick[i][j].getPosition()->y );
				window->draw(texture1sprite);
				brick[i][j].setType("null")  ;    
			}
		}
}

//..............* draw bombermans *..................
	
void GUI::drawBomberman(BomberMan *Man, bool iself)
{
	if(iself == true)
	{	
		sf::Texture texture1;
		string address[4];
		string face;
		address[0] = "/home/samin/Desktop/game_gift/bombrMan_image/manFront.png";
		address[1] = "/home/samin/Desktop/game_gift/bombrMan_image/manRight.png";
		address[2] = "/home/samin/Desktop/game_gift/bombrMan_image/manLeft.png";
		address[3] = "/home/samin/Desktop/game_gift/bombrMan_image/manBack.PNG";
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
		address[0] = "/home/samin/Desktop/game_gift/bombrMan_image/manFront.png";
		address[1] = "/home/samin/Desktop/game_gift/bombrMan_image/manRight.png";
		address[2] = "/home/samin/Desktop/game_gift/bombrMan_image/manLeft.png";
		address[3] = "/home/samin/Desktop/game_gift/bombrMan_image/manBack.PNG";
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

//..............* draw bombs *..................
		
void GUI::drawBomb(Bomb* bomb)
{
	for(int i =0 ;i<4 ;i++)
	{
		sf::Texture texture;
		if(!texture.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/bomb.png")){}
		sf::Sprite texture1sprite(texture);
		texture1sprite.setTexture(texture);
		texture1sprite.setPosition(bomb[i].getPosition()->x, bomb[i].getPosition()->y);
		window->draw(texture1sprite);	
	}
}

//.................* PAUSE *....................		
	
void GUI::drawPause(int flag)
{
	if (flag == 1)
	{
		sf::Texture texture;
		if(!texture.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/pause.png")){}
		sf::Sprite sprite(texture);
		sprite.setTexture(texture);
		sprite.setPosition(160, 200);
		window->draw(sprite);
		
	}
	
}		
				
//....................* Menu *.....................	

int GUI::drawMenu()
{	
	Menu menu(window->getSize().x, window->getSize().y);
	
	sf::Texture texture;
    if(!texture.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/menu1.png")){}
    sf::Sprite sprite(texture);
    sprite.setTexture(texture);
    sprite.setPosition(0, 0);
	window->draw(sprite);

	static bool flag = 0;
	
	while (window->isOpen())
	{
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
						if (flag == 1)
						{
							return 0;
						}
						flag = 1;

						break;
	
					case 1:
						return 1;

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
}
	
//..................* About *..................

void GUI::drawAbout(int flag)
{
	if (flag == 2)
	{
		sf::Texture texture;
		if(!texture.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/menu1.png")){}
		sf::Sprite sprite(texture);
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
		window->draw(sprite);
		
	}
	
}

//.......................................* end of About *.......................................


//.......................................* upMan Winer *......................................

void GUI::drawWinner(int flag)
{
	if (flag == 3)
	{
		sf::Texture texture;
		if(!texture.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/downMan_winner.png")){}
		sf::Sprite sprite(texture);
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
		window->draw(sprite);
		
	}

	else if (flag == 4)
	{
		sf::Texture texture;
		if(!texture.loadFromFile("/home/samin/Desktop/game_gift/bombrMan_image/upMan_winner.png")){}
		sf::Sprite sprite(texture);
		sprite.setTexture(texture);
		sprite.setPosition(0, 0);
		window->draw(sprite);
		
	}
	
}

//...................................* end of Winer *....................................

//........................................* Music *...............................................
/*
void GUI::playMusic()
{
  sf::Music music;
  if(!music.openFromFile("/home/aeinsara/Desktop/game_gift/bombrMan_image/gitar.ogg")){}
  music.play();
}
*/
//.......................................* end of Music *...................................

	
void GUI::show(World *world, int flag)
{
	window->clear(sf::Color(0,200,0));
	
	drawBomb(world->getupBomb());
	drawBomb(world->getdownBomb());
		
	drawWall(world->getWall());
	
	drawGift(world->getBrick());
	
	drawBomberman(world->getupMan(), true);
	drawBomberman(world->getdownMan(), false);
	
	drawPause(flag);
	
	drawAbout(flag);
	
	drawWinner(flag);
					
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
/*void GUI::mu()
{
   sf::SoundBuffer buffer;
    buffer.loadFromFile("/home/fateme/Desktop/1,mp3")
        
    // Create a sound instance and play it
    sf::Sound sound(buffer);
    sound.play();

}*/
void GUI::close()
{
	window->close();
}

