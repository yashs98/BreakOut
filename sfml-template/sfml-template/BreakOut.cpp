#include<iostream>
#include<string>
#include<cmath>
#include<vector>

#include <SFML/Graphics.hpp>
using namespace sf;
#include"BreakOut.h"
using namespace std;





BallShape::BallShape(){//default constructor

}

void BallShape:: Update()
{
	//Need to make the ball bounce of the window edges
	shape.move(velocity);
	//If it's leaving on the left edge, we set a positive horizontal value.
	if (left() < 0)
		velocity.x = BALL_VELOCITY;
	//Same for the right
	else if (right() > WINDOW_WIDTH)
		velocity.x = -BALL_VELOCITY;
	//Top
	if (top() < 0)
		velocity.y = BALL_VELOCITY;
	//And bottom
	else if (bottom() > WINDOW_HEIGHT)
		velocity.y = -BALL_VELOCITY;

}

Paddle::Paddle(float mX, float mY)   //Set the variables for the paddle rectangle shape.
{
	shape.setPosition(mX, mY);
	shape.setSize({ PADDLE_WIDTH, PADDLE_HEIGHT });
	shape.setFillColor(Color::Red);
	shape.setOrigin(PADDLE_WIDTH / 2.f, PADDLE_HEIGHT / 2.f);
}


void Paddle:: Update()
{
	shape.move(velocity);
	//To ensure that the paddle stays inside the window we only change the Velocity when it's inside the boundaries
	//Making it impossible to move outside when the initial velocity is set to zero
	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
		velocity.x = -PADDLE_VELOCITY;

	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < WINDOW_WIDTH)
		velocity.x = PADDLE_VELOCITY;
	//If the player isn't pressing a buttom (legt/right) the velocity is set to zero.
	else
		velocity.x = 0;
}


Brick::Brick(float mX, float mY)
{
	shape.setPosition(mX, mY);
	shape.setSize({ BLOCK_WIDTH, BLOCK_HEIGHT });
	shape.setFillColor(Color::Black);
	shape.setOrigin(BLOCK_WIDTH / 2.f, BLOCK_HEIGHT / 2.f);
}



void BallShape:: CollisionTest(Brick& mBrick, BallShape& mBall)// function for making the ball go appropriate directions when hitting the bricks
{
	if (!isIntersecting(mBrick, mBall)) return;
	mBrick.destroyed = true;

	float overlapLeft{ mBall.right() - mBrick.left() };
	float overlapRight{ mBrick.right() - mBall.left() };
	float overlapTop{ mBall.bottom() - mBrick.top() };
	float overlapBottom{ mBrick.bottom() - mBall.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
		mBall.velocity.x = ballFromLeft ? -BALL_VELOCITY : BALL_VELOCITY;
	else
		mBall.velocity.y = ballFromTop ? -BALL_VELOCITY : BALL_VELOCITY;
}


float BallShape:: x() { return shape.getPosition().x; }
float BallShape:: y() { return shape.getPosition().y; }
float BallShape:: left() { return x() - shape.getRadius(); }
float BallShape::right() { return x() + shape.getRadius(); }
float BallShape::top() { return y() - shape.getRadius(); }
float BallShape::bottom() { return y() + shape.getRadius(); }



BallShape::BallShape(float mX, float mY)//sets the position of the ball on the screen
{
	shape.setPosition(mX, mY);
	shape.setRadius(BALL_RADIUS);
	shape.setFillColor(Color::Yellow);
	shape.setOrigin(BALL_RADIUS, BALL_RADIUS);
}





void BallShape::CollisionTest(Paddle& mBrick, BallShape& mBall) // function for making the ball go appropriate directions when hitting the paddle
{
	if (!isIntersecting(mBrick, mBall)) return;
	

	float overlapLeft{ mBall.right() - mBrick.left() };
	float overlapRight{ mBrick.right() - mBall.left() };
	float overlapTop{ mBall.bottom() - mBrick.top() };
	float overlapBottom{ mBrick.bottom() - mBall.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
		mBall.velocity.x = ballFromLeft ? -BALL_VELOCITY : BALL_VELOCITY;
	else
		mBall.velocity.y = ballFromTop ? -BALL_VELOCITY : BALL_VELOCITY;
}
