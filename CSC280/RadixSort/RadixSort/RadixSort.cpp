#include <iostream>
#include <queue>
#include <ctime>
#include <cmath>
using namespace std;

void RadixSort(int numbers[], int length) {
	// Create all of the bins.
	queue<int> one;
	queue<int> zero;
	// From the least significant digit to the most significant digit
	for(int i = 0; i < 16; i++)	{
		for(int j = 0; j < length; j++) {
			// if numbers[i] contains a 1 at the j'th bit
			//		push it into one
			//		else push it into zero
			(numbers[j] & ((int)pow(2.0, i))) ?	one.push(numbers[j]) : zero.push(numbers[j]);
		}

		int index = 0;
		while(!zero.empty()) {
			numbers[index++] = zero.front();
			zero.pop();
		}
		while(!one.empty()) {
			numbers[index++] = one.front();
			one.pop();
		}
	}
}

int main() {
	int length = 3000;
	srand(time(NULL));
	int numbers[3000];

	cout << sizeof(int) << endl;

	for(int i = 0; i < length; i++) {
		numbers[i] = rand()%  100;
	}

	for(int i = 0; i < length; i++) {
		cout << numbers[i];
		if(i < length - 1)
			cout << ", ";
		else
			cout << endl;
	}

	RadixSort(numbers, length);

	for(int i = 0; i < length; i++) {
		cout << numbers[i];
		if(i < length - 1)
			cout << ", ";
		else
			cout << endl;
	}

	return 0;
}

