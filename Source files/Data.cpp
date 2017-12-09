#include "stdafx.h"
#include "Data.hpp"


Data::~Data()
{}

Data::Data(int argc, const char* argv[])
{
	area = 0;
	min_size = 0;
	min_size_i = 0;
	min_size_j = 0;
	is_checked = false;

	ifstream input(argv[1]);
	ofstream output(argv[2]);

	bool check = false;

	check = checkUserInput(argc, input, output);

	if (!check)
	{
		return;
	}

	check = inputDataFromFile(input, output);

	if (!check)
	{
		return;
	}

	output_str = argv[2];

	check = countArea();

	if (!check)
	{
		return;
	}

	check = getValidSizes(area, min_size_i, min_size_j);

	if (!check)
	{
		getError(INVALID_AREA);
		return;
	}
	else
	{
		is_checked = true;
	}
}

bool Data::checkUserInput(int argc,
	ifstream& input,
	ofstream& output)
{
	if (argc != 3)
	{
		getError(NEED_HELP);
		return false;
	}

	if (!input || !output)
	{
		getError(NEED_HELP);
		return false;
	}

	return true;
}

bool Data::inputDataFromFile(ifstream& input, ofstream& output)
{
	vector<Figures> input_figures;

	size_t number_of_figures = 0;
	size_t square_size = 0;

	//количество фигур на ввод
	input >> number_of_figures;

	for (int i = 0; i < number_of_figures; i++)
	{
		int figure_id = 0;
		int number_of_figures = 0;

		// Cчитываем id фигуры
		input >> figure_id;

		// Cторона массива
		input >> square_size;

		if (square_size <= 0)
		{
			getError(WRONG_SIDE_SIZE);
			return false;
		}

		// Количество фигур
		input >> number_of_figures;

		vector<vector<int>> binary_performance = Figures::getZeroSquareArray(square_size);

		for (size_t j = 0; j < square_size; j++)
		{
			for (size_t k = 0; k < square_size; k++)
			{
				input >> binary_performance[j][k];
			}
		}

		//конструктор выполняет проверку на корректность данных
		Figures item(binary_performance);

		if (item.is_correct)
		{
			item.setPrimaryKey(figure_id);
			item.setNumberOfFigures(number_of_figures);
			input_figures.push_back(item);
		}
		else
		{
			return false;
		}

		valid_data = input_figures;

	}
	return true;
}

bool Data::countArea()
{
	for (int i = 0; i < valid_data.size(); i++)
	{
		area += valid_data[i].getArea() * valid_data[i].number_of_same_figures;

		if (valid_data[i].getSize() > min_size)
		{
			min_size = valid_data[i].getSize();
		}

		if (valid_data[i].side_size_i > min_size_i)
		{
			min_size_i = valid_data[i].side_size_i;
		}

		if (valid_data[i].side_size_j > min_size_j)
		{
			min_size_j = valid_data[i].side_size_j;
		}
	}

	if (area > 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

bool Data::getValidSizes(size_t area, size_t min_size_i, size_t min_size_j)
{
	vector<Coordinates> answer;

	for (int i = 1; i <= area / 2; i++)
	{
		if (area % i == 0)
		{
			int first_factor = i;
			int second_factor = (int)area / i;

			if ((first_factor >= min_size_i &&
				second_factor >= min_size_j) ||
				((first_factor >= min_size_j &&
					second_factor >= min_size_i)))
			{
				answer.push_back(Coordinates(first_factor, second_factor));
			}
		}
	}

	int array_half_size = (int)answer.size() / 2;

	for (int i = 0; i < array_half_size; i++)
	{
		answer.pop_back();
	}

	if (answer.size() > 0)
	{
		valid_sizes = answer;
		return true;
	}
	else
	{
		return false;
	}
}

bool Data::tryLocalOptimum()
{
	// Пробегаем все возможные размеры прямоугольника
	for (int j = 0; j < valid_sizes.size(); j++)
	{
		condition_tree.clear();

		Condition condition_size(valid_sizes[j].i,
			valid_sizes[j].j,
			0,
			-1,
			valid_data);
		condition_tree.push_back(condition_size);

		for (int i = 0; i < condition_tree.size(); i++)
		{
			int new_condition_id = (int)condition_tree.size();
			Condition condition = condition_tree[i].countStep(new_condition_id);

			switch (condition.is_final)
			{
			case 1:
				condition_tree.push_back(condition);
				return true;

			case -1:
				return false;

			default:
				condition_tree.push_back(condition);
			}
		}
	}
	return false;
}

void Data::printFieldInfo()
{
	cout << "Polymino figures: " << endl;

	for (int i = 0; i < valid_data.size(); i++)
	{
		valid_data[i].printFiguresInfo();
	}

	cout << endl << "All valid sizes: " << endl;

	for (int i = 0; i < valid_sizes.size(); i++)
	{
		valid_sizes[i].printCoordinatesInfo();
		cout << endl;
	}

	cout << endl << "Area: " << area << endl << endl;
}

void Data::getAnswer()
{
	int end = 0;
	ofstream output(output_str);

	output << "Answer: " << endl;

	for (int i = 0; i < condition_tree.size(); i++)
	{
		if (condition_tree[i].is_final == 1)
		{
			end = condition_tree[i].parent_id;
		}
	}

	while (end >= 0)
	{
		output << condition_tree[end].variant.figures.getPrimaryKey() << ". "
			<< endl << condition_tree[end].variant.data_group_performance << endl;

		end = condition_tree[end].parent_id;
	}
}