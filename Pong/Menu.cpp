#include "Menu.h"
#include <iostream>
#include <SFML\Graphics.hpp>

Menu::Menu():play("Play"), quit("Quit")
{	
	background.loadFromFile("menu.png");
	sbackground.setTexture(background);

	play.setPosition(375, 200);
	quit.setPosition(375, 300);
}

void Menu::draw(sf::RenderWindow & r)
{
	r.draw(sbackground);
	r.draw(play);
	r.draw(quit);
	mouse=sf::Mouse::getPosition(r);
}

void Menu::handleEvent()
{	
	if(play.getPosition().x<=mouse.x && mouse.x<=play.getPosition().x+100 &&
	   play.getPosition().y<=mouse.y && mouse.y<=play.getPosition().y+50)
	{
		play.setCharacterSize(40);
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			changeState=true;
	}
	else
		play.setCharacterSize(30);
	if(quit.getPosition().x<=mouse.x&&mouse.x<=quit.getPosition().x+100 &&
		quit.getPosition().y<=mouse.y&&mouse.y<=quit.getPosition().y+50)
	{
		quit.setCharacterSize(40);
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			exit(0);
	}
	else
		quit.setCharacterSize(30);
}

void Menu::update()
{
}