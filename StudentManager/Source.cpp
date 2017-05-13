#pragma once
#include "Student.h"
#include <iostream>

using namespace std;

int main()
{
	Student s("Alex", GradeLevel::GL_FRESHMAN);
	s.addCourse("Math");
	s.accessCourse(1)->addAssignment("IB Paper 1", 300, 400, Weight::W_FORMAL);
	cout << s.accessCourse(1)->getName() << endl;
	cout << s.accessCourse(1)->accessAssignment(1)->toString() << endl;
	
	//s.accessCourses()[0]->addAssignment("IB Paper 1", 200, 300, Weight::W_FORMAL);
	//cout << s.accessCourses()[0]->getName() << endl;
	//cout << s.accessCourses()[0]->accessGradeBook()[0]->toString() << endl;
}