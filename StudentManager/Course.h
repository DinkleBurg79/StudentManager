#pragma once
#include "Assignment.h"
#include <memory>
#include <string>
#include <vector>

// Student will hold vector of unique_ptrs to courses

class Course
{
	using GradeBook = std::vector<std::unique_ptr<Assignment>>;

public:
	
	// Default constructor
	Course();

	// Perfect forwarding constructor 
	template <typename Name>
	Course(Name&& n);

	// Adds unique_ptr to Assignment in vector
	template <typename Name, typename Points, typename Weight>
	void addAssignment(Name&& n, Points earned, Points max, Weight w);

	// Deletes unique_ptr to Assignment in vector based on name
	template <typename Name>
	void deleteAssignment(Name&& n);

	// Returns reference to unique_ptr to Assignment (uptr can be modified, but ownership doesn't change)
	std::unique_ptr<Assignment>& accessAssignment(int index);

	// Returns vector of unique_ptrs to assignments
	GradeBook& accessGradeBook();

	// Returns final grade of the course
	float getFinalGrade() const;
	
	// Return name of the course
	std::string getName() const;


private:
	// Name of the course
	std::string _name;

	// Vector that holds unique_ptrs to Assignments
	GradeBook _grades;
};

#include "Course.tpp.h"