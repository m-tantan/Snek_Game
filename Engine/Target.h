#pragma once
#include "Location.h"
#include "Graphics.h"
#include <random>
#include "Board.h"
#include "Snake.h"

class Target
{
public:
	Target(std::mt19937 rng, const Snake& snek);
	void respawn(std::mt19937 rng, Board& brd, Graphics& gfx, const Snake& snek);
	void draw(Board& brd);
	const Location&  getLocation() const;
private:
	const bool checkPreviousLocations(const Location& loc);
	int currentLocationIdx = 0;
	bool isInitiated = false;
	static constexpr int maxAmountOfTargets = 500;
	Location tLoc;
	Location locations[maxAmountOfTargets];
	static constexpr Color clr = Colors::Magenta;

};