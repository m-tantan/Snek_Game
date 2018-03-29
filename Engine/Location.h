#pragma once


class Location
{
public: 
	void operator=(const Location& rhs) { x = rhs.x; y = rhs.y; }
	bool operator==(const Location& rhs) const { return x == rhs.x && y == rhs.y; }
	Location operator+=(const Location& rhs) { x += rhs.x; y += rhs.y; return *this; }
	Location operator-=(const Location& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
	bool operator!=(const Location& rhs) { return !(*this == rhs); }
	int x, y;
};