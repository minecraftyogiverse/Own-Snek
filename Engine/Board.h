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

	void drawBorder();

	bool isInBoard(const Location& loc) const;

private:

	static constexpr Color borderColor = Colors::Blue;
	static constexpr int width = 32;
	static constexpr int height = 24;
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 2;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int x = 70;
	static constexpr int y = 50;

	Graphics& gfx;
};

