#include "Game.h"
#include "Menu.h"
#include "Running.h"
#include <iostream>
Game::Game()
{
	//Initialize states and set the currentState
	std::cout<<"Loading...";
	states[MENU]=new Menu();
	states[RUNNING]=new Running();
	currentState=states[MENU];
	system("cls");
	std::cout<<"Score 5 points to win";
}

Game::~Game()
{
	//Release the memory
	delete states[MENU];
	delete states[RUNNING];
}

void Game::changeState(GameStates s)
{
	currentState = states[s]; //Point to the new state
}

void Game::draw( sf::RenderWindow & r) const
{
	currentState->draw(r);
}

void Game::update()
{
	if(currentState->needToChangeState())
		changeState(RUNNING);
	currentState->update();
}

void Game::handleEvent()
{
	currentState->handleEvent();
}