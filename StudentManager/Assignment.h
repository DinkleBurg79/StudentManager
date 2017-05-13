#pragma once
#include <string>

// Informal 30%, Formal 70%
enum class Weight
{
	W_FORMAL,
	W_INFORMAL
};

class Assignment
{
public:
	// Constructor
	Assignment(std::string, float points, float maxPoints, Weight weight);

	// Perfect forwarding constructor 
	//template <typename Name, typename Points, typename Weight>
	//Assignment(Name&& n, Points earned, Points max, Weight w);

	// Move constructor
	Assignment(Assignment&& rhs);

	// Move assignment operator
	Assignment& operator=(Assignment&& rhs);

	// Get name of assignment
	std::string getName() const;

	// Return assignment in string format for printing
	std::string toString();

	int getPoints() const;

	int getMaxPoints() const;

	// Get score as a percentage
	int getScore() const;

	// Get weight of assignment
	Weight getWeight() const;

	void editName(std::string newName);

	void editPoints(float points, float maxPoints);

private:
	std::string _name;

	// Points earned
	float _points;

	// Max points possible
	float _max_points;

	// Percentage of points out of max points
	int _score;

	// Grading weight of assignment
	Weight _weight;
};

#include "Assignment.tpp.h"