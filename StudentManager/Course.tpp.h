#pragma once
#include "Course.h"

using namespace std;

template <typename Name, typename Points, typename Weight>
void Course::addAssignment(Name&& n, Points earned, Points max, Weight w)
{
	auto assignment = make_unique<Assignment>(forward<Name>(n), earned, max, w);
	_grades.push_back(move(assignment));
}

template <typename Name>
void Course::deleteAssignment(Name&& n)
{
	for (auto itr = _grades.begin(), end_itr = _grades.end(); itr != end_itr; ++itr)
	{
		if ((*itr)->getName() == n)
		{
			_grades.erase(*itr);
			break;
		}
	}
}