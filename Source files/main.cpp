#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "Figures.hpp"
#include "Data.hpp"
#include "Errors.hpp"

using namespace std;

int main(int argc, const char* argv[])
{
	Data data(argc, argv);
	bool has_answer = data.tryLocalOptimum();

	if (has_answer)
	{
		getError(WIN);
		data.getAnswer();
	}
	else
	{
		getError(NO_ANSWER);
	}

	return 0;
}
