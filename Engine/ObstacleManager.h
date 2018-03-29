#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include <vector>

class ObstacleManager
{
private:
	class Obstacle 
	{
	public:
		Obstacle(const Color& color, const Location& loc);
		ObstacleManager::Obstacle initObstacle(const Location& obstacleLocation, const int& num);
		void drawObstacle(Board& brd);
		const Location& getLoc() const { return oLoc; };
	private:
		Location oLoc;
		Color oClr;
	};

public:
	ObstacleManager() = default;
	ObstacleManager(std::mt19937 originalRng) : rng(originalRng) {};
	void addObstacle();
	bool checkIfEmpty(const Location& loc);
	void drawObstacles(Board& brd);
	const int getObstacleAmount() const { return _nObstacles; };
	bool checkCollisions(const Location& snakeLoc);
	void clearObstacles();
private:
	static constexpr int maxAmountOfObstacles = 600;
	static constexpr Color obstacleColor =	Colors::Gray;
	std::vector<Obstacle> obstacles;
	int _nObstacles = 0;
	std::mt19937 rng;
};