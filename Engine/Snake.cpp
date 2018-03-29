#include "Snake.h"
#include "assert.h"


void Snake::Segment::initHead(Location & headLoc)
{
	assert(!isInstantiated);
	sLoc = headLoc;
	clr = Snake::headClr;
	isInstantiated = true;
}

void Snake::Segment::initBody(const int & length)
{
	int clrIdx = length % 5;
	int clrR = 200, clrG = 200, clrB = 0;
	if (clrIdx == 0 || clrIdx == 4) {
		clrG = 160;
	}
	else if (clrIdx == 1 || clrIdx == 3)
	{
		clrG = 200;
	}
	else clrG = 240;

	clr = Color( clrR, clrG, clrB );

}

void Snake::Segment::moveBy(Location & newLoc)
{
	assert(std::abs(newLoc.x) + std::abs(newLoc.y) == 1);
	sLoc.x += newLoc.x;
	sLoc.y += newLoc.y;
}

void Snake::Segment::follow(Segment& nxtSeg)
{
	sLoc = nxtSeg.sLoc;
}

void Snake::Segment::draw(Board & brd) const
{
	brd.drawCell(sLoc, clr);
}

const Location & Snake::Segment::getLocation() const
{
	return sLoc;
}

void Snake::Segment::setSegLoc(const Location & newLoc)
{
	sLoc = newLoc;
}

Snake::Snake(Location & snakeLoc)
{
	nSegment[0].initHead(snakeLoc);
}

void Snake::moveBy(Location & deltaLoc)
{
	for (int i = _length; i > 0; --i)
	{
		nSegment[i].follow(nSegment[i - 1]);
	}
	nSegment[0].moveBy(deltaLoc);
}

void Snake::grow()
{
	if (_length < nSegmentMaximum)
	{
		nSegment[_length].initBody(_length);
		++_length;
	}
}

void Snake::draw(Board & brd)
{
	for (int i = 0; i < _length; i++)
	{
		nSegment[i].draw(brd);
	}
}

bool Snake::isInsideBoard(const Board& brd, const Location& next)
{
	return next.x > brd.startX() && next.x < brd.startX() + brd.getWidth() - 1
		&& next.y > brd.startY() && next.y < brd.startY() + brd.getHeight() - 1;
}

const Location & Snake::getSnakeNext(const Location& direction)
{
	//snek. += direction;
	Location next = nSegment[0].getLocation();
	next += direction;
	return next;
}

bool Snake::isInsideSnekExceptEnd(const Location & checkLoc) const
{
	for (int i = 0; i < _length - 1; ++i)
	{
		if (nSegment[i].getLocation() == checkLoc)
		{
			return true;
		}
	}
	return false;
}

bool Snake::isInsideSnek(const Location& checkLoc) const
{
	for (int i = 0; i < _length; ++i)
	{
		if (nSegment[i].getLocation() == checkLoc)
		{
			return true;
		}
	}
	return false;
}

void Snake::reset()
{
	nSegment[0].setSegLoc(Location{ 5,5 });
	_length = 1;
}

const Location & Snake::getSnakeHead() const
{
	return nSegment[0].getLocation();
}

const Location & Snake::getSnakeSeg(const int & segNum) const
{
	return nSegment[segNum].getLocation();
}
const bool Snake::canMoveInDirection(const Location & direction) const
{
	Location head = getSnakeHead();
	Location segOne = getSnakeSeg(1);
	Location next = (head += direction);
	if (next != segOne)
	{
		return true;
	}
	return false;
}