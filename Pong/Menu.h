#pragma once

#include "GameState.h"
#include <SFML/Graphics.hpp>

class Menu: public GameState
{
private:
	sf::Vector2i mouse;

	sf::Texture background;
	sf::Sprite sbackground;//for background images

	sf::Text play;
	sf::Text quit;
public:
	Menu();
	virtual ~Menu(){}

	virtual void draw(sf::RenderWindow & r);
	virtual void handleEvent();
	virtual void update();

};