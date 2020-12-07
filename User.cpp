#include "User.h"
#include <vector>

// An explicit, parameterless constructor, that will initialize the semester list.
User::User()
{

	_SemesterList = new vector<Semester>();

}

// Destructor to free or reset any allocated resources.
User::~User()
{


}

// AddSemester(S) adds a given semester, S.
void User::AddSemester(const Semester& S)
{

	vector<Semester>::const_iterator itr = _SemesterList->begin();
	_SemesterList->insert(itr, S);

}

// AddSemester(S) adds a given semester, S; overloaded as an rvalue.
void User::AddSemester(Semester&& S)
{

	vector<Semester>::const_iterator itr = _SemesterList->begin();
	_SemesterList->insert(itr, S);

}

// FindSemester(index) finds the semester that is located at iterator position,
// index.
const Semester& User::FindSemester(unsigned int index) const
{

	vector<Semester>::iterator itr = _SemesterList->begin();

	while (itr != _SemesterList->end())
	{

		ptrdiff_t idx = _SemesterList->end() - itr;

		if (index == idx)
		{

			return *itr;

		}

		itr++;
	}

	return *itr;

}

// GetSemesterList() returns the list of semesters for this
// User instance.
const vector<Semester>& User::GetSemesterList() const
{

	return *_SemesterList;

}

// GetCreditsTaken() returns the total number of credits attempted
// by this user.
const unsigned int User::GetCreditsTaken() const
{

	return _CreditsTaken;

}

// GetOverallGPA() returns the overall GPA as a floating point value.
const float User::GetOverallGPA() const
{

	return _OverallGPA;

}

// GetCachedGradePoints() returns the total number of cached grade points
// as a floating point value.
const float User::GetCachedGradePoints() const
{

	return _CachedGradePoints;

}