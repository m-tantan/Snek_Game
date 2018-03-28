#pragma once


class Location
{
public: 
	void operator=(const Location& rhs) { x = rhs.x; y = rhs.y; }
	bool operator==(const Location& rhs) const { return x == rhs.x && y == rhs.y; }
	void operator+=(const Location& rhs) { x += rhs.x; y += rhs.y; }
	bool operator!=(const Location& rhs) { return !(*this == rhs); }
	int x, y;
};