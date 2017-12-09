#include "stdafx.h"
#include "Substring.hpp"

Substring::Substring(string str,
	int rotation,
	size_t index_figures,
	size_t index_data) :
	substring{ str },
	rotation{ rotation },
	index_in_figures{ index_figures },
	index_in_data{ index_data }
{
	size = substring.size();
}

Substring::~Substring()
{}