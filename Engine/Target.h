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
	int currentLocationIdx = 0;
	bool isInitiated = false;
	Location tLoc;
	static constexpr Color clr = Colors::Magenta;

};