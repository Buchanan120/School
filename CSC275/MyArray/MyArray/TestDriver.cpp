#include "MyArray.h"

#include <iostream>
using namespace std;

void main() {
	MyArray<int> a1;
	MyArray<int> a2(12);
	MyArray<int> a3(a1);

	for(int i = 0; i < 5; i++) {
		a1.Add(i);
		a2.Add(i*3);
		a3.Add(i%2);
	}

	cout << "a1.At(1) = " << a1.At(1) << endl;
	cout << "a2.At(1) = " << a2.At(1) << endl;
	cout << "a3.At(1) = " << a2.At(1) << endl;

	cout << "a2.Add(45): Found at index: ";
	a2.Add(45);
	cout << a2.Find(45) << endl;


	a2.Insert(42, 5);
	cout << "a2.Insert(42, 5): Found " << a2[5] << " at index " << a2.Find(42) << endl;
	cout << "Old value at index 5 bumped to " << a2.Find(45) << endl;
	a2.RemoveAt(5);
	cout << "a2.Remove(5): Found 45 at index: " << a2.Find(45) << endl;

	a2.SetValue(300, 0);
	cout << "a2.SetValue(300): a2[0] == " << a2[0] << endl;

	cout << "Searching for nonexistant value 222: "
		<< a2.Find(222) << " (-1 == not found)" << endl;

	a1 = a2;
	if(a1 == a2)
		cout << "= and == both working" << endl;
	else
		cout << "= and/or == are broken." << endl;

	if(a1 != a2)
		cout << "Something is wrong with !=" << endl;
	else
		cout << "If the previous test passed, != is also working." << endl;

}