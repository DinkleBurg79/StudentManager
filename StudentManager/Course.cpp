#include "Course.h"

using namespace std;

Course::Course() = default;

//Course::Course(string name)
//{
	//_name = name;
	//_grades = GradeBook();
//}

unique_ptr<Assignment>& Course::accessAssignment(int index) 
{
	// Since vector counts from 0, decrement index value asked
	index--;
	return _grades[index];
}

vector<unique_ptr<Assignment>>& Course::accessGradeBook()
{
	return _grades;
}

float Course::getFinalGrade() const
{
	// Calculate the averages of the formal and informal grades separately
	float formal = 0;
	int numFormals = 0;
	float informal = 0;
	for (auto itr = _grades.begin(), end_itr = _grades.end(); itr != end_itr; ++itr)
	{
		if ((*itr)->getWeight() == Weight::W_FORMAL)
		{
			formal += (*itr)->getScore();
			numFormals++;
		}
		else
		{
			informal += (*itr)->getScore();
		}
	}
	return ((formal / numFormals) * 0.7f + (informal / (_grades.size() - numFormals)) * 0.3f);
}

string Course::getName() const
{
	return _name;
}