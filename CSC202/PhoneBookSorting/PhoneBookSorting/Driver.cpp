#include <iostream>
#include <vector>
#include "MyString.h"

using namespace std;

void main() {
	MyString firstName = new MyString[];
	MyString lastName = new MyString[];
	MyString phoneNumber = new MyString[];

	int i;

	while (firstName != "DONE") {
		cout << "Please input the following values.\n";
		cout << "Enter \"DONE\" in First Name space when finished.";
		cout << "First Name:\n";
		cin >> firstName[i];
		cout << "Last Name:\n";
		cin >> lastName[i];
		cout << "Phone Number (XXX-XXX-XXXX)";
		i++;
	}

	for(int j = 0; j < i - 1; j++) {
		MyString phoneBook[j](lastName[j] + " " + firstName[j] + " " + phoneNumber[j]);
	}

	insertionSort(phoneBook[], i - 1);

	for(int j = 0; j < i - 1; j++) {
		cout << phoneBook[j] << "\n";
	}
}

void insertionSort (MyString[] aMyString, int length) {
	for(int i = 0; i < length; i++) {
		int j = i;
		while(j > 0 && aMyString[j - 1] > aMyString[j]) {
			MyString tempMyString(aMyString[j]);
			aMyString[j] = aMyString[j - 1];
			aMyString[j - 1] = tempMyString;
			j--;
		}
	}
}