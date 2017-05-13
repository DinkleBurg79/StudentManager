#pragma once
#include "Assignment.h"

using namespace std;

template <typename Name, typename Points, typename Weight>
Assignment::Assignment(Name&& n, Points earned, Points max, Weight w)
	: _name(forward<Name>(n)),
	_points(earned),
	_max_points(max),
	_weight(w)
{

}