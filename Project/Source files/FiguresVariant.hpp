#ifndef FiguresVariant_hpp
#define FiguresVariant_hpp
#include <stdio.h>
#include <string>
#include <vector>

#include "Figures.hpp"
#include "Substring.hpp"

using namespace std;

class FiguresVariant
{
public:
	string data_group_performance;
	vector<string> new_data_group_performances;
	vector<Substring> common_substrings;

	Figures figures;
	bool end;

	FiguresVariant(string, Figures);
	~FiguresVariant();

	void getFiguresLargestCommonSubstring();
	void getLargestCommonSubstrings(string, int);

	bool countNewDataBase();
	bool checkData(string);

	size_t getSubstringLength();

	void printVariantInfo();

	string getInvertedPart(int);
	string getTurnedString(string);

	FiguresVariant& operator = (const FiguresVariant&);
};

#endif /* FiguresVariant_hpp */