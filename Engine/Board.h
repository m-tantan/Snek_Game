#pragma once
#include <random>
#include "Graphics.h"
#include "Location.h"

class Board
{
public:
	Board(Graphics &gfx);
	void drawCell(const Location &loc, const Color& c);
	int getHeight() const { return height; }
	int getWidth() const { return width; }
	int startX() const { return _startX; }
	int startY() const { return _startY; }
	void drawBorder();
	static constexpr int _startX = 3;
	static constexpr int _startY = 1;
	static constexpr int dimension = 11;
	static constexpr int height = 48;
	static constexpr int width = 65;

private:
	Graphics& gfx;
	//Snake snake;
};