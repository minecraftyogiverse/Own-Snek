#pragma once
#include "Location.h"
#include "Colors.h"
#include "Graphics.h"
#include <assert.h>

class Board
{
public:
	Board(Graphics& gfx);
	void drawCell(const Location& loc, const Color& c) const;
	int getWidth() const;
	int getHeight() const;

	bool isInBoard(const Location& loc) const;

private:

	static constexpr int width = 20;
	static constexpr int height = 20;
	static constexpr int dimension = 5;
	static constexpr int cellPadding = 2;

	Graphics& gfx;
};

