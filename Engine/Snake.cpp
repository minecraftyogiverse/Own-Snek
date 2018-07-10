#include "Snake.h"



Snake::Snake(const Location& loc)
{

	static constexpr int nBodyColors = 4;
	static constexpr Color bodyColors[nBodyColors] = {
		{255, 0, 0},
		{0, 255, 0},
		{0, 0, 255},
		{255, 0, 0}
	};

	for (int i = 0; i <= nSegmentsMax; i++)
	{
		segments[i].initBody(bodyColors[i % nBodyColors]);
	}

	segments[0].initHead(loc);

}

void Snake::draw(Board & brd) const
{

	for (int i = 0; i < nSegments; i++)
	{
		segments[i].draw(brd);
	}

}

void Snake::grow()
{

	if (nSegments < nSegmentsMax)
	{
		nSegments++;
	}

}

void Snake::moveBy(const Location & delta_loc)
{

	for (int i = nSegments - 1; i > 0; i--)
	{
		segments[i].follow(segments[i - 1]);
	}
	segments[0].moveBy(delta_loc);

}

Location Snake::getNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].getLocation());
	l.add(delta_loc);

	return l;

}

bool Snake::isInTileWithoutEnd(const Location & target) const
{
	for (int i = 0; i <= nSegments - 1; i++)
	{
		if (segments[i].getLocation() == target)
		{
			return true;
		}
	}
	return false;
}

bool Snake::isInTileWithEnd(const Location & target) const
{

	for (int i = 0; i <= nSegments; i++)
	{
		if (segments[i].getLocation() == target)
		{
			return true;
		}
	}

	return false;
}

void Snake::Segment::initHead(const Location& loc_in)
{

	loc = loc_in;
	c = Snake::headColor;

}

void Snake::Segment::initBody(Color c_in)
{

	c = c_in;

}

void Snake::Segment::draw(Board& brd) const
{

	brd.drawCell(loc, c);

}

void Snake::Segment::moveBy(const Location & delta_loc)
{

	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);

	loc.add(delta_loc);

}

void Snake::Segment::follow(const Segment & next)
{

	loc = next.loc;

}

const Location & Snake::Segment::getLocation() const
{
	return loc;
}
