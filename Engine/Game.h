/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
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
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Snake.h"
#include <random>
#include "SpriteCodex.h"
#include "Target.h"
#include "ObstacleManager.h"

#define INITIAL_SPEED 10

class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();

private:
	void ComposeFrame();
	void UpdateModel();
	void _getUserInput();
	void restartGame();
	
private:
	MainWindow& wnd;
	Graphics gfx;
	Board brd;
	std::mt19937 rng;
	Snake snek;
	Target trgt;
	ObstacleManager om;
	Location deltaLoc{ 1,0 };
	int screenCounter = 0;
	int timeCounter = 0;
	int gameSpeed = INITIAL_SPEED;
	int framesToUpdate = gameSpeed;
	int framesToIncSpeed = 400;
	bool _gameOver = false;
	bool _generateObstacles = false;

	
};