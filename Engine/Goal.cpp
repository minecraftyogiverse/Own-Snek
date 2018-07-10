#include "Goal.h"

Goal::Goal(std::mt19937 & rng, const Snake & snek, const Board & brd)
{

	respawn(rng, snek, brd);

}

void Goal::respawn(std::mt19937 & rng, const Snake & snek, const Board & brd)
{

	std::uniform_int_distribution<int> xDist(0, brd.getWidth());
	std::uniform_int_distribution<int> yDist(0, brd.getHeight());

	Location newLoc;

	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snek.isInTileWithEnd(newLoc));

	loc = newLoc;
}

void Goal::draw(Board & brd) const
{

	brd.drawCell(loc, c);

}

const Location & Goal::getLocation() const
{
	return loc;
}
