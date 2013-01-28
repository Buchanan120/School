// MyDate.cpp

#include "MyDate.h"

// UTILITY FUNCTIONS
	// you might want to create some utility functions

	int NumDaysToYear(int year) {
		if (year == 1)
			return 0;
		int numLeapYears = ((year - 1) / 4)
						 - ((year - 1) / 100)
						 + ((year - 1) / 400);
		365 * (year - 1) + numLeapYears;
	}

// CONSTRUCTORS
	// default: sets date to jan 1, year 1
	MyDate(); 
	MyDate(int day, int month, int year);
	// sets date to 'days' days from jan 1 year 1
	MyDate(int days); 
	// copy constructor
	MyDate(MyDate & aMyDate); 

	bool IsLeapYear (int year) {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			return true;
		else
			return false;
	}

