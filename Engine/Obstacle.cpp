#include "Obstacle.h"

void Obstacle::draw(Board & brd) const
{

	brd.drawCell(loc, c);

}

void Obstacle::spawn(std::mt19937 & rng, const Snake & snek, const Board & brd)
{

	std::uniform_int_distribution<int> xDist(1, brd.getWidth() - 1);
	std::uniform_int_distribution<int> yDist(1, brd.getHeight() - 1);

	Location newLoc;

	do
	{
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while (snek.isInTileWithEnd(newLoc));
	loc = newLoc;
}

const Location & Obstacle::getLocation() const
{
	return loc;
}
