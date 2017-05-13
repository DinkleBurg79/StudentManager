#pragma once
#include "Course.h"
#include <memory>
#include <string>
#include <vector>

enum class GradeLevel
{
	GL_FRESHMAN,
	GL_SOPHMORE,
	GL_JUNIOR,
	GL_SENOIR
};

class Student
{	
	using VecUPtrCourses = std::vector<std::unique_ptr<Course>>;

public:
	// Default constructor
	Student();

	// Constructor
	Student(std::string name, GradeLevel gradeLevel);

	// Move constructor
	Student(Student&& rhs);

	// Move assignment operator
	Student& operator=(Student&& rhs);

	// Returns id#
	int getIdNum() const;

	// Returns student's name
	std::string getName() const;

	// Adds course to VecUPtrClasses
	template <typename Name>
	void addCourse(Name&& n);

	// Returns reference to unique_ptr to Course based on index (uptr can be modified, but ownership doesn't change)
	std::unique_ptr<Course>& accessCourse(int index);

	// Returns vector of unique_ptrs to courses 
	VecUPtrCourses& accessCourses();

private:
	static int _getNextIdNum();
	static int _next_id_num;

	std::string _name;
	int _id_num;
	GradeLevel _grade_level;
	VecUPtrCourses _courses;
};

#include "Student.tpp.h"