// MyAppointment.h
//	MyAppointment is an appointment keeper application

// insure taht this header file is not included more than once
#pragma once
#ifndef MYAPPOINTMENT_H_
#define MYAPPOINTMENT_H_

#include "MyAppointment.h"
#include "MyArray.h"
#include "MyDate.h"
#include "MyString.h"
#include "MyTime.h"

using std::ostream;
using std::istream;

class MyAppointment
{
private:
	MyString _title;
	MyString _description;
	MyDate _date;
	MyTime _time;

public:
// CONSTRUCTOR
	MyAppointment();

// DESTRUCTOR
	~MyAppointment();

// METHODS

	// GetTitle
	MyString GetTitle();

	// SetTitle
	void SetTitle();
	void SetTitle(MyString newTitle);

	// GetDescription
	MyString GetDescription();

	// SetDescription
	void SetDescription();
	void SetDescription(MyString newDescription);

	// GetDate
	MyDate GetDate();

	// GetDateSerial
		// Returns days in _date
	int GetDateSerial();

	// SetDate
	void SetDate();
	void SetDate(MyDate newDate);

	// GetTime
	MyTime GetTime();

	// GetTimeSerial
		// Returns ticks in _time
	long GetTimeSerial();

	// SetTime
	void SetTime();
	void SetTime(MyTime newTime);

	// Display
		// Outputs a formatted MyAppointment object
	void Display();

// FIELDS
	bool inDateRange;
};
#endif