// MyTime.cpp

#include "MyTime.h"
#include <ctime>
// CONSTRUCTORS
 
	// Default (explicit)
	MyTime::MyTime() {
		_ticks = 0;
	}

	// Copy
	MyTime::MyTime(const MyTime & origMyTime) {
		MyTime thisMyTime(origMyTime._ticks);
		_ticks = thisMyTime._ticks;
	}

	// Parameterized (various useful overloads)
		// Hours, Minutes, Seconds, Miliseconds
	MyTime::MyTime(int initHours, int initMinutes, int initSeconds, int initMilisecs) {
		if (initHours < 0 || initMinutes < 0 || initSeconds < 0 || initMilisecs < 0) 
			std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += (initHours * _ticksPerHour);
		_ticks += (initMinutes * _ticksPerMinute);
		_ticks += (initSeconds * _ticksPerSecond);
		_ticks += initMilisecs;
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
	
		// Hours, Minutes, Seconds
	MyTime::MyTime(int initHours, int initMinutes, int initSeconds) {
		if (initHours < 0 || initMinutes < 0 || initSeconds < 0) 
			std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += initHours * _ticksPerHour;
		_ticks += initMinutes * _ticksPerMinute;
		_ticks += initSeconds * _ticksPerSecond;
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
	
		// Hours, Minutes
	MyTime::MyTime(int initHours, int initMinutes) {
		if (initHours < 0 || initMinutes < 0) 
			std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += initHours * _ticksPerHour;
		_ticks += initMinutes * _ticksPerMinute;
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
	
		// Ticks
	MyTime::MyTime(long initTicks) {
		if (initTicks < 0) 
			std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = initTicks;
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
	
 
// DESTRUCTOR

      MyTime::~MyTime() {

	  }
	  
// METHODS
 
	// Accessors and mutators for:
		// hours, minutes, seconds, ticks
	int MyTime::GetHours() const {
		return _ticks / _ticksPerHour;
	}
	void MyTime::SetHours(int newHours) {
		_ticks = _ticks - ((_ticks / _ticksPerHour) * _ticksPerHour);
		_ticks += _ticksPerHour * newHours;
	}
	
	int MyTime::GetMinutes() const {
		int theseTicks = _ticks;
		theseTicks = theseTicks % _ticksPerHour;	// Ticks for hours are discarded
		theseTicks = theseTicks / _ticksPerMinute;  // Tics for seconds and individual ticks are dropped.
		return theseTicks;
	}
	void MyTime::SetMinutes(int newMinutes) {
		int oldMinutes = (_ticks % _ticksPerHour); // Ticks for hours are discarded
		oldMinutes = oldMinutes / _ticksPerMinute; // Ticks for seconds and individual are discarded
		_ticks = _ticks - (oldMinutes * _ticksPerMinute); // Ticks for minutes are removed from _ticks
		_ticks = _ticks  + (newMinutes * _ticksPerMinute);
	}
	
	int MyTime::GetSeconds() const {
		int theseTicks = _ticks;
		theseTicks = theseTicks % _ticksPerMinute;  // Everything greater than seconds are discarded
		theseTicks = theseTicks / _ticksPerSecond; // individual ticks dropped
		return theseTicks;
	}
	void MyTime::SetSeconds(int newSeconds) {
		int oldSeconds = _ticks;
		oldSeconds = oldSeconds % _ticksPerMinute;
		oldSeconds = oldSeconds - (oldSeconds / _ticksPerSecond);
		_ticks = _ticks - (oldSeconds * _ticksPerSecond);
		_ticks = _ticks + (newSeconds * _ticksPerSecond);
	}
 
	long MyTime::GetTicks() const {
		return _ticks;
	}
	void MyTime::SetTicks(int newTicks) {
		_ticks = newTicks;
	}

	// SetTime (various useful overloads)
		// Hours, Minutes, Seconds, Miliseconds
	void MyTime::SetTime(int newHours, int newMinutes, int newSeconds, int newMilisecs) {
		if (newHours < 0 || newMinutes < 0 || newSeconds < 0 || newMilisecs < 0) 
			std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += (newHours * _ticksPerHour);
		_ticks += (newMinutes * _ticksPerMinute);
		_ticks += (newSeconds * _ticksPerSecond);
		_ticks += newMilisecs;
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Hours, Minutes, Seconds
	void MyTime::SetTime(int newHours, int newMinutes, int newSeconds) {
		if (newHours < 0 || newMinutes < 0 || newSeconds < 0) 
			std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += newHours * _ticksPerHour;
		_ticks += newMinutes * _ticksPerMinute;
		_ticks += newSeconds * _ticksPerSecond;
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Hours, Minutes
	void MyTime::SetTime(int newHours, int newMinutes) {
		if (newHours < 0 || newMinutes < 0) 
			std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += newHours * _ticksPerHour;
		_ticks += newMinutes * _ticksPerMinute;
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Ticks
	void MyTime::SetTime(long newTicks) {
		if (newTicks < 0) 
			std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = newTicks;
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// MyTime
	void MyTime::SetTime(const MyTime & aMyTime) {
		_ticks = aMyTime._ticks;
	}

	// Now
		// a static function that returns a MyTime object
		// initialized to the current time according to the system clock
	static MyTime Now() {
		long theseTicks = time(NULL);
		theseTicks = theseTicks % _ticksPerDay;
		MyTime aMyTime(theseTicks);
		return aMyTime;	
	}

	// Add (various useful methods)
		// For adding amounts of time to this MyTime

		// Hours
	void MyTime::AddHours(int moreHours) {
		_ticks += (moreHours * _ticksPerHour);
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Minutes
	void MyTime::AddMinutes(int moreMinutes) {
		_ticks += (moreMinutes * _ticksPerMinute);
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Seconds
	void MyTime::AddSeconds(long moreSeconds) {
		_ticks += (moreSeconds * _ticksPerSecond);
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Ticks
	void MyTime::AddTicks(long moreTicks) {
		_ticks += moreTicks;
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// MyTime
	void MyTime::AddTime(const MyTime & aMyTime) {
		_ticks += aMyTime._ticks;
		if (_ticks > _lastTickOfTheDay)
			std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
 
	// Compare
		// Takes a MyTime argument
		// Returns (zero) if the argument has the same time as this MyTime
		// Returns (a positive int)  if the argument is before this MyTime
		// Returns (a negative int)  if the argument is after this MyTime
	int MyTime::Compare(const MyTime & aMyTime) const {
		if (_ticks == aMyTime._ticks)
			return 0;
		else if (_ticks >= aMyTime._ticks)
			return 1;
		else 
			return -1;
	}

	// Equals
		// Takes a MyTime argument
		// Returns (true) if the argument has the same time
		//   as this MyTime, otherwise it returns (false).
	bool MyTime::Equals(const MyTime & aMyTime) const {
		MyTime thisMyTime(_ticks);
		if (thisMyTime._ticks == aMyTime._ticks)
			return true;
		else
			return false;
	}
 
	// Subtract (various useful methods)
		// For subtracting amounts of time to this MyTime  

		// Hours
	void MyTime::SubtractHours(int lessHours) {
		_ticks -= (lessHours * _ticksPerHour);
		if (_ticks < 0)
			std::runtime_error("REDALERT _ticks less than 0");
	}
		// Minutes
	void MyTime::SubtractMinutes(int lessMinutes) {
		_ticks -= (lessMinutes * _ticksPerMinute);
		if (_ticks < 0)
			std::runtime_error("REDALERT _ticks less than 0");
	}
		// Seconds
	void MyTime::SubtractSeconds(long lessSeconds) {
		_ticks -= (lessSeconds * _ticksPerSecond);
		if (_ticks < 0)
			std::runtime_error("REDALERT _ticks less than 0");
	}
		// Ticks
	void MyTime::SubtractTicks(long lessTicks) {
		_ticks -= lessTicks;
		if (_ticks < 0)
			std::runtime_error("REDALERT _ticks less than 0");
	}
		// MyTime
	void MyTime::SubtractTime(const MyTime & aMyTime) {
		_ticks -= aMyTime._ticks;
		if (_ticks < 0)
			std::runtime_error("REDALERT _ticks less than 0");
	}

	//// OVERLOADED OPERATORS
 //
	//// = (assignment - takes a MyTime)
	//MyTime MyTime::operator= (const MyTime & aMyTime) {
	//}

	//// +, += (Addition - takes a MyTime)
	//MyTime MyTime::operator+ (const MyTime & aMyTime) const {
	//}
	//MyTime MyTime::operator+= (const MyTime & aMyTime);

	//// >, <, >=, <=, ==, != (boolean relational test operators)
	//bool MyTime::operator> (const MyTime & aMyTime) const ;
	//bool MyTime::operator< (const MyTime & aMyTime) const ;
	//bool MyTime::operator>= (const MyTime & aMyTime) const ;
	//bool MyTime::operator<= (const MyTime & aMyTime) const ;
	//bool MyTime::operator== (const MyTime & aMyTime) const ;
	//bool MyTime::operator!= (const MyTime & aMyTime) const ;

	//// <<, >> stream insertion and extraction
	//friend ostream & operator<< (ostream & os, const MyTime & aMyTime);
	//friend istream & operator>> (istream & is, MyTime & aMyTime);


	
