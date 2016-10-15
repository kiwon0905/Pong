#include <SFML/Graphics.hpp>
#include "Game.h"

#include <ctime>
#include <random>

const short LENGTH=800;
const short WIDTH=600;

int main()
{
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(LENGTH, WIDTH), "Pong");

	Game game;
	while(window.isOpen())
	{
		sf::Event event;
		
		while(window.pollEvent(event))
		{
			if(event.type==sf::Event::Closed)
				window.close();
		}
		window.clear();
		game.handleEvent();
		game.update();
		game.draw(window);
		window.display();
	}
	return 0;
}