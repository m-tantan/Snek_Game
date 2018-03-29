#pragma once
#include "Location.h"
#include "Board.h"
#include "ObstacleManager.h"

class Snake
{
private:
	class Segment
	{
	public: 
		void initHead( Location& headLoc);
		void initBody(const int& length);
		void moveBy(Location& newLoc);
		void follow( Segment & nxtSeg);
		void draw( Board& brd) const;
		const Location& getLocation() const;
		void setSegLoc(const Location& newLoc);
	private:
		bool isInstantiated = false;
		bool isAlive = true;
		Location sLoc;
		Color clr;
	};

public:
	Snake(Location & snakeLoc);
	void moveBy(Location & deltaLoc);
	void grow();
	void draw(Board & brd);
	int getLength() { return _length; }
	bool isInsideBoard(const Board& brd, const Location& next);
	const Location& getSnakeNext(const Location& direction);
	bool isInsideSnekExceptEnd(const Location& checkLoc) const;
	bool isInsideSnek(const Location& checkLoc) const;
	void reset();
	const Location& getSnakeHead() const;
	const Location& getSnakeSeg(const int& segNum) const;
	const bool canMoveInDirection(const Location & direction) const;
private:
	static constexpr Color headClr = Colors::Green;
	static constexpr Color bodyClr = Colors::Yellow;
	static const int nSegmentMaximum = 2000;
	Segment nSegment[nSegmentMaximum];
	int _length = 1; // Starts at length 1
};