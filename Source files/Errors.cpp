#include "stdafx.h"
#include "Errors.hpp"


void getError(Errors code)
{
	switch (code) {
	case ZERO_ARR:
		cout << "You have entered an array consisting of only zeros!"
			<< endl;
		break;

	case UNKNOWN_SYMBOL:
		cout << "You have entered an array containing an unknown symbol!"
			<< endl;
		break;

	case HOLE:
		cout << "You entered an element containing a hole!"
			<< endl;
		break;

	case NO_FILE:
		cout << "File not found! "
			<< endl;
		break;

	case NOT_SINGLE:
		cout << "The element is not the only one!"
			<< endl;
		break;

	case WRONG_SIDE_SIZE:
		cout << "Wrong array size!"
			<< endl;
		break;

	case NEED_HELP:
		cout << "Usage: ./a.out <Path to input file> <Path to output file>"
			<< endl;
		break;

	case INVALID_AREA:
		cout << "Input figures can not be placed in a rectangle!"
			<< endl;
		break;

	case NO_ANSWER:
		cout << "No solution found!"
			<< endl;
		break;

	case WIN:
		cout << "A solution is found!"
			<< endl;
		break;

	default:
		break;
	}
}
