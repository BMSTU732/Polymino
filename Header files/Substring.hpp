#ifndef Substring_hpp
#define Substring_hpp

#include <stdio.h>
#include <string>

	using namespace std;

class Substring
{
public:

	string substring;

	int rotation;
	size_t size;

	size_t index_in_data;
	size_t index_in_figures;

	Substring(string, int, size_t, size_t);
	Substring();
	~Substring();
};

#endif /* Substring_hpp */