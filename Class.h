#include <iostream>
using namespace std;

#ifndef Class_H
#define Class_H

class Class
{

	// The name of this class.
	string _ClassName;

	// The letter grade assigned to this Class instance.
	string _LetterGrade;

	// The number of credits that accompany this Class instance.
	unsigned int _Credits;

public:

	// Explicit, parameterless constructor.
	Class();

	// A three-parameter, explicit constructor, that accepts a set of lvalue(s)
	// that will indicate the course name, assigned letter grade and corresponding
	// number of credits.
	Class(const string& name, const string& LetterGrade, const unsigned int& Credits);

	// A three-parameter, explicit constructor, that accepts a set of rvalue(s)
	// that will indicate the course name, assigned letter grade and corresponding
	// number of credits.
	Class(const string&& name, const string&& LetterGrade, const unsigned int&& Credits);

	// A Class destructor that will deallocate and free up resources
	// that have been allocated from this Class instance.
	~Class();

	// GetClassName() is an accessor method, and will return the name of this class.
	const string& GetClassName() const;

	// GetLetterGrade() is an accessor method, and will return the letter grade assigned
	// to this class.
	const string& GetLetterGrade() const;

	// GetCredits() is an accessor method, and will return the number of credits that
	// correspond to this class.
	const unsigned int& GetCredits() const;

	// SetClassName(name) is a mutator method, that sets the class name.
	void SetClassName(const string& name);

	// SetLetterGrade(letter) is a mutator method, that sets the letter grade.
	void SetLetterGrade(const string& letter);

	// SetCredits(credits) is a mutator method, that sets the number of credits.
	void SetCredits(const unsigned int& credits);

};

#endif

