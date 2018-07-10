#include "Goal.h"

Goal::Goal(std::mt19937 & rng, const Snake & snek, const Board & brd)
{

	respawn(rng, snek, brd);

}

void Goal::respawn(std::mt19937 & rng, const Snake & snek, const Board & brd)
{

	std::uniform_int_distribution<int> xDist(2, brd.getWidth() - 3);
	std::uniform_int_distribution<int> yDist(2, brd.getHeight() - 3);

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
