#pragma once
class Location
{
public:
	void add( const Location& loc);

	bool operator==(const Location& rhs) const;

	int x, y;
};

