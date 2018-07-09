#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

void Board::drawCell(const Location& loc, const Color& c) const
{
	assert(loc.x >= 0);
	assert(loc.x <= width);
	assert(loc.y >= 0);
	assert(loc.y <= height);

	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension, dimension, Colors::Black);
	gfx.DrawRectDim(loc.x * dimension, loc.y * dimension, dimension - cellPadding, dimension - cellPadding, c);

}

int Board::getWidth() const
{
	return width;
}

int Board::getHeight() const
{
	return height;
}

bool Board::isInBoard(const Location & loc) const
{
	return loc.x > 0 && loc.x < width &&
		loc.y > 0 && loc.y < height;
}
