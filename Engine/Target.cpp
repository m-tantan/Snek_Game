#include "Target.h"

Target::Target(std::mt19937 rng, const Snake& snek)
{
	
	
	std::uniform_int_distribution<> xDist(Board::_startX + 1 , (Board::_startX + Board::width));
	std::uniform_int_distribution<> yDist(Board::_startY + 1 , (Board::_startY + Board::height));
	do
	{

		tLoc.x = xDist(rng);
		tLoc.y = yDist(rng);
	
	} while (snek.isInsideSnek(tLoc));
}

void Target::respawn(std::mt19937 rng, Board & brd, Graphics & gfx, const Snake& snek)
{
	currentLocationIdx++;
	
	do
	{

		tLoc.x = (rand() % (Board::width - 2)) + (Board::_startX + 1);
		tLoc.y = (rand() % (Board::height  - 2)) + (Board::_startY + 1);
		
	} while (snek.isInsideSnek(tLoc));
}

void Target::draw(Board& brd)
{
	brd.drawCell(tLoc, clr);
}

const Location & Target::getLocation() const
{
	return tLoc;
}

