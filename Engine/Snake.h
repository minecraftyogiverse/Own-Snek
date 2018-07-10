#pragma once
#include "Colors.h"
#include "Location.h"
#include "Board.h"
#include <assert.h>

class Snake
{

private:
	class Segment
	{
	public:
		void initHead(const Location& loc_in);
		void initBody(Color c_in);
		void draw(Board& brd) const;
		void moveBy(const Location& delta_loc);
		void follow(const Segment& next);
		const Location& getLocation() const;
		
	private:
		Color c;
		Location loc;

	};
public:
	Snake(const Location& loc);
	void draw(Board& brd) const;
	void grow();
	void moveBy(const Location& delta_loc);
	Location getNextHeadLocation(const Location& delta_loc) const;
	bool isInTileWithoutEnd(const Location& target) const;
	bool isInTileWithEnd(const Location& target) const;
private:
	static constexpr Color headColor = Colors::Yellow;

	static constexpr int nSegmentsMax = 100;
	int nSegments = 1;

	Segment segments[nSegmentsMax];
};

