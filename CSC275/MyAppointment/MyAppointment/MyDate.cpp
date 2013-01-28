// MyDate.cpp

#include "MyDate.h"
#include <ctime>

	const int MyDate::numDaysToMonth[14] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	
// UTILITY FUNCTIONS
	// you might want to create some utility functions

	// return number of leap years since year 0
	//int MyDate::GetLeapYears(int year) {
	//	int year = this->GetYear();
	//	int leapYearCount = (year / 4) - (year / 100) + (year / 400);
	//	return leapYearCount;
	//}
	int MyDate::GetLeapYears(int year) {
		int leapYearCount = (year / 4) - (year / 100) + (year / 400);
		return leapYearCount;
	}
	int MyDate::GetLeapYears(MyDate & aMyDate) {
		int year = aMyDate.GetYear();
		int leapYearCount = (year / 4) - (year / 100) + (year / 400);
		return leapYearCount;
	}
	// return number of days in month
	int MyDate::DaysInThisMonth() {
		switch(GetMonth()) {
			case Jan:
			case Mar:
			case May:
			case Jul:
			case Aug:
			case Oct:
			case Dec:
				return 31;
				break;
			case Apr:
			case Jun:
			case Sep:
			case Nov:
				return 30;
				break;
			case Feb:
				if(this->IsLeapYear())
					return 29;
				else
					return 28;
				break;
		}

	}
	int MyDate::DaysInThisMonth(int month) {
		if (month > 12)
			throw std::runtime_error("REDALERT Month must be between 1 and 12 (Jan-Dec)");
		switch(month) {
			case Jan:
			case Mar:
			case May:
			case Jul:
			case Aug:
			case Oct:
			case Dec:
				return 31;
				break;
			case Apr:
			case Jun:
			case Sep:
			case Nov:
				return 30;
				break;
			case Feb:
				if(this->IsLeapYear())
					return 29;
				else
					return 28;
				break;
		}

	}
	int MyDate::DaysInThisMonth(MyDate & aMyDate) {
		switch(aMyDate.GetMonth()) {
			case Jan:
			case Mar:
			case May:
			case Jul:
			case Aug:
			case Oct:
			case Dec:
				return 31;
				break;
			case Apr:
			case Jun:
			case Sep:
			case Nov:
				return 30;
				break;
			case Feb:
				if(this->IsLeapYear())
					return 29;
				else
					return 28;
				break;
		}

	}

	int MyDate::NumDaysToYear(int year) {
		if (year == 0)
			return 0;
		int numLeapYears = year / 4 - year / 100 + year / 400;
	    
		return (year * 365 + numLeapYears);
	}

// CONSTRUCTORS
	// Default constructor
		// sets date to jan 1, year 1
	MyDate::MyDate() {
		_days = 0;
	}
	// Parameterized constructors
		// Day, month, year
	MyDate::MyDate(int day, int month, int year) {
		// Adjust for year offset
		year--;
		if (day < 0 || month < 0 || year < 0)
			throw std::runtime_error("REDALERT All arguments must be positive.");
		if (month > 12) {
			year += month / 12;
			month = month % 12;
		}
		if (day > DaysInThisMonth(month)) {
			while (day > DaysInThisMonth(month)) {
				month++;
				day -= DaysInThisMonth();
			}
		}
		int daysFromMonth = numDaysToMonth[month];
		
		_days = 0;
		_days += day;
		_days += daysFromMonth;
		_days += (year * 365 + GetLeapYears(year));
	}

		// sets date to 'days' days from jan 1 year 1
	MyDate::MyDate(int days) {
		if (days < 0)
			throw std::runtime_error("REDALERT days must be positive.");
		_days = days;
	}
		// Copy constructor
	MyDate::MyDate(MyDate & aMyDate) {
		_days = aMyDate._days;
	}

 //METHODS

	// IsLeapYear
		// Takes the year and calculates whether or not
		// it is a leap year.
	bool MyDate::IsLeapYear(MyDate & aMyDate) {
		int year = aMyDate.GetYear();

		if ( (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) )
			return true;
		else
			return false;
	}
	bool MyDate::IsLeapYear(int year) {
		if ( (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) )
			return true;
		else
			return false;
		
	}
		// returns true if the current instance is a leapyear
	bool MyDate::IsLeapYear() {
		int year = this->GetYear();

		if ( (year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0) )
			return true;
		else
			return false;
	}

	// Accessors and mutators for:
		// day, month, and year

	// GetDay
		// returns int day of month
	int MyDate::GetDay() {
		int year = GetYear();
		int month = GetMonth();

		int result = _days - NumDaysToYear(year);
		result -= numDaysToMonth[month];
		if (IsLeapYear(GetYear() + 1) && GetMonth() > 2)
			result++;

		if (result == 0)
			result++;
		return result;

/*
	int result = _days - NumDaysToYear(GetYear());
		result -= numDaysToMonth[GetMonth()];
		if (IsLeapYear(GetYear() + 1) && GetMonth() > 2)
			result++;

		// Adjust for loss of day on the first of some months
		if (result == 0) result++;
		return result;
*/
	}

	// SetDay
		// sets day of month (1-31)
	void MyDate::SetDay(int newDay) {
		_days -= GetDay();
		_days += newDay;
	}

	// GetMonth
		// returns int month of year ( jan = 1 dec = 12)
	int MyDate::GetMonth() {
		int year = GetYear();
		int days = NumDaysToYear(year);
		// how many days into the current year are we
		days = _days - days; 

		// if January
		if (days < 31) return Jan;
		// Leap year
		if (IsLeapYear(year)) {
			if (days < 60) return Feb;
			if (days < 91) return Mar;
			if (days < 121) return Apr;
			if (days < 152) return May;
			if (days < 182) return Jun;
			if (days < 213) return Jul;
			if (days < 244) return Aug;
			if (days < 274) return Sep;
			if (days < 305) return Oct;
			if (days < 335) return Nov;
			if (days < 366) return Dec;
		} 
		// regular year
		else {
			if (days < 59) return Feb;
			if (days < 90) return Mar;
			if (days < 120) return Apr;
			if (days < 151) return May;
			if (days < 181) return Jun;
			if (days < 212) return Jul;
			if (days < 243) return Aug;
			if (days < 273) return Sep;
			if (days < 304) return Oct;
			if (days < 334) return Nov;
			if (days < 365) return Dec;
		}
	}

	// SetMonth
		// Takes an int argument
		// sets month of year ( jan = 1 dec = 12)
	void MyDate::SetMonth(int newMonth) {
		int oldMonth = GetMonth();
		int year = GetYear() + 1;
		// remove _days for old month
		_days -= numDaysToMonth[oldMonth];
		if (oldMonth > 2 && IsLeapYear(year))
			_days--;
		// add _days for new month
		_days += numDaysToMonth[newMonth];
		if (newMonth > 2 && IsLeapYear(year))
			_days++;
	}

	// GetYear
		// returns int year
	int MyDate::GetYear() {
		// Sets year to lower than it probably is by assuming each year is a leap year
		int year = _days / 366;
		// Gets number of days from epoch to that year
		int testDays = NumDaysToYear(year + 1);

		// Increment year until testDays at least match _days
		while (testDays <= _days) {
			++year;
			testDays = NumDaysToYear(year + 1);
		}
	    
		return year;
	}

	// SetYear
		// sets the year of the current date
	void MyDate::SetYear(int newYear) {
		int year = GetYear();
		// remove old years
		_days = _days - (year * 365);
		_days = _days - (this->GetLeapYears(year));

		// add new years
		_days = _days + newYear * 365;
		_days = _days + GetLeapYears(newYear);
	}

	// GetDayName
		// writes a cstring representation
		// of the current day of the week to dayBuffer
	void MyDate::GetDayName(char * dayBuffer) {
		char dayNames [7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday",
			"Friday", "Saturday", "Sunday"};
		strcpy(dayBuffer, dayNames[_days % 7]);
	}
	// GetMonthName
		// writes a cstring representation
		// of the current month of the year to monthBuffer
	void MyDate::GetMonthName(char * monthBuffer) {
		char monthNames [12][10] = {"January", "February", "March", "April",
			"May", "June", "July", "August", "September", "October", 
			"November", "December"};
		strcpy(monthBuffer, monthNames[GetMonth() - 1]);
	}

	//GetDateSerial
		// returns number of days since jan 1 year 1 for current instance date
	int MyDate::GetDateSerial() const {
		return _days;
	}

	// SetDate (various useful overloads)
		// Days
	void MyDate::SetDate(int days) {
		if(days < 0)
			throw std::runtime_error("REDALERT days must be a positive int.");
		_days = days;
	}
		// Day, Month Year
	void MyDate::SetDate(int newDay, int newMonth, int newYear) {
		if (newDay < 0 || newMonth < 0 || newYear < 0)
			throw std::runtime_error("REDALERT All arguments must be positive.");
		if (newDay > DaysInThisMonth()) {
			while (newDay > DaysInThisMonth(newMonth)) {
				newMonth++;
				newDay -= DaysInThisMonth();
			}
		}
		if (newMonth > 12) {
			newYear += newMonth / 12;
			newMonth = newMonth % 12;
		}
		int daysFromMonth = 0;
		 
		daysFromMonth = numDaysToMonth[newMonth];
		if (newMonth > 2 && IsLeapYear(newYear))
			daysFromMonth++;
		
		_days = 0;
		_days += newDay;
		_days += daysFromMonth;
		_days += (newYear * 365 + GetLeapYears(newYear));
	}
		// MyDate
	void MyDate::SetDate(const MyDate & aMyDate) {
		_days = aMyDate._days;
	}

	// Now
		// a static function that returns a MyDate object
		// initialized to the current date according to the system clock
	MyDate MyDate::Now() {
		// get time from system clock
		time_t rawtime;
		time(& rawtime);
		struct tm * timeinfo;
		timeinfo = localtime(& rawtime);

		// plug it into a MyDate object
		MyDate currentDate(timeinfo->tm_mday, (timeinfo->tm_mon + 1), (timeinfo->tm_year + 1900));

		return currentDate;
	}

	// Add (various useful functions)
		//	For adding amounts of time to this MyDate
	
		// Years
	void MyDate::AddYears(int moreYears) {
		_days += (GetLeapYears(moreYears) - GetLeapYears(this->GetYear()));
		_days += moreYears * 365;
		
	}
		// Months
	void MyDate::AddMonths(int moreMonths) {
		for (int i = 0; i < moreMonths; i++) {
			_days += DaysInThisMonth((GetMonth() + i) % 12);
		}
	}
		// Day
	void MyDate::AddDays(long moreDays) {
		_days += moreDays;
	}
		// MyDate
	void MyDate::AddDate(const MyDate & aMyDate) {
		_days += aMyDate._days;
	}

	// Compare
		// Takes a MyDate argument
		// Returns (zero) if the argument has the same time as this MyDate
		// Returns (a positive int)  if the argument is before this MyDate
		// Returns (a negative int)  if the argument is after this MyDate
	int MyDate::Compare(const MyDate & aMyDate) const {
		if (aMyDate._days == _days)
			return 0;
		else if (_days > aMyDate._days)
			return 1;
		else
			return -1;
	}

	// Equals
		// Takes a MyDate argument
		// Returns (true) if the argument has the same time
		// as this MyDate, otherwise it returns (false).
	bool MyDate::Equals(const MyDate & aMyDate) const {
		if (_days == aMyDate._days) 
			return true;
		else
			return false;
	}

	// Subtract (various useful functions)
		// Years
	void MyDate::SubtractYears(int lessYears) {
		_days -= (GetLeapYears(this->GetYear()) - GetLeapYears(lessYears));
		_days -= lessYears * 365;
	}
		// Months
	void MyDate::SubtractMonths(int lessMonths) {
		if (lessMonths > GetMonth()){
			lessMonths -= GetMonth();
			if (IsLeapYear() && GetMonth() > 2)
				_days--;
			_days -= (numDaysToMonth[GetMonth()]);
		}
		
		for (int i = 0; i < lessMonths; i++) {
			_days -= DaysInThisMonth((GetMonth() - i) % 12);
		}
	}
		// Days
	void MyDate::SubtractDays(long lessDays) {
		if(lessDays > _days)
			throw std::runtime_error("REDALERT Cannot subtract more days than are in the date");
		_days -= lessDays;
	}
		// MyDate
	void MyDate::SubtractDate(const MyDate & aMyDate){
		if(aMyDate._days > _days)
			throw std::runtime_error("REDALERT Cannot subtract more days than are in the date");
		_days -= aMyDate._days;
	}

// OVERLOADED OPERATORS
 
	// = (assignment - takes a MyDate)
	MyDate MyDate::operator= (const MyDate & aMyDate) {
		SetDate(aMyDate);
		return *this;
	}
 
	// +, += (Addition - takes a MyDate)
	MyDate MyDate::operator+ (const MyDate & aMyDate) const {
		MyDate current;
		current.AddDays(this->_days);
		current.AddDays(aMyDate._days);
		return current;
	}
	MyDate MyDate::operator+= (const MyDate & aMyDate) {
		AddDate(aMyDate);
		return *this;
	}
 
	// >, <, >=, <=, ==, != (boolean relational test operators)
	bool MyDate::operator< (const MyDate & aMyDate)  const {
		int result = Compare(aMyDate);
		if (result == -1)
			return true;
		else 
			return false;
	}
	bool MyDate::operator> (const MyDate & aMyDate)  const {
		int result = Compare(aMyDate);
		if (result == 1)
			return true;
		else 
			return false;
	}
	bool MyDate::operator>= (const MyDate & aMyDate)  const {
		int result = Compare(aMyDate);
		if (result == -1 || result == 0)
			return true;
		else 
			return false;
	}
	bool MyDate::operator<= (const MyDate & aMyDate)  const {
		int result = Compare(aMyDate);
		if (result == 1 || result == 0)
			return true;
		else 
			return false;
	}
	bool MyDate::operator== (const MyDate & aMyDate)  const {
		int result = Compare(aMyDate);
		if (result == 0)
			return true;
		else 
			return false;
	}
	bool MyDate::operator!= (const MyDate & aMyDate)  const {
		int result = Compare(aMyDate);
		if (result != 0)
			return true;
		else 
			return false;
	}

	// <<, >> stream insertion and extraction
	ostream & operator<< (ostream & os, MyDate & aMyDate) {
		if (aMyDate.GetDay() < 10)
			os << "0";
		os << aMyDate.GetDay() << "/";
		if (aMyDate.GetMonth() < 10)
			os << "0";
		os << aMyDate.GetMonth() << "/";
		if ((aMyDate.GetYear() + 1) < 10) {
			os << "000";
		} else if ((aMyDate.GetYear() + 1) < 100) {
			os << "00";
		} else if ((aMyDate.GetYear() + 1) < 1000) {
			os << "0";
		}
		os << (aMyDate.GetYear() + 1);
		return os;
	}

	// date must be one of these formats
		// DD/MM/YYYY
		// DD.MM.YYYY
		// DD[any symbol]MM[any symbol]YYYY
	istream & operator>> (istream & is, MyDate & aMyDate) {
		// Override whatever is currently in there
		aMyDate.SetDate(0);

		int inputDay;
		int inputMonth;
		int inputYear;

		is >> inputDay;

		// ignore any symbol
		if (!(is.peek() < 48 || 57 < is.peek() < 65)) {
			is.clear();
			is.sync();
			throw std::runtime_error("REDALERT Invalid input (Missing first symbol)");
		} else
			is.get();

		is >> inputMonth;

		if (inputDay < 1 || inputDay > aMyDate.DaysInThisMonth(inputMonth)) {
			is.clear();
			is.sync();
			throw std::runtime_error("REDALERT Invalid input (Day)");
		}

		aMyDate.SetDay(inputDay);
		if (inputMonth < 1 || inputMonth > 12) {
			is.clear();
			is.sync();
			throw std::runtime_error("REDALERT Invalid input (Month)");
		}

		aMyDate.SetMonth(inputMonth);

		// ignore any symbol
		if (!(is.peek() < 48 || 57 < is.peek() < 65 || 90 < is.peek() < 97)) {
			is.clear();
			is.sync();
			throw std::runtime_error("REDALERT Invalid input (Missing second symbol)");
		} else
			is.get();

		is >> inputYear;

		if (inputYear < 0) {
			is.clear();
			is.sync();
			throw std::runtime_error("REDALERT Invalid input (Year)");
		}
		
		aMyDate.SetYear(inputYear);

		if (is.peek() == '\n')
			is.get();
		
		return is;
	}