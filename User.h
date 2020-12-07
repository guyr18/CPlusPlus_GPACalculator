#include "Semester.h"
#include <vector>
#include <iostream>
using namespace std;

#ifndef User_H
#define User_H

class User
{

	// A vector containing an array of Semester objects.
	vector<Semester>* _SemesterList;

	// The total number of credits that have been taken by this user.
	unsigned int _CreditsTaken = 0;

	// The cumulative GPA of this user.
	float _OverallGPA = 0.0f;

	// The number of grade points achieved by this user; this is to be used for
	// GPA computation.
	float _CachedGradePoints = 0.0f;

public:

	// The default number of allowable semesters; standard graduation is in eight.
	static const size_t MAX_SEMESTER_CAPACITY = 8;

	// An explicit, parameterless constructor, that will initialize the semester list.
	User();

	// Destructor to free or reset any allocated resources.
	~User();

	// AddSemester(S) adds a given semester, S.
	void AddSemester(const Semester& S);

	// AddSemester(S) adds a given semester, S; overloaded as an rvalue.
	void AddSemester(Semester&& S);

	// FindSemester(index) finds the semester that is located at iterator position,
	// index.
	const Semester& FindSemester(unsigned int index) const;

	// Accessors

	// GetSemesterList() returns the list of semesters for this
	// User instance.
	const vector<Semester>& GetSemesterList() const;

	// GetCreditsTaken() returns the total number of credits attempted
	// by this user.
	const unsigned int GetCreditsTaken() const;

	// GetOverallGPA() returns the overall GPA as a floating point value.
	const float GetOverallGPA() const;

	// GetCachedGradePoints() returns the total number of cached grade points
	// as a floating point value.
	const float GetCachedGradePoints() const;

};

#endif User_H

