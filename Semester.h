#include <vector>
#include <string>
#include <iostream>
#include "Class.h"
using namespace std;

#ifndef Semester_H
#define Semester_H

class Semester
{

	// The name of this semester.
	string _SemesterName;

	// The cumulative GPA of classes taken during the semester.
	// This should be cached, so that, if the class is not modified
	// then we can show it in O(1) time. Rather than O(N) time if we 
	// had to traverse the entire vector contents; defaults to 0.0f.
	float _SemesterGPA = 0.0f;

	// A vector containing the list of classes that were
	// taken for this semester.
	vector<Class>* _ClassList;

	// An unsigned integral type that represents the capacity
	// of the class list that is associated with this Semester
	// instance.
	size_t _Capacity;

public:

	
	// Explicit parameterless constructor.
	Semester();

	// A two-parameter constructor that initializes a Semester instance.
	// It takes a semester name.
	Semester(const string& name);

	// A two-parameter constructor that initializes a Semester instance.
	// It takes a semester name and a vector (of Class instances), Target.
	// Target is copied onto the class list for this Semester instance.
	Semester(const string& name, const vector<Class>& Target);

	// A two-parameter constructor that initializes a Semester instance.
	// It takes a semester name, an array of Class objects, and a type,
	// size_t, N. N represents the length of the preceding array.
	Semester(const string& name, const Class Target[], const size_t N);

	// A destructor that deallocates all resources associated with this
	// Semester instance.
	~Semester();

	// GetSemesterName() is an accessor that returns the name of this semester.
	const string& GetSemesterName() const;

	// GetSemesterGPA() is an accessor that returns the cached cumulative semester GPA.
	const float& GetSemesterGPA() const;

	// GetClassList() is an accessor that the returns the list of classes taken
	// this semester.
	const vector<Class>& GetClassList() const;

	// UpdateSemesterGPA(val) is a mutator function that updates the cumulative semester GPA.
	void UpdateSemesterGPA(float val);

	// AddClass(C) adds a Class object, C, to the end of the class list
	// that is associated with this Semester instance.
	void AddClass(const Class& C);

	// AddClass(C) adds a Class object, C, to the end of the class list
	// that is associated with this Semester instance; An overloaded variation
	// that accepts an rvalue.
	void AddClass(Class&& C);

	// RemoveClass(c) returns true if the class is successfully removed. And false, otherwise.
	bool RemoveClass(Class& C);

	// FindClassByName(name) returns the const_iterator object if 
	// a Class object is matched with string parameter, name.
	// This gives a clear indication of the position that
	// this match occurred at. If no match occurs, the
	// iterator returned is equivalent to: const_iterator.end().
	const vector<Class>::const_iterator FindClassByName(const string& name) const;

	// FindClassByName(name) returns the iterator object if 
	// a Class object is matched with string parameter, name.
	// This gives a clear indication of the position that
	// this match occurred at. If no match occurs, the
	// iterator returned is equivalent to: iterator.end().
	//
	// This overload is provided in the case the returner would
	// like a mutatable iterator.
	vector<Class>::iterator FindClassByName(const string& name);
};

#endif 