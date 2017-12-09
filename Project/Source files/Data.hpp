#ifndef Data_hpp
#define Data_hpp
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include "Figures.hpp"
#include "Errors.hpp"
#include "Coordinates.hpp"
#include "Condition.hpp"

using namespace std;

class Data
{
	vector<Figures> valid_data;
	vector<Condition> condition_tree;
	vector<Coordinates> valid_sizes;

	string output_str;

	size_t min_size;
	size_t min_size_i;
	size_t min_size_j;
	size_t area;

	bool is_checked;

public:

	Data(int, const char**);
	~Data();

	void printFieldInfo();
	bool tryLocalOptimum();
	void getAnswer();

private:

	bool checkUserInput(int, ifstream&, ofstream&);
	bool inputDataFromFile(ifstream&, ofstream&);
	bool countArea();

	bool getValidSizes(size_t, size_t, size_t);
};


#endif /* Data_hpp */
