#include <iostream>
#include <vector>
#include "MyString.h"
#include <cstring>

using namespace std;

void insertionSort (MyString aMyString[10], int length) {
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

void main() {
	MyString firstName[10];
	MyString lastName[10];
	MyString phoneNumber[10];

	int i = 0;

	MyString checkDone(4);
	bool exit = false;
	while (i < 10 && !exit) {
		cout << "Please input the following values.\n";
		cout << "Enter \"DONE\" in First Name space when finished.\n";
		cout << "First Name:\n";
		cin >> checkDone;
		if (checkDone == "DONE") {
			exit = true;
			continue;
		}
		firstName[i] = checkDone;
		cout << "Last Name:\n";
		cin >> lastName[i];
		cout << "Phone Number (XXX-XXX-XXXX)\n";
		cin >> phoneNumber[i];
		i++;
	}

	MyString phoneBook[10];

	for(int j = 0; j < i; j++) {
		// lastName, firstName - phoneNumber
		phoneBook[j].Append(lastName[j]);
		phoneBook[j].Append(", ");
		phoneBook[j].Append(firstName[j]);
		phoneBook[j].Append(" - ");
		phoneBook[j].Append(phoneNumber[j]);
	}

	insertionSort(phoneBook, i);

	system("cls");	
	cout << "Sorted Phone Book:\n";
	for(int j = 0; j < i; j++) {
		cout << phoneBook[j] << "\n";
	}
}

