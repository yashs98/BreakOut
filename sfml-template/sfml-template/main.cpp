#include <iostream>
using namespace std;

#include<cmath>
#include"BreakOut.h"
#include <SFML/Graphics.hpp>
using namespace sf;




	




int main()
{
	bool isPlaying = true;
	BallShape upd;
	BallShape collision;
	int lives=4;
	
	//create the window
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Breakout Mayhem");
	window.setFramerateLimit(60);

	Paddle paddle{ WINDOW_WIDTH / 2, WINDOW_HEIGHT - 50 };
	int x = 5;

	// reference the Ball, Paddle and Bricks
	 BallShape ball{ WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
	
	//vector to make the bricks
	 vector<Brick> bricks;
	for (int iX{ 0 }; iX < COUNT_BLOCKS_X; ++iX)
		for (int iY{ 0 }; iY < COUNT_BLOCKS_Y; ++iY)
			bricks.emplace_back(
			(iX + 1) * (BLOCK_WIDTH + 3) + 22, (iY + 2) * (BLOCK_HEIGHT + 3));
	


	
	while (true)
	{
		window.clear(Color::Color(49, 79, 79));

		
		//calling the update function for the ball and the paddle
		ball.Update();
		paddle.Update();
	collision.CollisionTest(paddle, ball);
		for (auto& brick : bricks) collision.CollisionTest(brick, ball);
		bricks.erase(remove_if(begin(bricks), end(bricks),
			[](const Brick& mBrick)
		{
			return mBrick.destroyed;
		}),
			end(bricks));

		if (isPlaying)
		{
			window.draw(ball.shape);
			window.draw(paddle.shape);

			for (auto& brick : bricks) window.draw(brick.shape);
			
		}

	
		if (bricks.size() == 0) {
			//text if the person wins
			cout << "You win!" << endl;

			break;

		}
		
		else if (ball.bottom() > WINDOW_HEIGHT) {
			lives--;
			cout << "You have " << lives << " lives." << endl;
		}
		if (lives == 0) {
			// text if person loses
			cout << "You lose!" << endl;

			break;
		}
		window.display();

	}

	return EXIT_SUCCESS;
}