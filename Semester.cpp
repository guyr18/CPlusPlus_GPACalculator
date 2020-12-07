#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "Semester.h"

// Explicit parameterless constructor.
Semester::Semester()
{

	_ClassList = new vector<Class>();
	_Capacity = 0;

}

// A two-parameter constructor that initializes a Semester instance.
// It takes a semester name.
Semester::Semester(const string& name)
{

	_ClassList = new vector<Class>();
	_SemesterName = name;

}

// A two-parameter constructor that initializes a Semester instance.
// It takes a semester name and a vector (of Class instances), Target.
// Target is copied onto the class list for this Semester instance.
Semester::Semester(const string& name, const vector<Class>& Target)
{

	_SemesterName = name;
	vector<Class>::iterator itr = _ClassList->begin();
	vector<Class>::const_iterator itr_c = Target.begin();
	
	while (itr_c != Target.end())
	{

		_ClassList->insert(itr, *itr_c);
		itr++, itr_c++;

	}

	_Capacity = Target.size();

}

// A two-parameter constructor that initializes a Semester instance.
// It takes a semester name, an array of Class objects, and a type,
// size_t, N. N represents the length of the preceding array.
Semester::Semester(const string& name, const Class Target[], const size_t N)
{

	_SemesterName = name;
	vector<Class>::iterator itr = _ClassList->begin();

	for (size_t i = 0; i < N && itr != _ClassList->end(); i++, itr++)
	{

		_ClassList->insert(itr, Target[i]);

	}

	_Capacity = N;

}

// A destructor that deallocates all resources associated with this
// Semester instance.
Semester::~Semester()
{

	//_SemesterName = nullptr;
	//_Capacity = 0;

	//if (_ClassList->size() > 0)
	//{

		//_ClassList->clear();

	//}
}

// GetSemesterName() is an accessor that returns the name of this semester.
const string& Semester::GetSemesterName() const
{

	return _SemesterName;

}

// GetSemesterGPA() is an accessor that returns the cached cumulative semester GPA.
const float& Semester::GetSemesterGPA() const
{

	return _SemesterGPA;

}


// GetClassList() is an accessor that the returns the list of classes taken
// this semester.
const vector<Class>& Semester::GetClassList() const
{

	return *_ClassList;

}

// UpdateSemesterGPA(val) is a mutator function that updates the cumulative semester GPA.
void Semester::UpdateSemesterGPA(float val)
{

	_SemesterGPA += val;

}

// AddClass(C) adds a Class object, C, to the end of the class list
// that is associated with this Semester instance.
void Semester::AddClass(const Class& C)
{

	vector<Class>::const_iterator itr = _ClassList->begin();
	_ClassList->insert(itr, C);

}

// AddClass(C) adds a Class object, C, to the end of the class list
// that is associated with this Semester instance; An overloaded variation
// that accepts an rvalue.
void Semester::AddClass(Class&& C)
{

	vector<Class>::const_iterator itr = _ClassList->begin();
	_ClassList->insert(itr, C);

}

// RemoveClass(c) returns true if the class is successfully removed. And false, otherwise.
bool Semester::RemoveClass(Class& C)
{

	const vector<Class>::const_iterator& pos_itr = FindClassByName(C.GetClassName());
	_ClassList->erase(pos_itr);
	return pos_itr != _ClassList->end();

}

// FindClassByName(name) returns the const_iterator object if 
// a Class object is matched with string parameter, name.
// This gives a clear indication of the position that
// this match occurred at. If no match occurs, the
// iterator returned is equivalent to: const_iterator.end().
const vector<Class>::const_iterator Semester::FindClassByName(const string& name) const
{

	vector<Class>::const_iterator itr = _ClassList->begin();

	while (itr != _ClassList->end())
	{

		const Class& C = *itr;

		if (C.GetClassName() == name)
		{

			return itr;

		}

		itr++;

	}

	return itr;

}

// FindClassByName(name) returns the iterator object if 
// a Class object is matched with string parameter, name.
// This gives a clear indication of the position that
// this match occurred at. If no match occurs, the
// iterator returned is equivalent to: iterator.end().
//
// This overload is provided in the case the returner would
// like a mutatable iterator.
vector<Class>::iterator Semester::FindClassByName(const string& name)
{

	vector<Class>::iterator itr = _ClassList->begin();

	while (itr != _ClassList->end())
	{

		const Class& C = *itr;

		if (C.GetClassName() == name)
		{

			return itr;

		}

		itr++;

	}

	return itr;

}