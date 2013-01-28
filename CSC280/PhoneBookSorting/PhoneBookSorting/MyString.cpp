#include "MyString.h"
#include <cstring>

 
/*****************************************************************************\
 *	Rules of good conduct:
 *		Everything is two ints and a char pointer.
 *		First int is capacity of string.  Second is length of string.
 *		_string[_length] is always a null
\*****************************************************************************/
 
 
// CONSTRUCTORS
 
	// Default constructor
		// Initialized capacity to 16 chars,
		// Initializes this MyString to an empty MyString
MyString::MyString() {
	_capacity = 16 ;
	// This many chars into your array, there had better be a null char.
	_length = 0;
	_string = new char[_capacity + 1] ; //Allocates new char array on heap to 
										//	_capacity + 1 for \0 terminator
	_string[_length] = '\0'; // Sets last char in array to terminator
}
 
	// parameterized constructors
		// takes a c style string argument
		// initializes capacity to greater of strlen(cString) or 16 chars
		// initializes this MyString to cString
MyString::MyString(const char *aCString) {
	int numCharsToCopy = strlen(aCString) ;
	if (numCharsToCopy > 16)		// Sets the capacity to the greater of 16 
									//	or the length of the string.
		_capacity = numCharsToCopy ; 
	else
		_capacity = 16 ;
 
	_length = numCharsToCopy ;	// Set _length to the number of characters 
									// in aCString
	_string = new char[_capacity + 1] ;	// Initialize to empty char array on 
											//	stack with null terminator 
											//	at _capacity + 1
 
	strcpy(_string, aCString) ;	// Copy aCString into _string on stack
 
	_string[_length] = '\0' ;	// Sets last char in array to terminator
}
 
		// takes an int argument
		// initializes capacity to numChars chars
		// initializes this MyString to an empty MyString
MyString::MyString(int NumChars) {
	// Check for negative NumChars
	if(NumChars < 0)
		throw std::runtime_error("RAGEQUIT Negative string length given.") ;
 
	_capacity = NumChars ;
	_length = 0 ;
	_string = new char[_capacity + 1] ;	//Allocates new char array on heap to 
										//	_capacity + 1 for \0 terminator
	// This many chars into your array, there had better be a null char.
 
	_string[_length] = '\0' ;	// Sets last char in array to terminator
}
 
	// copy constructor
		// initializes this MyString to a deep copy of the original
MyString::MyString(const MyString &original) {
	_capacity = original._capacity ;	// Copy capacity from original
	_length = original._length ;	// Copy length from original
	_string = new char[_capacity + 1] ;
	strcpy(_string, original._string) ;	// Copy string contents from original
										// Default copy constructor points
										//	to the _string being copied
 
	_string[_length] = '\0' ;	// Sets last char in array to terminator
}
 
// DESTRUCTOR
	// deallocate dynamic storage
MyString::~MyString() {
	delete[] _string ;
}
 
// METHODS
 
	// Append
		// Takes a MyString argument
		// Appends chars to the end of this MyString
void MyString::Append(const MyString &aMyString) {
	MyString bMyString = MyString(aMyString);// prevent self-dereferencing
	int totalLength = _length + bMyString._length;
	if (_capacity < totalLength) {
		_capacity = totalLength;
		char *oldString = new char[_capacity + 1];
		strcpy(oldString, _string);
		delete[] _string;
		_string = oldString;
	}
	strcat(_string, bMyString._string);
	_length = totalLength;
	_string[_length] = '\0';
}
 
		// Takes  a c style string argument
		// Appends chars to the end of this MyString
void MyString::Append(const char *aCString) {
	int totalLength = _length + strlen(aCString);
	if (_length < totalLength) {
		_capacity = totalLength;
		char * oldString = new char[_capacity + 1];
		strcpy(oldString, _string);
		delete[] _string;
		_string = oldString;
	}
	strcat(_string, aCString);
	_length = totalLength;
	_string[_length] = '\0';
}
 
	// Assign
		// Takes a MyString argument
		// makes this MyString a copy of aMyString
void MyString::Assign(const MyString &aMyString) {
	MyString bMyString = MyString(aMyString); // prevent self-dereferencing
	delete[] _string;
	_capacity = bMyString._capacity ;	// Copy capacity from aMyString
	_length = bMyString._length ;	// Copy length from aMyString
	_string = new char[_capacity + 1] ;
	strcpy(_string, bMyString._string) ;	// Copy string contents from 
											//	aMyString
	_string[_length] = '\0' ;	// Sets last char in array to terminator
}
 
		// Takes  a c style string argument
		// makes this MyString contain the chars of aCString
void MyString::Assign(const char *const aCString) {
	// Two ints and a pointer!
	// There'd better be a null char at index _length
 
	// strlen does not count the null char.
	int numCharsToCopy = strlen(aCString) ;
 
	if (numCharsToCopy > _capacity)	{
		// Cap'n, we need more capacity!
		_capacity = numCharsToCopy ;	
		// Deallocate old array
		delete[] _string ;
 
		// Allocate new memory
		_string = new char[_capacity + 1] ;
	}
 
	// strcpy copy will copy the null char.
	strcpy(_string, aCString) ;
 
	// Set the length.
	_length = numCharsToCopy ;
}
 
	// At
		// Takes an int argument
		// Returns a copy of the char at that index
		// throws an exception if index is < 0 or >= _length
char MyString::At(int index) const {
	if (index < 0) 
		throw std::runtime_error("RAGEQUIT Index given is less than 0.") ;
	else if (index >= _length) 
		throw std::runtime_error("RAGEQUIT Index given is greater than _length") ;
	char charAtIndex = _string[index] ;
	return charAtIndex ;
}
 
	// Clear
		// Makes this MyString empty
		// does not change capacity;
void MyString::Clear() {
	_length = 0;
	_string[_length] = '\0';
}
 
	// Makes this MyString empty
		// changes capacity to newCapacity
		// throws an exception if newCapacity < 0
void MyString::Clear(int newCapacity) {
	if (newCapacity < 0)
		throw std::runtime_error("RAGEQUIT newCapacity given is less than 0");
	_length = 0;
	_capacity = newCapacity;
	_string[_length] = '\0';
}
 
	// Compare
		// Takes a MyString argument
		// Returns (zero) if the argument contains
		//   the same string of chars as this MyString
		// Returns (a positive int) if the argument is
		//   alphabetically less than this MyString
		// Returns (a negative int) if the argument is
		//   alphabetically greater than this MyString
int MyString::Compare(const MyString &aMyString) {
	return strcmp(_string, aMyString._string);
}
 
	// Equals
		// Takes a MyString argument
		// Returns (true) if the argument contains
		//   the same string of chars as this MyString,
		//   otherwise it returns (false).
bool MyString::Equals(const MyString & aMyString) const {
	if (aMyString._length != _length)
		return false;
	for (int i = 0; i < aMyString._length; i++) {
		if (_string[i] != aMyString._string[i])
			return false;
	}
	return true;
}
 
	// Takes a c style string argument
		// Returns (true) if the argument contains
		//   the same string of chars as this MyString,
		//   otherwise it returns (false).
bool MyString::Equals(const char *const aCString) const {
	MyString aMyString(aCString);
	if (aMyString._length != _length)
		return false;
	for (int i = 0; i < aMyString._length; i++) {
		if (_string[i] != aMyString._string[i])
			return false;
	}
	return true;
}
 
	// Find
		// Takes a myString argument
		// Returns the index (int)
		//   where the argument MyString was found
		//   in this MyString. If it is not found, then returns -1.
int MyString::Find(const MyString &aMyString) const {
	int index = 0;
	if (aMyString._length == 0 || aMyString._length > _length)
		return -1;
	bool isFound = true;
	for (int i = 0; i < _length; i++) {
		isFound = true;
		for (int j = 0; j < aMyString._length; j++) {
			if (_string[i+j] != aMyString._string[j]) {
				isFound = false;
				break;
			}
		}
		if (isFound)
			return i;
	}
	if (!isFound)
		return -1;
}
 
	// Insert
		// Takes two arguments
		// An int – the index in this MyString
		//   at which to insert the new chars
		// A MyString containing the chars to be inserted
void MyString::Insert(const MyString & aMyString, int index) {
	if(index > _length)
		throw std::runtime_error("RAGEQUIT index is greater than Length()");
	if(index < 0)
		throw std::runtime_error("RAGEQUIT index is less than zero");
 
	MyString bMyString = aMyString;
 
	MyString returnString = MyString();
	MyString subString = MyString(SubStr(index, _length - index));
 
	returnString.Assign(SubStr(0, index));
	returnString.Append(bMyString);
	returnString.Append(subString);
 
	Assign(returnString);
 
}
 
	// Length
		// Returns the number (int) of chars in this MyString
int MyString::Length(void) const {
      return _length;
}
 
	// Replace
		// Takes three arguments
		// An int – the index of the char in thisMyString
		//   to begin replacing at.
		// An int – the number of chars to replace
		// And a MyString containg the replacement string
		// throws an exception if startIndex >= Length
		// throws an exception if startIndex + numChars > Length()
		// throws an exception if aMyString.Length() < numChars
void MyString::Replace(int startIndex, int numChars, const MyString & aMyString) {
	int totalLength = _capacity;
 
	// Exception handling
	if (startIndex >= _length)
		throw std::runtime_error("RAGEQUIT startIndex >= Length()");
	else if (startIndex + numChars > _length)
		throw std::runtime_error("RAGEQUIT startIndex + numChars > Length()");
	else if (aMyString._length < numChars)
		throw std::runtime_error("RAGEQUIT aMyString.Length() < numChars");
 
	// check to see if _capacity is insufficent
	if (aMyString._length > _capacity) {
		totalLength = aMyString._length + _capacity;
		_capacity = totalLength;
		MyString temp(*this);
		delete [] _string;
		_string = new char [_capacity + 1];
		// restore string to old value. We use the CString to preserve the new _capacity
		Assign(temp._string); 
	}
 
	for (int i = 0; i < numChars; i++) // repace the chars we wanted
		_string[i + startIndex] = aMyString[i];
 
}
 
	// Substr
		// Takes two int arguments,
		// An int for the starting index,
		// An int for the number of chars to return.
		// Returns a MyString with the requested sub-string
		//   from the original MyString
		// throws an exception if startIndex + numChars > Length()
MyString MyString::SubStr(int startIndex, int numChars) const {
	if (startIndex + numChars > _length)
		throw std::runtime_error("RAGEQUIT startIndex + numChars > Length()");
 
	char *stringAtIndex = new char[numChars+1];
	for(int i = 0; i < numChars; i++) {
		stringAtIndex[i] = _string[startIndex + i];
	}
	stringAtIndex[numChars] = '\0';
	MyString returnString(stringAtIndex);
	delete[] stringAtIndex;
	return returnString;
}
 
// OPERATORS
 
	// = (assignment - takes a MyString or a c style string)
MyString MyString::operator = (const MyString & aMyString) {
	Assign(aMyString._string) ;
	return *this ;
}
MyString MyString::operator = (const char *  const aCString) {
	Assign(aCString) ;
	return *this ;
}
 
	// +, += (concatenation - takes a MyString or a c style string)
MyString MyString::operator + (const MyString & aMyString) {
	MyString current;
	current.Append(this->_string);
	current.Append(aMyString);
	return current;
}
 
MyString MyString::operator += (const MyString & aMyString) {
	this->Append(aMyString);
	return *this;
}
 
	// [] (read/write char access by index)
		// Returns a reference to the char at that index
		// throws an exception if index is < 0 or >= _length
char & MyString::operator [] (int index) const {
	if (index < 0)
		throw std::runtime_error("RAGEQUIT index is < 0");
	if (index >= _length)
		throw std::runtime_error("RAGEQUIT index is >= _length");
	return _string[index];
}
 
	// >, <, >=, <=, ==, != (boolean relational test operators)
bool MyString::operator > (const MyString & aMyString) {
	int result = Compare(aMyString);
	if (result == 1 && _string != aMyString._string)
		return true;
	else
		return false;
}
 
bool MyString::operator < (const MyString & aMyString) {
	int result = Compare(aMyString);
	if (result == -1 && _string != aMyString._string)
		return true;
	else
		return false;
}
 
bool MyString::operator >= (const MyString & aMyString) {
	int result = Compare(aMyString);
	if (result == 1)
		return true;
	else
		return false;
}
 
bool MyString::operator <= (const MyString & aMyString) {
	int result = Compare(aMyString);
	if (result == -1)
		return true;
	else
		return false;
}
 
bool MyString::operator == (const MyString & aMyString) {
	if (Equals(aMyString))
		return true;
	else
		return false;
}
 
bool MyString::operator != (const MyString & aMyString) {
	if (Equals(aMyString)){
		return false;
	}else
		return true;
}
 
 
	// <<, >> stream insertion and extraction
ostream & operator << (ostream &os, const MyString &aMyString) {
	// Insert the string into the stream.
	os << aMyString._string ;
 
	// Pass the stream on.
	return os;
}
 
istream & operator >> (istream &is, MyString &aMyString) {
	char buffer[80];
	aMyString.Clear();
	if (is.peek() != '\n') {
		do{
			// get up to 79 chars at a time
			is.get(buffer, 80);
			// append them to the aMyString
			aMyString.Append(buffer);
		}while((int) strlen(buffer) == 79);
	}	
	if (is.peek() == '\n')
		is.get(); // remove the trailing null char
	return is;
}