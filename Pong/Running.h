#pragma once
#include "gamestate.h"
#include <SFML\Graphics.hpp>
#include "vector2.h"

class Running : public GameState
{
private:
	//const float ballSpeed;

	sf::RectangleShape paddle;
	sf::RectangleShape aPaddle;
	
	sf::CircleShape ball;
	vector2f ballVelocity;
	bool c;
	bool gameOver;
	bool collided();
	bool aCollided();
	bool cCollided();//for ball colliding with ceiling
	bool someoneScored();


	int score;
	int aScore;

	sf::Text tScore;
	sf::Text taScore;

	void reset();
	void updateAI();

public:
	Running();
	virtual ~Running();

	virtual void draw(sf::RenderWindow & r) ;
	virtual void handleEvent();
	virtual void update();

};

