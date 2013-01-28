//For different value assignment location, good for consts try
#include <iostream>
#include <stdexpect>
#using namespace std;

class MyClass
{
private: 
	int m_value;
	const int m_constValue; // = 99;   Can't do this.
	int & m_refValue; // this and const have to be initialized when constructed but not in the body since C++ wants pre-built by the constructor executes
public:
	MyClass() : m_constValue(99), m_refValue(m_value)
	{
		m_value = 0;
	}
}

class OddException : public runtime_error
{
public:
	OddException() : runtime_error("Even where odd expected."); {}
	OddException(char * message) : runtime_error(message); {}
};


int AddOnlyOddInts(int odd1, int odd2)
{
	if(odd1%2 && odd2 % 2)
		return odd1+odd2;

	//cout only makes sense because it's a console application
	//cout << "Error!  odd1 and odd2 must both be odd numbers"

	//You can throw anything, but don't be arbitrary
	//throw 1;
	//throw "Odd Exception.  Even where odd expected.";
	//throw invalid_argument("Odd1 and Odd2 must be Odd.");
	throw OddException;
	//Usually good to derive from runtime_error
}

int main()
{
	int x = 1;
	int y = 2;

	try 
	{
		cout << AddOnlyOddInts(x,y) << endl;
	}
	catch(...) //... means catch everything
	{
		cout << "Something bad happened somewhere." << endl;
	}

	try 
	{
		cout << AddOnlyOddInts(x,y) << endl;
	}
	catch(int e)
	{
		cout << "Caught : " << e << endl;
	}
	catch(exception & e)
	{
		cout << "Caught : " << e.what() << endl;
	}
	

	return 0;
}


//More notes

int main()
{
	int a[] = {11,22,33,44,55};
	for(int i = 0; i <5; i++)
	{
		cout << a[i] << ", ";
	}

	cout << a[2] << "\n"; // 33
	cout << a << "\n";  //Shows address of first element
	cout << a+1 << "\n";  //Shows address of second element, 4 bytes more
	cout << &(a[0]) << "\n";  // Shows address of first element
	cout << *a << "\n";   //Shows value at first element

	cout << a[1] << "\n"; // shows value at second element
	cout << *(a+1) << "\n";   //Shows value at second element

	cout << *(1+a) << "\n"; //Shows value at first element
	cout << 1[a] << "\n"; // Shows value at first element
	cout << "\n\n";
	// endl is more expensive, forces Windows to clear the screen

	int * ia = new int[3];
	//int * ia = new int[0];
	ia[0] = 33;
	cout << ia[0;]

	for(int i = 0; i < 3; i++)
		ia[i] = i*2;

	for(int i = 0; i < 3; i++)
		cout << "ia[i] = " << ia[i] << "\n";

	delete [] ia;

	return 0;
}

//stream overload notes

//Overloaded output operator to easily output instances of MyString
ostream & operator<< (ostream & os, const MyString & aMyString)
{
	os << aMyString._string; 
	return os;
}

//Overloaded input operator to easily create instances of MyString
istream & operator>> (istream & is, MyString & aMyString)
{
	//create a buffer to grab input
	char buffer[80] = {'\0'};  //initializes the rest to null, works like 0's for ints or something
	//clear the aMyString
	aMyString.Clear();
	//start getting the chars from the input stream
	if(is.peek() != '\n')
	{
		do 
		{
			//get up to 79 chars
			is.get(buffer, 80);
			//append these chars t aMyString
			aMyString.Append(buffer);
			//continue to read input while still chars input stream
		} while (int)strlen(buffer) == 79);
	}

	if(is.peek() == '\n')
	{
		is.get(); //pull that newline char out of the input stream
	}
	//return this input stream for chaining calls
	return is;
}

class MyClass
{
public:
	MyClass();
	void MemberFunction();
	static void StaticFunction();
	int memberVariable;
	static int staticVariable;
	const int constMemberVariable; //= 99; // can't do this here
	static const int staticConstMemberVariable; //can be initialized here
	static const float staticFConstMemberVariable;
};
//int MyClass::memberVariable = 99;
//int MyClass::constMemberVariable = 99;
static const float MyClass::staticFConstMemberVariable = 99.9;  // has to be done here
int MyClass::staticVariable = 99;
const int MyClass::staticConstMemberVariable = 99;

MyClass::MyClass() : constMemberVariable(99)
{

}

void MyClass::MemberFunction(/*MyClass* this*/)
{
	cout << "MemberFunction::memberVariable = "
		<< this->memberVariable << endl;
	cout << "MemberFunction::staticVariable = "
		<< MyClass::staticVariable << endl;
}

void MyClass::StaticFunction()
{
	cout << "MemberFunction::staticVariable = "
		<< MyClass::staticVariable << endl;

	//cout << "MemberFunction::memberVariable = "
	//	<< this->memberVariable << endl;
	//illegal reference to non static member with memberVariable
	//Static per class, all objects share the exact same value
	//Statics don't have this pointers
	//Doesn't get a this pointer
	//
}
int main()
{

	MyClass m1;
	m1.MemberFunction();
	m1.StaticFunction();
	//MemberFunction(&m1); 
	//Essentially m1. does ^^^ this

	//char s1[] = "Bob";
	//char s2[] = "Bob";
	//char * cp = &s1[0];

	//cout << cp << endl;

	//if(s1 == s2)
	//{
	//	cout << s1 << " == "  << s2 << endl;
	//}
	//else
	//{
	//	cout << s1 << " != "  << s2 << endl; //This outputs, char pointers, not dereferenced
	//}
	return 0;
}


#include <ctime>

int main()
{
	//for my Now method
	time_t rawtime;
	time( &rawtime );

	cout << "rawtime = " << rawtime << endl;

	struct tm * timeinfo;

	timeinfo = localtime( &rawtime);

	cout << "h = " << timeinfo->tm_hour << endl;
	cout << "m = " << timeinfo->tm_min << endl;
	cout << "s = " << timeinfo->tm_sec << endl;

	cout << "D = " << timeinfo->tm_mday << endl;
	cout << "M = " << timeinfo->tm_mon << endl;
	cout << "Y = " << timeinfo->tm_year << endl;

	return 0;
}

//for the date class

static bool IsLeapYear(int year)
{
	if(( (year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0) )
		return true;
	else
		return false;
}

int NumDaysToYear(int year)
{
	if(year == 1)
		return 0;
	int numLeapYears = ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400);
	int days = 0;
	days = ((year - 1) * 365) + numLeapYears;

	return days;
}

int NumDaysToYear1(int year)
{
	int days = (year - 1) * 365.2425;

	return days;
}

//Mod 3

//template, for a function
template <class T>
T Biggest(T val1, T val2)
{
	if(val1> val2)
		return val1;
	else
		return val2;
}
//This ends up compiled auto when things are passed as int
//Just an example
//int Biggest(int val1, int val2)
//{
//	if(val1> val2)
//		return val1;
//	else
//		return val2;
//}

int main()
{
	int a,b,c;
	a = 3;
	b = 5;
	c = Biggest(a,b);

	double d = Biggest(3.5,6.1);
	return 0;
}


//template, for a function
template <typename T>
T Biggest(T Tarr[], int size)
{
	T biggestSoFar = Tarr[0];
	for(int i = 0; i < size; i++)
	{
		if(Tarr[i] > biggestSoFar)
			biggestSoFar = Tarr[i];
	}
	return biggestSoFar;
}

int main()
{
	//prevent us from, needs to know at runtime
	int size = 5;
	int myInts[size];

	int iArr[] = {1,2,3,4,5,666,7,8,9,0};
	cout << Biggest(iArr,10) << endl;
	return 0;
}
#include <iostream>
using namespace std;
//public
//protected
//private
class MyBase
{
private:
	//Class itself and friends of the class
	int base_private_int;
protected:
	//Class itself and children
	int base_protected_int;
public:
	//Almost global
	int base_public_int;

	//Taking virtual off makes basePtr go here instead
	//Without virtual, this one shadows inherited one
	//Virtual means derived classes will use their own
	virtual void Public_Method()
	{
		base_private_int = 99;
		base_protected_int = 99;
		base_public_int = 99;
	}

	friend class MyDerived; //Don't do this often, actually ever
};

class MyDerived : public MyBase //use a , to multiple inheritance, public inheritance, default is private
								//
{
private:
	//Not a friend so can't use this
	int derived_private_int;
protected:
	//From parent
	int derived_protected_int;
public:
	//Almost global
	int derived_public_int;

	void Public_Method()
	{
		//base_private_int = 99; //No direct access to private except when made friend
		base_protected_int = 99;
		base_public_int = 99;
	}
};

int main()
{
	MyDerived o;
	MyBase* basePtr = &o;

	//o.base_private_int = 99; // once again this doesn't work, no access to privates
	//o.base_protected_int = 99; // can't do protected from outside
	o.base_public_int = 99;

	//o.derived_private_int = 99; //private members from outside, nope
	//o.derived_protected_int = 99; //outside of class, so nope again
	o.derived_public_int = 99;
	o.Public_Method(); // goes to MyDerived
	basePtr->Public_Method(); //goes to MyDerived method
	o.MyBase::Public_Method(); //Goes to MyBase
	
	return 0;
}

//Notes for mydate
#include <iostream>
using namespace std;


int NumDaysToYear(int year)
{
	if(year == 1)
		return 0;
	int numLeapYears = ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400);
	int days = 0;
	days = ((year - 1) * 365) + numLeapYears;

	return days;
}


int GetYear(int _days)
{
	int year = _days / 366;
	int days = NumDaysToYear(year + 1);
	//Tally up the rest
	while(days <= _days)
	{
		++year;
		if(((year % 4 == 0) && (year % 100 != 0))|| (year % 400 == 0))
		{
			days += 366;
		} else
		{
			days += 365;
		}
	}
	return year;
}

int daysToMonth[] = {0,0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
int GetMonth(int _days)
{
	int year = GetYear(_days);
	int days = _days;

	days -= NumDaysToYear(year);
	//count months into current year
	//	account for leap years
	//	if it's leap year and more than 31+28=59 days into this year
	if(IsLeapYear(year) && days >= 59)
		days -= 1;
	//factor out the days in all expired months
	int month = 1;
	while(daysToMonth[month] <= days)
	{
		++month;
	}

	return month -1;
}

int GetDay(int _days)
{
	int days = _days;
	int year = GetYear(_days);
	days -= NumDaysToYear(year);

	int month = GetMonth(_days);
	//subtract days in expired months
	days -= daysToMonth[month];
	//account for possible leap years
	if(IsLeapYear(year) && month > 2)
		days -= 1;
	return days+1; //days aren't zero based
}



//////////////////////////////////////////////////////////////////////////
//July 8, 2009 templates

//Methods of class templates are function templates themselves
//remember to provide <type> parameter in declaration
//remember <T> next to function declarations

#include <iostream>
using namespace std;


template <class T>
class MyClass
{
private:
	T value1;
public:
	MyClass();
	T GetValue();
	void SetValue(T newValue);
};

template <class T>
MyClass<T>::MyClass()
{
	cout << "ctor " << sizeof(T) << "\n\n";
}

template <class T>
T MyClass<T>::GetValue()
{
	return value1;
}

template <class T>
void MyClass<T>::SetValue(T newValue)
{
	value1 = newValue;
}

int main()
{
		//When debugging, it uses the template as a display
	//Since it's actually doing machine code disassembly
	//And thats ugly

	//Can't declare this like this
	//provide type
	//MyClass mc;
	MyClass<int> mc;
	mc.SetValue(111);
	cout << mc.GetValue() << "\n\n";

	MyClass<int> mc1;
	MyClass<bool> mc2;
	return 0;
}


#include <iostream>
using namespace std;

template <class T, int size>
//template <class T, class Z>
class MyClass
{
public:
	T v[size];
};

int main()
{
	//this works until you pass a variable for size
	MyClass<int, 5> v5;
	MyClass<int,bool> mc1;
	for(int i = 0; i < 5; i++)
	{
		v5.v[i] = 999 + i;
		cout << v5.v[i] << endl;
	}
	
}



#include <iostream>
using namespace std;

template <class T>
class SimpleStack
{
private:
	T* bottomPtr;
	int top;
	const int MAX_SIZE;
	int count;
public:
	SimpleStack(int size) : MAX_SIZE(size)
	{
		bottomPtr = new T[size];
		top = 0;
		count = 0;
	}
	~SimpleStack(){ delete [] bottomPtr;	}
	void Push(T val)
	{
		if(top == MAX_SIZE)
		{
			throw "BOOM!";
		} else
		{
			bottomPtr[top] = val;
			++top; ++count;
		}
	}

	T Pop()
	{
		if(top == 0)
		{
			throw "BOOM!";
		} else
		{
			--top; --count;
			return bottomPtr[top]
		}
	}

	T Peek()
	{
		if(top == 0)
		{
			throw "OUCH!";
		} else
		{
			return bottomPtr[top-1];
		}
	}

	int Count()
	{
		return count;
	}

};

int main()
{
	SimpleStack<int> ssi(5);
	ssi.Push(1);
	ssi.Push(2);
	ssi.Push(3);
	cout << ssi.Count() << endl;
	cout << ssi.Peek() << endl;

	ssi.Pop();
	cout << ssi.Count() << endl;
	cout << ssi.Peek() << endl;

	cout << ssi.Pop() << endl;
	cout << ssi.Pop() << endl;
	cout << ssi.Pop() << endl;
	//Error
	return 0;
}

//////////////////////////////////////////////////////////////////////////
//Vectors
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Foo(int i)
{
	cout << i << "-";
}

//3rd takes pointer to a function, that takes an int, and returns a void...
//void foreach(vector<int>::iterator iter, vector<int>::iterator end, void(*fp)(int))
//{
//	while(iter != end)
//	{
//		fp(*iter++);
//		//or
//		//fp(*iter);
//		//++iter;
//	}
//}

template <class Iter, class Func>
void foreach(Iter iter, Iter end, Func fp)
{
	while(iter != end)
		fp(*iter++);
}

int main()
{
	vector<int> v;
	for(int i = 0; i < 10; i++)
		v.push_back(i);

	foreach(v.begin(),v.end(),Foo);
	//Algorithm class 
	for_each(v.begin(),v.end(),Foo);
	//their for_each returns the function
	(for_each(v.begin(),v.end(),Foo))(999);
	//Array like thing, essentially it is an array, dynamic sizing
	//
	vector<int> v1;
	
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	for(int i = 0; i < v1.size(); i++)
	{
		//at is bound protected, [] isn't
		cout << v1.at(i) << ", ";
		cout << v1[i] << ", ";
	}
	cout << "\n\n";

	cout << v1.front() << endl;
	cout << v1.back() << endl;
	//takes off last element
	v1.pop_back();
	vector<int>::iterator iter;
	for(iter = v1.begin(); iter != v1.end(); ++iter)
	{
		cout << *iter << ", ";
	}
	cout << "\n\n";
	
	
	//////////////////////////////////////////////////////////////////////////



	
	return 0;
}

#include <iostream>
using namespace std;

#include <vector>
#include <iomanip>

template <class T>
class Matrix
{
private:
	vector < vector <T> > _myMatrix;
	unsigned _rows, _cols;
public:
	Matrix(unsigned rows, unsigned cols, T initValue)
	{
		_rows = rows;
		_cols = cols;
		_myMatrix = vector < vector <T> > (rows,vector <T> (cols, initValue));
	}
	int rows() { return _rows;}
	int cols() { return _cols;}

	vector <T>& operator[] (unsigned index)
	{
		return _myMatrix[index];
	}

	T& operator() (unsigned rowIndex, unsigned colIndex)
	{
		if(rowIndex < _rows && colIndex < _cols)
			return _myMatrix[rowIndex][colIndex];
		else
			throw "Matrix subscript out of bounds"
	}
};

int main()
{
	//sets all 3 to 99
	//vector<int> vi(3,99);


	//vector of vectors
	//declare myMatrix to be a 
	//vector of 2 vectors of ints 
	//where each vector of ints is initialized
	//to 7 ints each initialized to 0
	//vector < vector <int> > myMatrix(2, vector<int>(7,0));

	//Now we can do this
	Matrix<int> m(3,4,99);
	for(int row = 0; row < m.rows(); row++)
	{
		for(int col = 0; col < m.cols(); col++)
		{
			//m[row] returns vector of ints, where [col] steps through that returned vector
			m[row][col] = (row*10) + col;
			//Right justifies to 2 character space limitations
			//cout << setw(2) << myMatrix[row][col] << " ";
			cout << setw(2) << m(row,col) << " ";
		}
		cout << "\n";
	}


	return 0;
}

///////////////
// Bad dynamic cast would just return NULL
//

/////////////////////////////////////////////////////Function pointer

#include <iostream>
using namespace std;
#include <climits>
#include <limits>

void Foo()
{
	cout << "Foo" << endl;
}
void Bar()
{
	cout << "Bar" << endl;
}


int main()
{
	cout << numeric_limits<int>::max() << endl;
	cout << numeric_limits<int>::min() << endl;
	cout << numeric_limits<float>::epsilon() << endl;
	cout << numeric_limits<double>::epsilon() << endl;
	//////////////////////////////////////////////////////////////////////////
	void(*fr)(void) = 0 ? Foo : Bar;
	fr();
	fr = Foo;
	fr();
	//

	//////////////////////////////////////////////////////////////////////////
	//Cannot convert without const_cast
	const int i = 1;
	
	int* ip = const_cast<int*>(&i);
	cout << *ip << endl;
	*ip = 99;
	cout << *ip << endl;
	cout << i << endl; //Still returns 1, compiler saves time and just switches i to 1
	return 0;
}


#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
	int age;
	char name[40];
};

int main()
{
	Person people[5] = 
	{ {11,"Al"},{22,"Bob"},{33,"Carl"},{44,"Dan"},{55,"Ed"} }
	ofstream myfile;
	myfile.open("test.txt", ios::out); //ios::out overwrites or creates new on that name
	if(myfile.is_open())
	{
		for(int i = 0; i < 5; i++)
		{
			myfile << people[i].name << " " << people[i].age << "\n";
		}
		myfile.close();
	} else
	{
		cout << "Failed to open file!\n\n";
	}
	return 0;
}

int main()
{
	Person people[5];/* = 
	{ {11,"Al"},{22,"Bob"},{33,"Carl"},{44,"Dan"},{55,"Ed"} }*/
	ifstream myfile;
	myfile.open("test.txt", ios::in); 
	if(myfile.is_open())
	{
		for(int i = 0; i < 5; i++)
		{
			myfile >> people[i].name >> people[i].age;
		}
		myfile.close();
	} else
	{
		cout << "Failed to open file!\n\n";
	}

	for(int i = 0; i < 5; i++)
	{
		cout << people[i].name << " " << people[i].age << "\n";
	}
	return 0;
}


////////////////////////////////////////////////////////////////////////// Binary
#include <iostream>
#include <fstream>
using namespace std;

class Person
{
public:
	int age;
	char name[40];
};

int main()
{
	Person people[5] = 
	{ {11,"Al"},{22,"Bob"},{33,"Carl"},{44,"Dan"},{55,"Ed"} }
	ofstream myfile;
	myfile.open("test.bin", ios::out | ios::binary); //bit flags,
	if(myfile.is_open())
	{
		//for(int i = 0; i < 5; i++)
		//{
		//	myfile.write((char*)&people[i].name, sizeof(Person)); //40x 1 byte, and int is 1 x 4 bytes
		//}
		myfile.write((char*)&people, sizeof(Person) *5)
		myfile.close();
		////////////////////////////////////////////////////////////////////////// click drag into VS and look
	} else
	{
		cout << "Failed to open file!\n\n";
	}
	return 0;
}

int main()///read binary
{
	Person people[5];
	ifstream myfile;
	myfile.open("test.bin", ios::in | ios::binary); //bit flags,
	if(myfile.is_open())
	{
		for(int i = 0; i < 5; i++)
		{
			myfile.read((char*)(&people[i]), sizeof(Person)); //40x 1 byte, and int is 1 x 4 bytes
		}
		//myfile.read((char*)&people, sizeof(Person) *5)
			myfile.close();
		////////////////////////////////////////////////////////////////////////// click drag into VS and look
	} else
	{
		cout << "Failed to open file!\n\n";
	}

	for(int i = 0; i < 5; i++)
	{
		cout <<people[i].name << " " << people[i].age << endl;
	}
	return 0;
}

#include <iostream>
using namespace std;

int i = 1;

void Foo()
{
	int i = 2;
	cout << i << endl;
	cout << ::i << endl; //instant access to global scope
}

class MyClass
{
private: 
	mutable int i;
	int j;
	int k;
	int l;
	int m;
public:
	MyClass(int initI) : i(initI)
	{
		
	}
	void Foo() const // const stops changing explicitly except mutable
	{
		i = 99;
		j = 99;  //Doesn't work
	}
};

int main()
{
	Foo();
	int i = 3;
	int j(3);
	return 0;
}

//////////////////////////////////////////////////////////////////////////



#include <iostream>
using namespace std;
#include <string>

class MyClass
{
private: 
	int i;
public:
	MyClass(){	}
	explicit MyClass(int i)
	{
		this->i = i;
		//or
		//(*this).i = i;
	}

	explicit MyClass(bool b) //stops implicit cast
	{
		this->i = 0;
	}

	explicit MyClass(string c) //stops implicit cast
	{
		this->i = 0;
	}

};

int main()
{
	MyClass m;

	m = 3; //implicit cast operation
	m = (MyClass)3; //works
	m = MyClass(3); // works
	m = true;  //dangerous implicit cast
	m = (MyClass)string("Bob"); //works till explicit cast with MyClass
	return 0;
}

//////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;
char* I2X(int I, char*X)
{
	if(I>0XF)X=I2X(I>>4,X);
	return*X++=(I&=0XF)<0XA?'0'+I:I+'7',X;
}

int main()
{
	char buffer[100] = {0};
	I2X(123,buffer); //conversion to hex
	cout << buffer << endl;
	cout << 0XF << endl; // returns 15
	int I = 1024;
	cout << (I>>4) << endl;
	return 0;
}

#include <iostream>
using namespace std;

class Foo
{
public:
	int i;
	//every member function has atleast 1 paremeter, this
	int GetI() {this-> return i;}
	void SetI(int newI){i = newI;}
};
//int i = 0;
//int GetI() {return i;}
int(Foo::*fPtr)() = &Foo::GetI;
///////////////////////////////////////////Pointer to member functions
//Attempt =)
//cdecl... >_>
//

int main()
{
	Foo f;
	f.SetI(99);
	//fPtr = ;//GetI();
	//this works
	//call back function for event driven 
	cout << (f.*fPtr)() << endl;
	
	
	//cout << f.GetI() << endl;
	return 0;
}

int main()
{
	int i = 10;
	int j = ~i; // makes it opposite... subtracts -1
	///2's compliment
	// 1011  
	// 0101
	// subtract
	// 0000
	//char i = 10;
	//char j = ~i; //???
	//unsigned short i = 10;
	//unsigned short j = ~i; // ???
	i = 0;
	while(i < 10)
	{
		cout << i << endl;
		i = -~i;
	}

	i = 10;
	while(i > 0)
	{
		cout << i << endl;
		i = ~-i;
	}
	// i = ~-i; == i = --i
	// i = -~i; == i = ++i
	return 0;
}

//////////////////////////////////////////////////////////////////////////
//Mind map of C++

/*
	Orthodox canonical form =
		default constructor ()
		copy constructor (&)
		overloaded & operator= (const &)
		destructor()
*/


#include <iostream>
#include <vector>
using std::cout;



int main()
{
	//
	return 0;
}


/* Final Exam review
	Opens on Saturday
	54 questions
	Essay questions
	Multiple choice
	T&F
	A prime number is a positive number blah blah, write a C++ function to
		determine if a passed # is a prime number or not. Throw exceptions if
		less than 1, as efficient as possible.
	Overload operators, including stream
	Differences in value parameters
	Private vs. protected members
	Describe purpose and implementation of friend functions
	When overloaded copy constructor are essential
	What the rules are for valid identifier names
	Function prototype
	Spot syntax errors
	Familiar with primitive datatypes, and implicit conversions
	Looping control structures
	C++ supports nested functions?
	Two functions with the same name?
	Pros/cons of global data, diff global consts verse variables
	Declare an Enum
	Function can return an enum?
	Know structs
	What has access to the private members of an object of a class
	What kinda things can a function return
	Whether or not a struct can be a member of another struct
	Whether an array can be a member of a struct
	Similarities between array and pointer notation
	Constructors rules
	28. Datamembers of a class must all be of the same datatype F
	29. The function members ofa class must be public F
	Want to know rules for constructors/destructors
	Want to know if I have a pointer to an object, how can you call member methods of that object
	Identify keywords in C++
	Familiar with c++ and its string stuff
	Default arguments
	Whether or not a string function has a default arguments
	Copy constructor
	When Copy constructor needs to be explicitly defined, and when default copy is ok
	Keyword static, with respect datamembers or functions of a class
	Static members, what can they access, what accesses them
	Keyword friend, what friend functions are about
	44. Keyword friend is included in a friend function definition F
	46. All overloaded operators must be friends of a class F
	Rules for operator overloading
	Inheiritance, what is accessible in the base class
	Template
	Whether or not you can overload function templates
	Standard datatypes for templates?  No  =)
	Define the functions of a class template 
*/

//test driven design
#include <iostream>
#include <vector>
#include <string>
using std::cout;

bool IsFibonacciPrime(int n)
{
	//keeps going onto some crazy huge number from wikipedia
	if(n == 2 || 
	   n == 3 ||
	   n == 5 ||
	   n == 13 ||
	   n == 89 ||
	   n == 233 || 
	   n == 1597 ||
	   n == 28657 ||
	   n == 514229 ||
	   n == 433494437 ||
	   n == 2971215073) // bigger than int
	{
		return true;
	} else
		return false;
}

void AssertEqual(bool expected, bool actual, string message)
{
	if(expected == actual)
		cout << "Passed : " << message << endl;
	else
		cout << "Failed : expected =" << expected 
			<< " but actual =" << actual
			<< "*******" << endl;
	
}

int main()
{
	//test, use wiki pedia
	int n; //can't equal the fibo prime numbers later on, the last one
	AssertEqual(false, IsFibonacciPrime(-2), "Input = -2" << endl;
	AssertEqual(false, IsFibonacciPrime(-1), "Input = -1" << endl;
	AssertEqual(false, IsFibonacciPrime(0), "Input = 0" << endl;
	AssertEqual(false, IsFibonacciPrime(1), "Input = 1" << endl;
	AssertEqual(true, IsFibonacciPrime(2), "Input = 2" << endl;
	AssertEqual(true, IsFibonacciPrime(3), "Input = 3" << endl;
	AssertEqual(true, IsFibonacciPrime(5), "Input = 5" << endl;
	AssertEqual(false, IsFibonacciPrime(7), "Input = 7" << endl;
	AssertEqual(false, IsFibonacciPrime(8), "Input = 8" << endl;
	AssertEqual(true, IsFibonacciPrime(89), "Input = 89" << endl;
	return 0;
}

