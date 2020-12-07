#include <iostream>
#include <string>
#include <map>
#include <conio.h>
#include "User.h"
#include "Semester.h"
#include "Class.h"
using namespace std;

// Variable / enum declarations
enum { MainMenu = 0, SemesterMenu = 1, NewClassMenu = 2, StatisticsMenu = 3, AboutMenu = 4 };
unsigned int ActiveMenuCode = MainMenu;
float CachedGradePoints = 0.0f;
unsigned int CachedCredits = 0;
Semester CachedSemester;
Class CachedClass;
map<string, float> GradingScale;

// Function prototypes; @see implementation for documentation.
void HandleEnrollmentInput(const User& U, ostream& out = cout, istream& in = cin);
void HandleAboutInput(const User& U, ostream& out = cout, istream& in = cin);
void HandleClassInput(const User& U, ostream& out = cout, istream& in = cin);
void HandleSemesterInput(const User& U, ostream& out, istream& in);
void HandleInput(const User& U, ostream& out = cout, istream& in = cin);
void AwaitKey(const User& U, bool isBack = false, istream& in = cin, ostream& out = cout);

// BuildGradingChart(M) takes a sorted map type, M, and builds
// it according to the chosen grading model; a plus-minus scale.
void BuildGradingChart(map<string, float>& M)
{

	M["A"] = 4.0f;
	M["A-"] = 3.70f;
	M["B+"] = 3.30f;
	M["B"] = 3.00f;
	M["B-"] = 2.70f;
	M["C+"] = 2.30f;
	M["C"] = 2.00f;
	M["C-"] = 1.70f;
	M["D+"] = 1.30f;
	M["D"] = 1.00f;
	M["D-"] = 0.70f;
	M["F"] = 0.00f;

}

// TraceInputMenu() traces the default menu to the standard output stream. By
// default, the standard output stream is -> cout.
void TraceInputMenu(ostream& out = cout)
{

	out << "Developed By Robert Guy | github.com/guyr18" << endl;
	out << "1. Show Semester List" << endl;
	out << "2. Show Class List" << endl;
	out << "3. Manage Semester" << endl;
	out << "4. Show Enrollment Statistics" << endl;
	out << "5. About This Application" << endl;
	out << "6. Exit Application" << endl;

}

// ShowSemesterList(U, out) shows the list of semesters that are available for User, U. 
// If no semesters have been inserted, an empty message will be displayed.
void ShowSemesterList(const User& U, ostream& out = cout)
{

	if (U.GetSemesterList().size() == 0)
	{

		out << endl << "No semesters currently available." << endl;

	}
	else
	{

		vector<Semester> semesters = U.GetSemesterList();
		vector<Semester>::reverse_iterator itr = semesters.rbegin();
		unsigned int i = 1;
		out << endl;

		while (itr != semesters.rend())
		{

			const Semester& sem = *itr;
			out << "   " << i << ". " << sem.GetSemesterName() << endl;
			itr++, i++;

		}
	}
}

// ChartLookup(letter) takes a letter grade string and returns an approximate
// grade point value.
float ChartLookup(const string& letter)
{

	return GradingScale[letter];

}

// ShowClassList(U, S, out) shows the list of classes taken by a given User, U,
// in a particular semester, S. Furthermore, it will display all data relative
// to that class. If no such Semester, S, exists, then an error message will 
// be displayed.
void ShowClassList(const User& U, const Semester& S, ostream& out = cout)
{

	if (U.GetSemesterList().size() == 0)
	{

		out << endl << "This user has not enrolled in a semester to date." << endl;

	}
	else
	{

		vector<Class> C = S.GetClassList();
		vector<Class>::iterator itr = C.begin();
		unsigned int num_credits = 0;
		float total_grade_points = 0.0f;
		out << endl << "Semester: " << S.GetSemesterName() << endl << endl;
		size_t i = 1;

		while(itr != C.end())
		{

			const Class& _C = *itr;
			const string& className = _C.GetClassName();
			const unsigned int& classCredits = _C.GetCredits();
			const string& classLetterGrade = _C.GetLetterGrade();
			num_credits += _C.GetCredits();
			total_grade_points = total_grade_points + (_C.GetCredits() * ChartLookup(_C.GetLetterGrade()));
			out << i << ". " << className << "\t" << classCredits << " Credits " << "\t" << classLetterGrade << endl;
			itr++, i++;

		}

		out << endl << "Cumulative GPA: " << total_grade_points / num_credits << endl;

	}
}

// AwaitKey(U, in, out) waits for user input before returning to the main menu.
void AwaitKey(const User& U, bool isBack, istream& in, ostream& out)
{

	if (!isBack)
	{

		out << endl << "Press [ANY KEY] to return to the input menu..." << endl;

		while (_kbhit() != 1)
		{ // do nothing 
		}

		// flush the state of _kbhit() in <conio.h>
		_getch();
		out << endl;

	}

	// A different input function will be called based on the context of the active
	// menu. So, here we will dispatch the correct method to handle the correct
	// menu. Menus are differentiated from by an enumeration declaration.
	if (ActiveMenuCode == MainMenu)
	{

		TraceInputMenu();
		HandleInput(U);

	}
	else if (ActiveMenuCode == SemesterMenu)
	{

		HandleSemesterInput(U, out, in);

	}
	else if(ActiveMenuCode == NewClassMenu)
	{

		HandleClassInput(U);

	}
}

// HandleClassInput(U, out, in) handles input to the submenu containing class property additions.
void HandleClassInput(const User& U, ostream& out, istream& in)
{

	User u = U;
	unsigned int i;
	string x;
	unsigned int y;
	out << endl << "Classes have three properties that can be updated. Luckily, we have listed each. " << endl;
	out << "Please choose which one you would like to update: " << endl;
	out << "1. Class Name" << endl;
	out << "2. Letter Grade" << endl;
	out << "3. Credits" << endl;
	out << "4. Back To Semester Menu (Adds class, make sure to complete options 1-3 first)" << endl;
	in >> i;

	if (i <= 0 || i > 4)
	{

		out << "Unrecognized menu code" << endl;
		ActiveMenuCode = SemesterMenu;

	}
	else if(i == 1)
	{

		out << endl << "Enter Class Name: " << endl;
		cin.ignore();
		getline(in, x);
		ActiveMenuCode = NewClassMenu;
		CachedClass.SetClassName(x);

	}
	else if (i == 2)
	{

		out << endl << "Enter Letter Grade: " << endl;
		in >> x;
		ActiveMenuCode = NewClassMenu;
		CachedClass.SetLetterGrade(x);

	}
	else if (i == 3)
	{

		out << endl << "Enter Credits Amount: " << endl;
		in >> y;
		ActiveMenuCode = NewClassMenu;
		CachedClass.SetCredits(y);

	}
	else if (i == 4)
	{

		out << endl << "Class, " << CachedClass.GetClassName() << " was added." << endl;
		out << endl;
		CachedSemester.AddClass(CachedClass);
		ActiveMenuCode = SemesterMenu;

	}

	AwaitKey(U, true);

}

// HandleSemesterInput(U, out, in) handles input to the submenu containing semester management (i.e.: input).
void HandleSemesterInput(const User& U, ostream& out, istream& in)
{

	User u = U;
	unsigned int j;
	out << endl << "Semesters can be managed in a variety of ways. These ways are listed below, alongside their respective menu code(s)." << endl;
	out << endl << "1. Add Semester" << endl;
	out << "2. Update Semester" << endl;
	out << "3. Back To Main Menu" << endl;
	in >> j;

	if (j == 1)
	{

		string name;
		out << endl << "To add a semester, we will need a name." << endl;
		out << "What is the name of your semester?" << endl;
		cin.ignore();
		getline(in, name);
		out << endl << "Okay, great, so we're recording semester, " << name << ". Next, to set up your semester, you'll need some classes. " << endl;
		out << "Updating a semester is easy. Just type menu code (3)." << endl;
		u.AddSemester(Semester(name));
		AwaitKey(U, true);

	}
	else if (j == 2)
	{

		unsigned int k;
		out << "To update a semester, we'll need a one based position, just like before." << endl;
		in >> k;

		if (k <= 0 || k > U.GetSemesterList().size())
		{

			out << "You appear to have entered an invalid one based position." << endl;
			AwaitKey(U);

		}
		else
		{
			
			CachedSemester = U.FindSemester(k);
			HandleClassInput(U);
			
		}
	}
	else if (j == 3)
	{

		ActiveMenuCode = MainMenu;
		out << endl;
		AwaitKey(U, true);

	}
}

// HandleAboutInput(U, out, in) handles menu code input initiated from
// enumeration declaration, AboutMenu.
void HandleAboutInput(const User& U, ostream& out, istream& in)
{

	unsigned int i;
	out << endl << "I, Robert Guy, developed this application to further acclimate myself to the C++ programming language." << endl;
	out << "This application is designed to test my knowledge of several STLs. And furthermore, to aid in my migration " << endl << "from a";
	out << " more traditional object-oriented style of programming (such as Java, AS3, C#) to a more functional format, " << endl << "that ";
	out << "is C / C++." << endl;
	out << endl << "1. Return To Main Menu" << endl;
	in >> i;
	out << endl;
	ActiveMenuCode = MainMenu;
	AwaitKey(U, true);

}

// HandleEnrollmentInput(U, out, in) handles menu code input initiated
// from enumeration declaration, StatisticsMenu.
void HandleEnrollmentInput(const User& U, ostream& out, istream& in)
{

	unsigned int i;

	if (U.GetSemesterList().size() < 1)
	{

		out << endl << "Currently, you have no registered semesters. So, no data can be shown.";

	}
	else
	{

		out << endl << "Total Credits: " << CachedCredits << endl;
		out << "Total Grade Points Earned: " << CachedGradePoints << endl;
		out << "Cumulative GPA: " << CachedGradePoints / CachedCredits << endl;

	}

	out << endl << endl << "1. Back To Main Menu" << endl;
	in >> i;
	out << endl;
	ActiveMenuCode = MainMenu;
	AwaitKey(U, true);

}

// HandleInput(U, out, in) handles menu code input initiated from
// enumeration declaration, MainMenu.
void HandleInput(const User& U, ostream& out, istream& in)
{

	unsigned int i;
	in >> i;

	if (i <= 0 || i > 5)
	{

		if (i != 6)
		{

			out << "Unrecognized menu code." << endl << endl;

		}
		else
		{

			out << endl << "Exiting application." << endl << endl;

		}

		exit(0);

	}
	else
	{

		if (i == 1)
		{

			ShowSemesterList(U);

		}
		else if (i == 2)
		{

			unsigned int code;
			out << endl << "Semesters can be viewed through menu code (1). Classes are associated with a one-based" << endl;
			out << "position. For example, you can view the class list associated with semester one by typing: '1'." << endl;
			in >> code;

			if (code > U.GetSemesterList().size() || code <= 0)
			{

				out << endl << "Unrecognized semester." << endl;

			}
			else
			{

				const Semester& S = U.FindSemester(code);
				CachedSemester = S;
				ShowClassList(U, S);

			}
		}
		else if (i == 3)
		{

			ActiveMenuCode = SemesterMenu;
			HandleSemesterInput(U, out, in);

		}
		else if (i == 4)
		{

			ActiveMenuCode = StatisticsMenu;
			HandleEnrollmentInput(U, out, in);

		}
		else if (i == 5)
		{

			ActiveMenuCode = AboutMenu;
			HandleAboutInput(U, out, in);

		}
	}

	AwaitKey(U);

}

// Main() is the execution point of this program.
int main()
{

	User U;
	BuildGradingChart(GradingScale);
	TraceInputMenu();
	HandleInput(U);
	cin.get();
	return 0;

}