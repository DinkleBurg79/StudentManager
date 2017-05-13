#pragma once
#include "Student.h"
#include <iostream>

using namespace std;

int main()
{
	Student s("Alex", GradeLevel::GL_FRESHMAN);
	s.addCourse("Math");
	s.accessCourse(1)->addAssignment("IB Paper 1", 200, 300, Weight::W_FORMAL);

	cout << s._courses.size() << endl;

	// SOMETHING WRONG WITH THIS CODE
	//cout << s.accessCourse(1)->getName() << endl;
	//cout << s.accessCourse(1)->accessAssignment(1)->getScore() << endl;
	//cout << s.accessCourse(1)->getFinalGrade() << endl;
}