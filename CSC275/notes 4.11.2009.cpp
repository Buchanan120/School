#include <iostream>
using namespace std;

// We use "T" because it stands for type
template <class T>
// This is not a function.  Will not run without the "template <class T>" line.
// It is a function template
// Not a complete function because it doesn't define data types.
// takes two "T"s and returns one "T".
T Biggest (T val1, T val2) {
	if (val1 > val2)
		return val1;
	else 
		return val2;
}

int Biggest (int val1, int val2) {
	if (val1 > val2)
		return val1;
	else 
		return val2;
}

// T is convention when templating for single type
	// other types usually S, but could be others or given a meaningful name
template <typename T>
T Biggest(T arr[], int size) {
	T biggestSoFar = arr[0];

	for(int i = 0; i < size; i++) {
		if (arr[i] > biggestSoFar)
			biggestSoFar = arr[i];
	}

int main() {
	// Compiler uses the template to write the int Biggest(int val1, int val2)
		// function based on the template
	int i = Biggest(1,2);

	cout << "Biggest(1,2) = " << Biggest(1,2) << endl;
	cout << "Biggest(2,1) = " << Biggest(2,1) << endl;
	// writes a Biggest using double
	cout << "Biggest(1.1,2.2) = " << Biggest(1.1,2.2) << endl;
	// writes a Biggest using char
	cout << "Biggest('a','b') = " << Biggest('a','b') << endl;
	// writes a Biggest using char*, but it will use memory addresses instead of 
		// ascii values for the comparison
	cout << "Biggest(\"Bob\", \"Carl\") = " << Biggest("Bob", "Carl") << endl;

	int iarr[] = {2 4 6 8 0 9 7 5 3 1};
	int biggest = Biggest(iarr, 10);
	cout << "biggest = " << biggest << "\n\n";

	return 0;
}

#include <iostream>
using namespace std;

template <class T, int z>
int Foo(T t) {
	//return t * z;
	for (int i = 0; i < z; i++)
		cout << t << ", ";
}

template <class T, class V>
void Goo(T t, V v) {
	cout << t << endl;
	cout << v << endl;
}

int main() {
	Foo<int, 5>(10);
	
	Goo(3,5.5);
	Goo("Hi!", false);
	return 0;
}