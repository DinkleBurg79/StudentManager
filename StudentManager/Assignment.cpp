#include "Assignment.h"

using namespace std;

Assignment::Assignment(string name, float points, float maxPoints, Weight weight)
	: _name(name),
	_points(points),
	_max_points(maxPoints),
	_weight(weight)
{
	_score = (_points / _max_points) * 100;
}

Assignment::Assignment(Assignment&& rhs)
	: _name(move(rhs._name)),
	_points(move(rhs._points)),
	_max_points(move(rhs._max_points)),
	_weight(move(rhs._weight))
{
	_score = (_points / _max_points) * 100;
}

Assignment& Assignment::operator=(Assignment&& rhs)
{

	_name = move(rhs._name);
	_points = move(rhs._points);
	_max_points = move(rhs._max_points);
	_weight = move(rhs._weight);
	_score = (_points / _max_points) * 100;
	return *this;
}

string Assignment::getName() const
{
	return _name;
}

string Assignment::toString()
{
	string message = "Name: ";
	message += _name;
	message += '\n';
	message += "Score(%): ";
	message += to_string(_score);
	return message;
}

int Assignment::getPoints() const
{
	return _points;
}

int Assignment::getMaxPoints() const
{
	return _max_points;
}

int Assignment::getScore() const
{
	return _score;
}

Weight Assignment::getWeight() const
{
	return _weight;
}

void Assignment::editName(string newName)
{
	_name = newName;
}

void Assignment::editPoints(float points, float maxPoints)
{
	_points = points;
	_max_points = maxPoints;
	_score = (_points / maxPoints) * 100;
}