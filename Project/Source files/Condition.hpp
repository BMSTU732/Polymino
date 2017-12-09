#ifndef Condition_hpp
#define Condition_hpp
#include <string>
#include <iostream>

#include "Figures.hpp"
#include "FiguresVariant.hpp"

using namespace std;

class Condition
{
public:

	vector<FiguresVariant> old_variant;
	vector<Figures> data;

	unsigned int id;
	int parent_id;

	int is_final;

	size_t height;
	size_t width;

	string group_performance_base;

	FiguresVariant variant;

	string getGroupPerformance();
	size_t getWidth();
	size_t getHeight();

	Condition countStep(int);
	void countVariants();

	void printDataInfo();

	Condition();
	Condition(size_t,
		size_t,
		unsigned int,
		int,
		vector<Figures>);
	Condition(size_t,
		size_t,
		string,
		unsigned int,
		int,
		vector<Figures>);
	~Condition();

	Condition& operator = (const Condition&);
};

#endif /* Condition_hpp */