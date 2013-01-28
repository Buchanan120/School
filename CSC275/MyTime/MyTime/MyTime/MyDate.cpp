// MyDate.cpp

#include "MyDate.h"

// CONSTRUCTORS
	// default: sets date to jan 1, year 1
	MyDate::MyDate() {
		_days = 0;
	}
	// Parameterized constructors
	MyDate::MyDate(int day, int month, int year) {

	}
	// sets date to 'days' days from jan 1 year 1
	MyDate::MyDate(int days) {
		_days = days;
	}
	// Copy constructor
	MyDate::MyDate(MyDate & aMyDate) {
		_days = aMyDate._days;
	}

// METHODS

	static bool IsLeapYear(MyDate & aMyDate);
	static bool IsLeapYear(int year);
	// returns true if the current instance is a leapyear
	bool IsLeapYear();

	// Accessors and mutators for:
		// day, month, and year

	// returns int day of month
	int GetDay() {
		return this._days;
	}

	// sets day of month (1-31)
	void SetDay(int newDay) {
		_days = newDay;
	}