#include "Class.h"
#include <string>
#include <iostream>
using namespace std;

// Explicit, parameterless constructor.
Class::Class()
{

	_ClassName = "";
	_LetterGrade = "F";
	_Credits = 0;

}

// A three-parameter, explicit constructor, that accepts a set of lvalue(s)
// that will indicate the course name, assigned letter grade and corresponding
// number of credits.
Class::Class(const string& name, const string& LetterGrade, const unsigned int& Credits)
{

	_ClassName = name;
	_LetterGrade = LetterGrade;
	_Credits = Credits;

}

// A three-parameter, explicit constructor, that accepts a set of rvalue(s)
// that will indicate the course name, assigned letter grade and corresponding
// number of credits.
Class::Class(const string&& name, const string&& LetterGrade, const unsigned int&& Credits)
{

	_ClassName = name;
	_LetterGrade = LetterGrade;
	_Credits = Credits;

}

// A Class destructor that will deallocate and free up resources
// that have been allocated from this Class instance.
Class::~Class()
{

	//_ClassName = nullptr;
	//_LetterGrade = nullptr;
	//_Credits = 0;

}

// GetClassName() is an accessor method, and will return the name of this class.
const string& Class::GetClassName() const
{

	return _ClassName;

}

// GetLetterGrade() is an accessor method, and will return the letter grade assigned
// to this class.
const string& Class::GetLetterGrade() const
{

	return _LetterGrade;

}

// GetCredits() is an accessor method, and will return the number of credits that
// correspond to this class.
const unsigned int& Class::GetCredits() const
{

	return _Credits;

}

// SetClassName(name) is a mutator method, that sets the class name.
void Class::SetClassName(const string& name)
{

	_ClassName = name;

}

// SetLetterGrade(letter) is a mutator method, that sets the letter grade.
void Class::SetLetterGrade(const string& letter)
{

	_LetterGrade = letter;

}

// SetCredits(credits) is a mutator method, that sets the number of credits.
void Class::SetCredits(const unsigned int& credits)
{

	_Credits = credits;

}