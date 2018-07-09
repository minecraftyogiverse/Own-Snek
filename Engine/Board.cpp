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

	const int off_x = x + borderWidth + borderPadding;
	const int off_y = y + borderWidth + borderPadding;

	gfx.DrawRectDim(loc.x * dimension + off_x, loc.y * dimension + off_y, dimension, dimension, Colors::Black);
	gfx.DrawRectDim(loc.x * dimension + off_x, loc.y * dimension + off_y, dimension - cellPadding, dimension - cellPadding, c);

}

int Board::getWidth() const
{
	return width;
}

int Board::getHeight() const
{
	return height;
}

void Board::drawBorder()
{
	static constexpr int left = x;
	static constexpr int top = y;
	static constexpr int bottom = top + (borderWidth + borderPadding) * 2 + dimension * height;
	static constexpr int right = left + (borderWidth + borderPadding) * 2 + dimension * width;

	//top
	gfx.DrawRect(left, top, right, top + borderWidth, borderColor);
	//bottom
	gfx.DrawRect(left, bottom - borderWidth, right, bottom, borderColor);
	//left
	gfx.DrawRect(left, top, left + borderWidth, bottom, borderColor);
	//right
	gfx.DrawRect(right - borderWidth, top, right, bottom, borderColor);

}

bool Board::isInBoard(const Location & loc) const
{
	return loc.x > 0 && loc.x < width &&
		loc.y > 0 && loc.y < height;
}
