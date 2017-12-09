#ifndef Errors_hpp
#define Errors_hpp
#include <iostream>

using namespace std;

// различные ошибки для вывода в консоль
enum Errors
{
	ZERO_ARR,
	UNKNOWN_SYMBOL,
	HOLE,
	NO_FILE,
	NOT_SINGLE,
	WRONG_SIDE_SIZE,
	NEED_HELP,
	INVALID_AREA,
	NO_ANSWER,
	WIN
};

#endif 
/* Errors_hpp */
void getError(Errors);



