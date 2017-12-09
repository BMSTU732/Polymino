#ifndef Coordinates_hpp
#define Coordinates_hpp
#include <iostream>

using namespace std;

//класс для координат элементов массива
//используется для проверки на наличие отверстий и нескольких фигур
class Coordinates
{
public:
	size_t i;
	size_t j;

	Coordinates();
	Coordinates(size_t, size_t);

	void printCoordinatesInfo();

	Coordinates& operator = (const Coordinates&);

	bool operator < (const Coordinates&)const;
	bool operator == (const Coordinates&)const;
	bool operator != (const Coordinates&)const;
};

#endif /* Coordinates_hpp */