#pragma once

#include "GameState.h"
#include <SFML\Graphics.hpp>

class GameState;

class Game
{
private:
	GameState * states[NUMGAMESTATES];		//Array of pointers to 2 GameStates->Menu=0, and Running=1
	GameState * currentState;	//Pointer to Current State
public:
	Game();
	~Game();

	//No copy constructor, assignment operator needed because this is a singleton

	void changeState(GameStates s); //Changing state is changing which state the currentState is pointing to
	void update();	//update the current state
	void handleEvent();
	void draw(sf::RenderWindow & r) const;	//draw the current state
};