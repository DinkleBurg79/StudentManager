#pragma once
#include "Student.h"

using namespace std;

template <typename Name>
void Student::addCourse(Name&& n)
{
	auto course = make_unique<Course>(forward<Name>(n));
	_courses.push_back(move(course));
}