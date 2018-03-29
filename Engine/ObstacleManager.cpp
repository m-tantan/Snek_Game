#include "ObstacleManager.h"



void ObstacleManager::drawObstacles(Board & brd)
{
	for (int i = 0; i < _nObstacles; ++i)
	{
		obstacles[i].drawObstacle(brd);
	}
}

void ObstacleManager::addObstacle( )
{
	Location rndLoc;
	int x = 0;
	int y = 0;
	do
	{

		x = (rand() % (Board::width - 2)) + (Board::_startX + 1);
		y = (rand() % (Board::height - 2)) + (Board::_startY + 1);
		rndLoc = Location{ x , y };

	} while (checkIfEmpty(rndLoc));
	ObstacleManager::Obstacle j = initObstacle(rndLoc, _nObstacles);
	obstacles.push_back(j);
	++_nObstacles;

}

bool ObstacleManager::checkCollisions(const Location & snakeLoc)
{
	for (int i = 0; i < _nObstacles; ++i)
	{
		if (obstacles[i].getLoc() == snakeLoc)
		{
			return true;
		}
	}
	return false;
}

void ObstacleManager::clearObstacles()
{
	obstacles.clear();
}



ObstacleManager::Obstacle::Obstacle(const Color & color, const Location & loc)
{
	oLoc = loc;
	oClr = color;
}

ObstacleManager::Obstacle ObstacleManager::Obstacle::initObstacle(const Location & obstacleLocation, const int & num)
{

	oLoc = obstacleLocation;

	int clrIdx = num % 10;

	int oClrR = 250, oClrG = 240, oClrB = 100;
	if (clrIdx == 0)
	{
		oClrG = 160;
	}
	else if (clrIdx == 1)
	{
		oClrG = 170;
	}
	else if (clrIdx == 3)
	{
		oClrG = 180;

	}
	else if (clrIdx == 2)
	{
		oClrG = 190;

	}
	else if (clrIdx == 4)
	{
		oClrG = 200;
	}
	else if (clrIdx == 5)
	{
		oClrG = 210;
	}
	else if (clrIdx == 6)
	{
		oClrG = 220;
	}
	else if (clrIdx == 7)
	{
		oClrG = 230;
	}
	else if (clrIdx == 8)
	{
		oClrG = 240;
	}
	else if (clrIdx == 9)
	{
		oClrG = 250;
	}
	else oClrG = 255;

	oClr = Color(oClrR, oClrG, oClrB);
	return ObstacleManager::Obstacle(oClr, obstacleLocation);
}

void ObstacleManager::Obstacle::drawObstacle(Board & brd)
{
	brd.drawCell(oLoc, oClr);
}
