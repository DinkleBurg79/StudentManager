#include "Student.h"
#include "Assignment.h"
#include <iostream>

using namespace std;

Student::Student()
{
	cout << "Default constructor called" << endl;
}

Student::Student(string name, GradeLevel gradeLevel)
	: _id_num(_getNextIdNum()),
	_name(name),
	_courses(VecUPtrCourses())
{
	_grade_level = gradeLevel;
	cout << "Standard constructor called" << endl;
}

Student::Student(Student&& rhs)
	: _id_num(move(rhs._id_num)),
	_name(move(rhs._name)),
	_courses(move(rhs._courses)),
	_grade_level(move(rhs._grade_level))
{
	cout << "Move constructor called" << endl;
}

Student& Student::operator=(Student&& rhs)
{
	cout << "Move assignment operator called" << endl;
	_id_num = move(rhs._id_num);
	_name = move(rhs._name);
	_courses = move(rhs._courses);
	_grade_level = move(rhs._grade_level);
	return *this;
}

int Student::_next_id_num = 0;

int Student::_getNextIdNum()
{
	return _next_id_num++;
}

int Student::getIdNum() const
{
	return _id_num;
}

string Student::getName() const
{
	return _name;
}

unique_ptr<Course>& Student::accessCourse(int index) 
{
	index--;
	// BAD CODE BECAUSE THIS MEANS UPTR WON'T BE IN VECTOR
	return _courses[index];
}

vector<unique_ptr<Course>>& Student::accessCourses() 
{
	return _courses;
}