#pragma once

#include <random>
#include "Board.h"
#include "Snake.h"

class Goal
{
public:
	Goal(std::mt19937& rng, const Snake& snek, const Board& brd);
	void respawn(std::mt19937& rng, const Snake& snek, const Board& brd);
	void draw(Board& brd) const;

	const Location& getLocation() const;
private:
	Color c;
	Location loc;
};

