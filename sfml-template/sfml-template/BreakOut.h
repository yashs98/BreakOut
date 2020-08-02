#pragma once
#include<iostream>
#include<cmath>
#include<vector>

#include <tchar.h>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


const int WINDOW_WIDTH(800), WINDOW_HEIGHT(600);
const float BALL_RADIUS(10.f), BALL_VELOCITY(6.f);
const float PADDLE_WIDTH(100.f), PADDLE_HEIGHT(20.f), PADDLE_VELOCITY(8.f);
const float BLOCK_WIDTH(60.f), BLOCK_HEIGHT(20.f);
const int COUNT_BLOCKS_X(11), COUNT_BLOCKS_Y(6);
const int COUNT_BLOCKS_2X(11), COUNT_BLOCKS_2Y(3);






//Class for the paddle
class Paddle
{

public:
	RectangleShape shape;
	float x() { return shape.getPosition().x; }
	float y() { return shape.getPosition().y; }
	float left() { return x() - shape.getSize().x / 2.f; }
	float right() { return x() + shape.getSize().x / 2.f; }
	float top() { return y() - shape.getSize().y / 2.f; }
	float bottom() { return y() + shape.getSize().y / 2.f; }
	bool isPlaying = true;

	//Create a variable for speed.
	Vector2f velocity;

	Paddle(float mX, float mY);

	// Within the update function we check if the player is moving the paddle
	void Update();
};



//class for the brick
class Brick
{
public:

	bool destroyed{ false };
	RectangleShape shape;
	float x() { return shape.getPosition().x; }
	float y() { return shape.getPosition().y; }
	float left() { return x() - shape.getSize().x / 2.f; }
	float right() { return x() + shape.getSize().x / 2.f; }
	float top() { return y() - shape.getSize().y / 2.f; }
	float bottom() { return y() + shape.getSize().y / 2.f; }
	bool isPlaying = true;
	Brick(float mX, float mY);
	

	

};
//class for the ball
class BallShape {

public:
	CircleShape shape;
	Vector2f velocity{ BALL_VELOCITY, BALL_VELOCITY };
	BallShape(float mX, float mY);
	BallShape();
	void Update();
	
	bool isPlaying = true;
	
	
		template <class T1, class T2>
		bool isIntersecting(T1& mA, T2& mB)
		{
			return mA.right() >= mB.left() && mA.left() <= mB.right() &&
				mA.bottom() >= mB.top() && mA.top() <= mB.bottom();
		}

		void CollisionTest(Brick& mBrick, BallShape& mBall);
		
		
		void CollisionTest(Paddle& mBrick, BallShape& mBall);
		float x();
		float y();
		float left();
		float right();
		float top();
		float bottom();

			

			
		


};
// class  for the rectangle for the paddle and the bricks
class Rectangles {
public:

	struct Rectangle {
		RectangleShape shape;
		float x() { return shape.getPosition().x; }
		float y() { return shape.getPosition().y; }
		float left() { return x() - shape.getSize().x / 2.f; }
		float right() { return x() + shape.getSize().x / 2.f; }
		float top() { return y() - shape.getSize().y / 2.f; }
		float bottom() { return y() + shape.getSize().y / 2.f; }


	};
	

};




