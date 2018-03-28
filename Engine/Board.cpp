#include "Board.h"
#include <assert.h>


Board::Board(Graphics & gfx) : gfx(gfx)
{
}

void Board::drawCell(const Location & loc, const Color & c)
{
	assert(loc.x <= _startX + width + 1);
	assert(loc.x >= _startX - 1 );
	assert(loc.y <= _startY + height + 1);
	assert(loc.y >= _startY - 1);
	gfx.DrawRectDim(loc.x * dimension + _startX, _startY + loc.y * dimension, dimension, dimension, c);
}

void Board::drawBorder()
{
	int borderColorR = 100, borderColorG = 90, borderColorB = 0;
	
	// Vertical Left
	for (int i = dimension * _startY; i < (_startY + height) * dimension; ++i)
	{
		gfx.PutPixel(_startX * dimension + dimension + 2, i, borderColorR, borderColorG, borderColorB);
	}
	// Vertical Right
	for (int i = dimension * _startY; i < (_startY + height) * dimension; ++i)
	{
		gfx.PutPixel((_startX + width) * dimension - dimension + 2, i, borderColorR, borderColorG, borderColorB);
	}
	// Upper Horizontal 
	for (int i = dimension * _startX; i < (_startX + width) * dimension; ++i)
	{
		gfx.PutPixel(i, (_startY + 1 )* dimension, borderColorR, borderColorG, borderColorB);
	}
	// Bottom Horizontal 
	for (int i = dimension * _startX; i < (_startX + width) * dimension; ++i)
	{
		gfx.PutPixel(i, (_startY + height - 1) * dimension, borderColorR, borderColorG, borderColorB);
	}

}


