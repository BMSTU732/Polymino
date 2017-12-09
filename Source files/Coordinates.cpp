#include "Coordinates.hpp"

Coordinates::Coordinates(size_t x, size_t y) :
	i{ x },
	j{ y }
{}

Coordinates::Coordinates() :
	i{ 0 },
	j{ 0 }
{}

Coordinates& Coordinates::operator = (const Coordinates& right)
{
	if (this == &right)
	{
		return *this;
	}

	i = right.i;
	j = right.j;

	return *this;
}

bool Coordinates::operator < (const Coordinates& right)const
{
	return (i < right.i) || (j < right.j);
}

bool Coordinates::operator == (const Coordinates& right)const
{
	return (i == right.i) && (j == right.j);
}

bool Coordinates::operator != (const Coordinates& right)const
{
	return (i != right.i) || (j != right.j);
}

void Coordinates::printCoordinatesInfo()
{
	cout << "[ " << i << " , " << j << " ] ";
}
