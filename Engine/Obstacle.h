#pragma once

#include <random>
#include "Board.h"
#include "Snake.h"
#include "Location.h"
#include "Colors.h"

class Obstacle
{
public:
	void draw(Board& brd) const;
	void spawn(std::mt19937& rng, const Snake& snek, const Board& brd);

	const Location& getLocation() const;

private:
	Location loc;
	static constexpr Color c = Colors::Gray;
};

