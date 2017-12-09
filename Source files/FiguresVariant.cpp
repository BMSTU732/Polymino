#include "stdafx.h"
#include "FiguresVariant.hpp"

FiguresVariant::~FiguresVariant()
{}

FiguresVariant::FiguresVariant(string base, Figures figure) :
	data_group_performance{ base },
	figures{ figure },
	end{ false }
{
	vector<string> group_performances = figures.getGroupPerformances();

	for (int i = 0; i < group_performances.size(); i++)
	{
		string buffer = base;

		for (int j = 0; j < buffer.size(); j++)
		{
			if (buffer == group_performances[i])
			{
				end = true;

				Substring common(data_group_performance,
					i,                       
					0,                       
					0);                      

				new_data_group_performances.push_back("");
				common_substrings.push_back(common);

				return;
			}
			buffer = getTurnedString(buffer);
		}
	}
	getFiguresLargestCommonSubstring();
}

void FiguresVariant::getFiguresLargestCommonSubstring()
{
	vector<string> group_performances = figures.getGroupPerformances();

	for (int i = 0; i < group_performances.size(); i++)
	{
		getLargestCommonSubstrings(group_performances[i], i);
	}
}

void FiguresVariant::getLargestCommonSubstrings(string figures_group_performance, int rotation)
{
	string data_string = data_group_performance + data_group_performance;
	string figures_string = figures_group_performance + figures_group_performance;

	const int a_size = (int)data_string.size();
	const int b_size = (int)figures_string.size();

	typedef vector<int> solution;

	const int solution_size = b_size + 1;
	solution x(solution_size, 0), y(solution_size);

	solution* previous = &x;
	solution* current = &y;

	size_t max_length = 0;
	size_t substring_begining_index_data = 0;
	size_t substring_begining_index_figures = 0;

	for (int i = a_size - 1; i >= 0; i--)
	{
		for (int j = b_size - 1; j >= 0; j--)
		{
			int & current_match = (*current)[j];

			if (data_string[i] != figures_string[j])
			{
				current_match = 0;
			}
			else
			{
				const int length = 1 + (*previous)[j + 1];

				if (length > max_length)
				{
					max_length = length;

					substring_begining_index_data = i % (a_size / 2);
					substring_begining_index_figures = j % (b_size / 2);
				}

				current_match = length;
			}
		}

		swap(previous, current);
	}

	size_t substrings_length = 0;

	if (common_substrings.size() > 0)
	{
		substrings_length = common_substrings[0].size;
	}

	if (max_length > substrings_length)
	{
		common_substrings.clear();
		Substring substring(data_string.substr(substring_begining_index_data, max_length),
			rotation,
			substring_begining_index_figures,
			substring_begining_index_data);
		common_substrings.push_back(substring);
	}

	else if (max_length == substrings_length)
	{

		Substring substring(data_string.substr(substring_begining_index_data, max_length),
			rotation,
			substring_begining_index_figures,
			substring_begining_index_data);
		common_substrings.push_back(substring);
	}
}

bool FiguresVariant::checkData(string input)
{
	vector<Coordinates> buffer;

	Coordinates coord(0, 0);
	buffer.push_back(coord);

	for (int i = 0; i < input.size(); i++)
	{
		switch (input[i])
		{
		case 'R':
			coord.j++;
			break;
		case 'D':
			coord.i++;
			break;
		case 'L':
			coord.j--;
			break;
		case 'U':
			coord.i--;
			break;
		default:
			break;
		}

		if (i != input.size() - 1)
		{
			if (find(buffer.begin(),
				buffer.end(),
				coord)
				== buffer.end())
			{
				buffer.push_back(coord);
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (coord != Coordinates(0, 0))
			{
				return false;
			}
		}
	}

	return true;
}

bool FiguresVariant::countNewDataBase()
{
	for (int i = 0; i < common_substrings.size(); i++)
	{
		if (data_group_performance.size() == 0)
		{
			return false;
		}

		else
		{
			string answer = "";
			string part_first = getInvertedPart(i);

			string data = data_group_performance;

			size_t begin = common_substrings[i].index_in_data;
			size_t end = (begin + common_substrings[i].substring.size()) % data.size();

			if (begin < end)
			{
				answer = data.substr(0, begin);
				answer += part_first;
				answer += data.substr(end, data.size() - end);
			}
			else
			{
				answer = data.substr(end, begin - end);
				answer += part_first;
			}

			new_data_group_performances.push_back(answer);
		}
	}
	return true;
}

string FiguresVariant::getInvertedPart(int iterator)
{
	string answer = "";
	string inverted = "";
	string figures_str = figures.getGroupPerformanceByIndex(common_substrings[iterator].rotation);

	size_t begin = (common_substrings[iterator].index_in_figures +
		common_substrings[iterator].size)
		% figures_str.size();
	size_t size = figures_str.size() - common_substrings[iterator].size;

	if (begin + size <= figures_str.size())
	{
		inverted = figures_str.substr(begin, size);
	}
	else
	{
		inverted = figures_str.substr(begin, size);
	}

	for (int i = (int)inverted.size(); i >= 0; i--)
	{
		switch (inverted[i])
		{
		case 'R':
			answer.push_back('L');
			break;
		case 'D':
			answer.push_back('U');
			break;
		case 'L':
			answer.push_back('R');
			break;
		case 'U':
			answer.push_back('D');
			break;
		default:
			break;
		}
	}
	return answer;
}

size_t FiguresVariant::getSubstringLength()
{
	if (common_substrings.size() > 0)
	{
		return common_substrings[0].size;
	}
	else return 0;
}

void FiguresVariant::printVariantInfo()
{
	cout << endl
		<< "Base group performance: "
		<< data_group_performance << endl
		<< "Common substrings: ";

	for (int i = 0; i < common_substrings.size(); i++)
	{
		cout << common_substrings[i].substring
			<< " " << common_substrings[i].index_in_figures
			<< " " << common_substrings[i].index_in_data
			<< endl;
	}

	cout
		<< "New field base string: ";

	for (int i = 0; i < new_data_group_performances.size(); i++)
	{
		cout << " " << new_data_group_performances[i] << endl;
	}
}

FiguresVariant& FiguresVariant::operator = (const FiguresVariant& right)
{
	data_group_performance = right.data_group_performance;
	end = right.end;
	new_data_group_performances = right.new_data_group_performances;
	figures = right.figures;
	common_substrings = right.common_substrings;


	return *this;
}

string FiguresVariant::getTurnedString(string input)
{
	size_t size = input.size();
	char tmp = input[size - 1];

	for (size_t i = size - 1; i > 0; i--)
	{
		input[i] = input[i - 1];
	}
	input[0] = tmp;

	return input;
}
