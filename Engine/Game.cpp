/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

#define RIGHT Location{1, 0}
#define LEFT Location{-1, 0}
#define DOWN Location{0, 1}
#define UP Location{0, -1}

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	rng(std::random_device()()),
	snek(Location{ 4,2 }),
	trgt(rng, snek),
	om(rng)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();

}

void Game::UpdateModel()
{

	// For testing purposes
	if (wnd.kbd.KeyIsPressed('O'))
	{
		om.addObstacle();
	}

	if (wnd.kbd.KeyIsPressed('S'))
	{
		if (framesToUpdate > 3) {
			--framesToUpdate;
			gameSpeed = 3;

		}
			
	}

	if (!_gameOver)
	{
		//User input section
		_getUserInput();

		//updating mechanism section
		++timeCounter;
		if (timeCounter % 400 == 0)
		{
			if (gameSpeed > 2)
			{
				framesToUpdate = --gameSpeed;
				if (gameSpeed == 3)
				{
					_generateObstacles = true;
				}
			}
			if (_generateObstacles)
			{
				om.addObstacle();
			}
		}

		if (screenCounter % framesToUpdate == 0)
		{
			const Location next = snek.getSnakeNext(deltaLoc);
			bool one = !snek.isInsideBoard(brd, next);
			bool two = snek.isInsideSnekExceptEnd(next);
			bool three = om.checkCollisions(next);
			if ( one || two || three )
			{
				_gameOver = true;
			}
			else
			{
				screenCounter = 0;
				snek.moveBy(deltaLoc);
			}

			if (wnd.kbd.KeyIsPressed(VK_CONTROL) || snek.isInsideSnek(trgt.getLocation()))
			{
				snek.grow();
				//trgt.respawn(rng, brd, gfx, snek);
			}

		}
		++screenCounter;

	}
	else {
		if (wnd.kbd.KeyIsPressed('R'))
		{
			restartGame();
			snek.reset();
			om.clearObstacles();
			deltaLoc = { 1,0 }; // Resets direction
			_gameOver = false; // Allows player to play
			trgt.respawn(rng, brd, gfx, snek);
		}
	}
}

void Game::_getUserInput()
{
	Location prvsDelta = deltaLoc;
	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		if (prvsDelta != (UP))
		{
			deltaLoc = DOWN;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		if (prvsDelta != DOWN)
		{
			deltaLoc = UP;
		}
	}
	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		if (prvsDelta != RIGHT)
		{
			deltaLoc = LEFT;
		}
	}

	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		if (prvsDelta != LEFT)
		{
			deltaLoc = RIGHT;
		}
	}

}

void Game::restartGame()
{
	snek.reset();
	gameSpeed = INITIAL_SPEED;
	framesToUpdate = gameSpeed;
}

void Game::ComposeFrame()
{
	brd.drawBorder();
	snek.draw(brd);
	trgt.draw(brd);
	if (_gameOver)
	{
		SpriteCodex::DrawGameOver(360, 320, gfx);
	}
	om.drawObstacles(brd);
}