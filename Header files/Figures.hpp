#ifndef Figures_hpp
#define Figures_hpp

#include <string>
#include <vector>
#include <stack>

#include "Errors.hpp"
#include "Coordinates.hpp"

using namespace std;

class Figures
{
public:

	int number_of_same_figures;
	int primary_key;
	bool is_correct;

	size_t side_size_i;
	size_t side_size_j;

	Figures(vector<vector<int>>);
	Figures();
	~Figures();

	bool setPrimaryKey(int);
	bool setNumberOfFigures(int);

	void printArrayPerformance();
	void printGroupPerfomances();
	void printFiguresInfo();

	vector<vector<int>> getArrayPerformance();
	vector<string> getGroupPerformances();
	string getGroupPerformanceByIndex(int);

	int getPrimaryKey();
	int getArea();
	size_t getSize();


	static vector<vector<int>> getZeroSquareArray(size_t);
	Figures& operator = (const Figures&);

private:

	vector<vector<int>> array_performance;
	size_t side_size;
	vector<string> group_performances_array;
	int area;

	bool countArea();
	bool countGroupPerformance();
	bool countSizes();
	void getAllGroupPerformances();

	bool checkValidation();

	bool checkArrayForCorrectNumbers();
	bool checkArrayForSingleFigure();
	bool checkArrayForHoles();
	bool checkArrayPerformance();

	bool getZerosNotHoleCoordinates(vector<Coordinates>&, Coordinates);
	bool getUnitsCoordinates(vector<Coordinates>&, Coordinates);

	void pushToBufferElementHoods(stack<Coordinates>&, Coordinates);
	void printArray(vector<vector<int>>);


	void fillAreaAroundByUnits(Coordinates);
	vector<vector<int>> getHelpArray(vector<vector<int>>);

	Coordinates getFirstUnitCoordinates(vector<vector<int>>);
	Coordinates getNextPosition(vector<vector<int>>,
		Coordinates,
		char,
		char&);
	Coordinates getFirstUnitCoordinates();

	string getTurnGroupPerformance(string);
	string getMirrorGroupPerformance(string);
};

#endif /* Figures_hpp */

