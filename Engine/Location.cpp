#include "Location.h"

void Location::add(const Location & loc)
{

	x += loc.x;
	y += loc.y;

}

bool Location::operator==(const Location & rhs) const
{
	return x == rhs.x && y == rhs.y;
}
