#include "Target.h"

Target::Target(std::mt19937 rng, const Snake& snek)
{
	
	
	std::uniform_int_distribution<> xDist(Board::_startX + 1 , (Board::_startX + Board::width));
	std::uniform_int_distribution<> yDist(Board::_startY + 1 , (Board::_startY + Board::height));
	do
	{

		tLoc.x = xDist(rng);
		tLoc.y = yDist(rng);
		locations[currentLocationIdx++] =  tLoc ;
	} while (snek.isInsideSnek(tLoc));
}

void Target::respawn(std::mt19937 rng, Board & brd, Graphics & gfx, const Snake& snek)
{
	do
	{
		std::uniform_int_distribution<> xDist(Board::_startX + 1, (Board::_startX + Board::width - 2));
		std::uniform_int_distribution<> yDist(Board::_startY + 1, (Board::_startY + Board::height - 2));
		tLoc.x = xDist(rng);
		tLoc.y = yDist(rng);
		locations[currentLocationIdx++] = tLoc ;

	} while (snek.isInsideSnek(tLoc) || checkPreviousLocations(tLoc));
}

void Target::draw(Board& brd)
{
	brd.drawCell(tLoc, clr);
}

const Location & Target::getLocation() const
{
	return tLoc;
}

const bool Target::checkPreviousLocations(const Location& loc)
{	
	
	for (int i = 0; i < currentLocationIdx; ++i) {
		if (locations[i] == loc) return true;
	}
	return false;
}
