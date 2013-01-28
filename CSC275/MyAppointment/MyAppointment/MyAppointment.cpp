// MyAppointment.h
//	MyAppointment is an appointment keeper application

#include <iostream>
#include <fstream>
#include "MyAppointment.h"
#include "MyArray.h"
#include "MyDate.h"
#include "MyString.h"
#include "MyTime.h"

using std::cin;
using std::cout;
using std::endl;


	MyAppointment::MyAppointment()
	{
		_title.Clear();
		_description.Clear();
		inDateRange = false;
	}

	MyAppointment::~MyAppointment()
	{
	}

// METHODS

	// GetTitle
	MyString MyAppointment::GetTitle()
	{
		return _title;
	}

	// SetTitle
	void MyAppointment::SetTitle()
	{
		MyString newTitle;
		cin >> newTitle;
		_title.Assign(newTitle);
	}

	// SetTitle
	void MyAppointment::SetTitle(MyString newTitle)
	{
		_title.Assign(newTitle);
	}

	// GetDescription
	MyString MyAppointment::GetDescription()
	{
		return _description;
	}

	// SetDescription
	void MyAppointment::SetDescription()
	{
		MyString newDescription;
		cin >> newDescription;
		_description.Assign(newDescription);
	}

	// SetDescription
	void MyAppointment::SetDescription(MyString newDescription)
	{
		_description.Assign(newDescription);
	}

	// GetDate
	MyDate MyAppointment::GetDate()
	{
		return _date;
	}

	// GetDays
	int MyAppointment::GetDateSerial()
	{
		return _date.GetDateSerial();
	}

	// SetDate
	void MyAppointment::SetDate()
	{
		MyDate newDate;
		cin >> newDate;
		_date.SetDate(newDate);
	}

	// SetDate
	void MyAppointment::SetDate(MyDate newDate)
	{
		_date.SetDate(newDate);
	}

	// GetTime
	MyTime MyAppointment::GetTime()
	{
		return _time;
	}

	//GetTimeSerial
	long MyAppointment::GetTimeSerial()
	{
		return _time.GetTicks();
	}

	// SetTime
	void MyAppointment::SetTime()
	{
		MyTime newTime;
		cin >> newTime;
		_time.SetTime(newTime);
	}

	// SetTime
	void MyAppointment::SetTime(MyTime newTime)
	{
		_time.SetTime(newTime);
	}

	// Display
		// Outputs a formatted MyAppointment object
	void MyAppointment::Display()
	{
		cout << endl;
		cout << GetTitle() << endl;
		cout << GetDate() << "\t" << GetTime() << endl;
		cout << "\t" << GetDescription() << endl;
	}
	