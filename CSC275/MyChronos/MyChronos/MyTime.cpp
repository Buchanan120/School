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
			throw std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += (initHours * _ticksPerHour);
		_ticks += (initMinutes * _ticksPerMinute);
		_ticks += (initSeconds * _ticksPerSecond);
		_ticks += initMilisecs;
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
	
		// Hours, Minutes, Seconds
	MyTime::MyTime(int initHours, int initMinutes, int initSeconds) {
		if (initHours < 0 || initMinutes < 0 || initSeconds < 0) 
			throw std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += initHours * _ticksPerHour;
		_ticks += initMinutes * _ticksPerMinute;
		_ticks += initSeconds * _ticksPerSecond;
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
	
		// Hours, Minutes
	MyTime::MyTime(int initHours, int initMinutes) {
		if (initHours < 0 || initMinutes < 0) 
			throw std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += initHours * _ticksPerHour;
		_ticks += initMinutes * _ticksPerMinute;
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
	
		// Ticks
	MyTime::MyTime(long initTicks) {
		if (initTicks < 0) 
			throw std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = initTicks;
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
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
		long theseTicks = _ticks;
		theseTicks = theseTicks % _ticksPerHour;	// Ticks for hours are discarded
		theseTicks = theseTicks / _ticksPerMinute;  // Tics for seconds and individual ticks are dropped.
		return theseTicks;
	}
	void MyTime::SetMinutes(int newMinutes) {
		long oldMinutes = (_ticks % _ticksPerHour); // Ticks for hours are discarded
		oldMinutes = oldMinutes / _ticksPerMinute; // Ticks for seconds and individual are discarded
		_ticks = _ticks - (oldMinutes * _ticksPerMinute); // Ticks for minutes are removed from _ticks
		_ticks = _ticks  + (newMinutes * _ticksPerMinute);
	}
	
	int MyTime::GetSeconds() const {
		long theseTicks = _ticks;
		theseTicks = theseTicks % _ticksPerMinute;  // Everything greater than seconds are discarded
		theseTicks = theseTicks / _ticksPerSecond; // individual ticks dropped
		return theseTicks;
	}
	void MyTime::SetSeconds(int newSeconds) {
		long oldSeconds = _ticks;
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
			throw std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += (newHours * _ticksPerHour);
		_ticks += (newMinutes * _ticksPerMinute);
		_ticks += (newSeconds * _ticksPerSecond);
		_ticks += newMilisecs;
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Hours, Minutes, Seconds
	void MyTime::SetTime(int newHours, int newMinutes, int newSeconds) {
		if (newHours < 0 || newMinutes < 0 || newSeconds < 0) 
			throw std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += newHours * _ticksPerHour;
		_ticks += newMinutes * _ticksPerMinute;
		_ticks += newSeconds * _ticksPerSecond;
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Hours, Minutes
	void MyTime::SetTime(int newHours, int newMinutes) {
		if (newHours < 0 || newMinutes < 0) 
			throw std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = 0;
		_ticks += newHours * _ticksPerHour;
		_ticks += newMinutes * _ticksPerMinute;
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Ticks
	void MyTime::SetTime(long newTicks) {
		if (newTicks < 0) 
			throw std::runtime_error("REDALERT All parameters must be positive.");
		_ticks = newTicks;
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// MyTime
	void MyTime::SetTime(const MyTime & aMyTime) {
		_ticks = aMyTime._ticks;
	}

	// Now
		// a static function that returns a MyTime object
		// initialized to the current time according to the system clock
	MyTime MyTime::Now() {
		// get time from system clock
		time_t rawtime;
		time(& rawtime);
		struct tm * timeinfo;
		timeinfo = localtime(& rawtime);

		// plug it into a MyTime object
		MyTime currentTime(timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

		return currentTime;
	}

	// Add (various useful methods)
		// For adding amounts of time to this MyTime

		// Hours
	void MyTime::AddHours(int moreHours) {
		if (moreHours < 0)
			throw std::runtime_error("REDALERT Argument must be positive.");
		_ticks += (moreHours * _ticksPerHour);
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Minutes
	void MyTime::AddMinutes(int moreMinutes) {
		if (moreMinutes < 0)
			throw std::runtime_error("REDALERT Argument must be positive.");
		_ticks += (moreMinutes * _ticksPerMinute);
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Seconds
	void MyTime::AddSeconds(long moreSeconds) {
		if (moreSeconds < 0)
			throw std::runtime_error("REDALERT Argument must be positive.");
		_ticks += (moreSeconds * _ticksPerSecond);
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// Ticks
	void MyTime::AddTicks(long moreTicks) {

		if (moreTicks < 0)
			throw std::runtime_error("REDALERT Argument must be positive.");
		_ticks += moreTicks;
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
	}
		// MyTime
	void MyTime::AddTime(const MyTime & aMyTime) {
		_ticks += aMyTime._ticks;
		if (_ticks > _lastTickOfTheDay)
			throw std::runtime_error("REDALERT Time too large: must be less than " + _lastTickOfTheDay);
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
		if (lessHours < 0)
			throw std::runtime_error("REDALERT Argument must be positive.");
		_ticks -= (lessHours * _ticksPerHour);
		if (_ticks < 0)
			throw std::runtime_error("REDALERT _ticks less than 0");
	}
		// Minutes
	void MyTime::SubtractMinutes(int lessMinutes) {
		if (lessMinutes < 0)
			throw std::runtime_error("REDALERT Argument must be positive.");
		_ticks -= (lessMinutes * _ticksPerMinute);
		if (_ticks < 0)
			throw std::runtime_error("REDALERT _ticks less than 0");
	}
		// Seconds
	void MyTime::SubtractSeconds(long lessSeconds) {
		if (lessSeconds < 0)
			throw std::runtime_error("REDALERT Argument must be positive.");
		_ticks -= (lessSeconds * _ticksPerSecond);
		if (_ticks < 0)
			throw std::runtime_error("REDALERT _ticks less than 0");
	}
		// Ticks
	void MyTime::SubtractTicks(long lessTicks) {
		if (lessTicks < 0)
			throw std::runtime_error("REDALERT Argument must be positive.");
		_ticks -= lessTicks;
		if (_ticks < 0)
			throw std::runtime_error("REDALERT _ticks less than 0");
	}
		// MyTime
	void MyTime::SubtractTime(const MyTime & aMyTime) {
		_ticks -= aMyTime._ticks;
		if (_ticks < 0)
			throw std::runtime_error("REDALERT _ticks less than 0");
	}

// OVERLOADED OPERATORS
 
	// = (assignment - takes a MyTime)
	MyTime MyTime::operator= (const MyTime & aMyTime) {
		SetTime(aMyTime);
		return *this;
	}

	// +, += (Addition - takes a MyTime)
	MyTime MyTime::operator+ (const MyTime & aMyTime) const {
		MyTime current;
		current.AddTicks(this->_ticks);
		current.AddTime(aMyTime);
		return current;
	}
	MyTime MyTime::operator+= (const MyTime & aMyTime) {
		AddTime(aMyTime);
		return *this;
	}
// Returns (zero) if the argument has the same time as this MyTime
		// Returns (a positive int)  if the argument is before this MyTime
		// Returns (a negative int)  if the argument is after this MyTime
	// >, <, >=, <=, ==, != (boolean relational test operators)
	bool MyTime::operator> (const MyTime & aMyTime) const {
		int result = Compare(aMyTime);
		if (result == -1)
			return true;
		else 
			return false;
	}
	bool MyTime::operator< (const MyTime & aMyTime) const {
		int result = Compare(aMyTime);
		if (result == 1)
			return true;
		else 
			return false;
	}
	bool MyTime::operator>= (const MyTime & aMyTime) const {
		int result = Compare(aMyTime);
		if (result == -1 || result == 0)
			return true;
		else 
			return false;
	}
	bool MyTime::operator<= (const MyTime & aMyTime) const {
		int result = Compare(aMyTime);
		if (result == 1 || result == 0)
			return true;
		else 
			return false;
	}
	bool MyTime::operator== (const MyTime & aMyTime) const {
		int result = Compare(aMyTime);
		if (result == 0)
			return true;
		else 
			return false;
	}
	bool MyTime::operator!= (const MyTime & aMyTime) const {
		int result = Compare(aMyTime);
		if (result != 0)
			return true;
		else 
			return false;
	}

	// <<, >> stream insertion and extraction
	ostream & operator<< (ostream & os, const MyTime & aMyTime) {
	// Insert the ticks into the stream.
		os << aMyTime.GetHours() << ":" << aMyTime.GetMinutes();
		// Only print seconds if there are significant data
		if(aMyTime.GetSeconds() != 0 || aMyTime.GetTicks() % 100 != 0)
			os << ":" << aMyTime.GetSeconds();
		// Only print ticks if there are any
		if(aMyTime.GetTicks() % 100 != 0)
			os << "." << aMyTime.GetTicks() % 100;
 
	// Pass the stream on.
	return os;
	}

	istream & operator>> (istream & is, MyTime & aMyTime){

		// Override whatever is currently in there
		aMyTime.SetTicks(0);

		int inputHours;
		int inputMinutes;
		int inputSeconds;
		int inputTicks;

		is >> inputHours;

		if (inputHours < 0 || inputHours > 23) {
			is.clear();
			is.sync();
			throw std::runtime_error("REDALERT Invalid input (Missing Hours)");
		}

		aMyTime.SetHours(inputHours);

		if (!(is.peek() == ':')) {
			is.clear();
			is.sync();
			throw std::runtime_error("REDALERT Invalid input (Missing first \":\")");
		}
		else
			is.get();
		is >> inputMinutes;

		if (inputMinutes < 0 || inputMinutes > 59) {
			is.clear();
			is.sync();
			throw std::runtime_error("REDALERT Invalid input (Missing Minutes)");
		}

		aMyTime.SetMinutes(inputMinutes);

		if (is.peek() == ':') {
			is.get();
			is >> inputSeconds;

			if (inputSeconds < 0 || inputSeconds > 59) {
				is.clear();
				is.sync();
				throw std::runtime_error("REDALERT Invalid input (Missing Seconds)");
			}
			
			aMyTime.SetSeconds(inputSeconds);
		}

		if (is.peek() == '.') {
			is.get();
			is >> inputTicks;

			if (inputTicks < 0 || inputTicks > 99) {
				is.clear();
				is.sync();
				throw std::runtime_error("REDALERT Invalid input (Missing Ticks)");
			}
			aMyTime.AddTicks(inputTicks);
		}

		if (is.peek() == '\n')
			is.get();
		
		return is;
	}


	
