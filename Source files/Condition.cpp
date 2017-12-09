#include "stdafx.h"
#include "Condition.hpp"

Condition::Condition() :
	height{ 0 },
	width{ 0 },
	group_performance_base{ "" },
	id{ 0 },
	parent_id{ 0 },
	is_final{ 0 },
	variant{ FiguresVariant("", Figures()) }
{}

Condition::Condition(size_t height,
	size_t width,
	string base,
	unsigned int id,
	int parent_id,
	vector<Figures> data) :
	height{ height },
	width{ width },
	group_performance_base{ base },
	id{ id },
	parent_id{ parent_id },
	data{ data },
	is_final{ 0 },
	variant{ FiguresVariant(group_performance_base, Figures()) }
{
	countVariants();
}

Condition::Condition(size_t height,
	size_t width,
	unsigned int id,
	int parent_id,
	vector<Figures> data) :
	height{ height },
	width{ width },
	id{ id },
	parent_id{ parent_id },
	data{ data },
	is_final{ 0 },
	variant{ FiguresVariant("", Figures()) }
{
	for (int i = 0; i < width; i++)
	{
		group_performance_base.append("R");
	}
	for (int i = 0; i < height; i++)
	{
		group_performance_base.append("D");
	}
	for (int i = 0; i < width; i++)
	{
		group_performance_base.append("L");
	}
	for (int i = 0; i < height; i++)
	{
		group_performance_base.append("U");
	}

	countVariants();
}

Condition::~Condition()
{}

string Condition::getGroupPerformance()
{
	return group_performance_base;
}

size_t Condition::getWidth()
{
	return width;
}

size_t Condition::getHeight()
{
	return height;
}

void Condition::countVariants()
{
	for (int i = 0; i < data.size(); i++)
	{
		FiguresVariant max(group_performance_base, data[i]);

		if (max.getSubstringLength() >= variant.getSubstringLength())
		{
			if (max.getSubstringLength() == variant.getSubstringLength())
			{
				old_variant.push_back(max);
			}
			else
			{
				variant = max;
				old_variant.clear();
			}
		}
	}
}

Condition Condition::countStep(int new_condition_id)
{
	if (variant.countNewDataBase())
	{
		if (variant.end)
		{
			Condition answer;
			answer.is_final = 1;
			answer.parent_id = id;
			return answer;
		}
		else
		{
			int primary_key = variant.figures.primary_key;

			for (int j = 0; j < data.size(); j++)
			{
				if (data[j].primary_key == primary_key)
				{
					if (data[j].number_of_same_figures > 1)
					{
						data[j].number_of_same_figures--;
					}
					else
					{
						data.erase(data.begin() + j);
					}
				}
			}
			if (variant.new_data_group_performances.size() > 0)
			{
				return Condition(height,
					width,
					variant.new_data_group_performances[0],         //??
					new_condition_id,
					id,
					data);
			}
			else
			{
				Condition answer = *this;

				if (old_variant.size() > 0)
				{
					size_t end = old_variant.size() - 1;
					answer.variant = old_variant[end];
					old_variant.pop_back();
				}
				else
				{
					answer.is_final = -1;
					answer.parent_id = id;
				}

				return answer;
			}
		}
	}
	else
	{
		Condition answer = *this;

		if (old_variant.size() > 0)
		{
			size_t end = old_variant.size() - 1;
			answer.variant = old_variant[end];
			old_variant.pop_back();
		}
		else
		{
			answer.is_final = -1;
		}

		return answer;
	}
}

void Condition::printDataInfo()
{
	cout << "State #" << id << endl
		<< "Parent id#" << parent_id << endl
		<< "Height: " << height << endl
		<< "Width: " << width << endl
		<< "Base: " << group_performance_base << endl
		<< "Comparative: ";

	variant.printVariantInfo();

	for (int i = 0; i < data.size(); i++)
	{
		data[i].printFiguresInfo();
	}
}

Condition& Condition::operator = (const Condition& right)
{
	old_variant = right.old_variant;
	data = right.data;

	id = right.id;
	parent_id = right.parent_id;

	is_final = right.is_final;
	height = right.height;
	width = right.width;

	group_performance_base = right.group_performance_base;
	variant = right.variant;

	return *this;
}