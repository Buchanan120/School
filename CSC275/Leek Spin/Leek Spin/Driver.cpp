// each class gets its own two files: header files for definitions,
	// cpp file for implementations
#include <iostream>
using namespace std;

#include "MyClass.h"

int main() {
	// default constructor
	// mci is a MyClass of int
	MyClass<int> mci;
	mci.SetValue(111);
	cout << mci.GetValue() << "\n\n";
	return 0;
}