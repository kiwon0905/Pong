#include "Running.h"
#include <iostream>
#include <cstdlib>//for random
#include <sstream>
#include "vector2.h"
#include <Windows.h>

inline float clamp(float x, float a, float b){    return x < a ? a : (x > b ? b : x);}
double fRand(double fMin, double fMax) 
{ 
    double f = (double)rand() / RAND_MAX; 
    return fMin + f * (fMax - fMin); 
} 
std::string tostr(int x) 
{ 
	std::string r; 
	std::stringstream s; 
	s << x; 
	r = s.str(); 
	return r; 
} 


bool Running::collided()
{
	if(paddle.getPosition().x+20>=ball.getPosition().x)
	{
		if(paddle.getPosition().y<=ball.getPosition().y+10 && ball.getPosition().y+10<=paddle.getPosition().y+100)
		{
			c=true;
			ball.move(paddle.getPosition().x+20-ball.getPosition().x, 0);
			return true;
		}
	}
	return false;
}

bool Running::aCollided()
{
	if(aPaddle.getPosition().x<=ball.getPosition().x+20)
	{
		if(aPaddle.getPosition().y<=ball.getPosition().y+10 && ball.getPosition().y+10<=aPaddle.getPosition().y+100)
		{
			c=false;
			ball.move(aPaddle.getPosition().x-(ball.getPosition().x+20), 0);
			return true;
		}
	}
	return false;
}

bool Running::cCollided()
{
	return ball.getPosition().y<0||ball.getPosition().y+20>600;
}

bool Running::someoneScored()
{
	return ball.getPosition().x<0 || ball.getPosition().x+20>800; 
}
																	
Running::Running():paddle(sf::Vector2f(20, 100)), aPaddle(sf::Vector2f(20, 100)), ball(10, 30), ballVelocity(0.7, 0), score(0), aScore(0), tScore(sf::String("0")), taScore(sf::String("0")), gameOver(false)
{
	paddle.setPosition(0, 250);
	aPaddle.setPosition(780, 250);
	ball.setFillColor(sf::Color::Cyan);
	ball.setPosition(390, 290);
	tScore.setPosition(190, 0);
	taScore.setPosition(590, 0);
}

Running::~Running()
{
}

void Running::draw(sf::RenderWindow & r) 
{
	r.draw(paddle);
	r.draw(aPaddle);
	r.draw(ball);
	r.draw(tScore);
	r.draw(taScore);
}

void Running::reset()
{		
		ball.setPosition(390, 290);
		if(int(rand()%2+1)==2)
			ballVelocity.x=-ballVelocity.x;
		ballVelocity.y=0;
	
}

void Running::handleEvent()
{
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if(paddle.getPosition().y>=0)
				paddle.move(0, -1);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if(paddle.getPosition().y<500)
				paddle.move(0, 1);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			reset();
		}
}

void Running::updateAI()
{
	if(ball.getPosition().y+10>aPaddle.getPosition().y+50)
	{
		if(aPaddle.getPosition().y<500)
			aPaddle.move(0,0.7);
	}
	else if(ball.getPosition().y+10<aPaddle.getPosition().y+50)
	{
		if(aPaddle.getPosition().y>0)
			aPaddle.move(0,-0.7);
	}
}

void Running::update()
{	
	if(gameOver)
	{
		Sleep(1000);
		exit(0);
	}
	updateAI();
	ball.setPosition(ball.getPosition().x+ballVelocity.x, ball.getPosition().y+ballVelocity.y);//advance the ball
	if(someoneScored())
	{
		if(ball.getPosition().x<400)
		{
			aScore++;
			taScore.setString(sf::String(tostr(aScore)));
		}
		else
		{
			score++;
			tScore.setString(sf::String(tostr(score)));
		}
		if(score>=5)
		{
			system("cls");
			std::cout<<"You Win!";
			gameOver=true;
		}
		else if(aScore>=5)
		{
			system("cls");
			std::cout<<"You Lost...";
			gameOver=true;
		}
		reset();
	}
	if(collided()||aCollided())//check for collision detection with paddle
	{
		float d;
		if(c)
		{
			d=(abs(paddle.getPosition().y+50-(ball.getPosition().y+10)));
		}
		else
		{
			d=(abs(aPaddle.getPosition().y+50-(ball.getPosition().y+10)));
		}
		//std::cout<<d<<std::endl;
		float a=fRand(-d/10, d/10);
		//std::cout<<a<<std::endl;
		ballVelocity.y+=a;
		ballVelocity.y=clamp(ballVelocity.y, -0.9, 0.9);
		ballVelocity.x=-ballVelocity.x;
	}
	if(cCollided())//ball collided with ceiliing
	{
		ballVelocity.y=-ballVelocity.y;
	}
}