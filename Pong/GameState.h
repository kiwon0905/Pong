#pragma once
#include <SFML/Graphics.hpp>

enum GameStates{MENU=0, RUNNING, NUMGAMESTATES};

class GameState//State Menu and Play will be derived from here.
{
protected:
	bool changeState;

public:
	GameState():changeState(false){}
	~GameState(){};
	
	virtual void handleEvent()=0;
	virtual void update()=0;
	virtual void draw(sf::RenderWindow & r)=0;
	virtual bool needToChangeState(){return changeState;}
};

