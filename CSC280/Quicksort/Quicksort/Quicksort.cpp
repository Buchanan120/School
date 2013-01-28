#include <iostream>
#include <ctime>

using namespace std;

class Node {
public:
	int value;
	Node *next;
	Node *previous;
};

void addNode(Node *tail, int newValue);
void moveNode(Node *moveMe, Node *afterMe);
void printList(Node *head, Node *tail);
int quicksort(Node *head, Node *tail);
int optimizedQuicksort(Node *head, Node *tail, int length);
int insertionSort(Node *head, Node *tail);

void main() {
	srand(time(NULL));

	Node *head1 = new Node();
	Node *tail1 = new Node();
	head1->next = tail1;
	tail1->previous = head1;

	Node *head2 = new Node();
	Node *tail2 = new Node();
	head2->next = tail2;
	tail2->previous = head2;

	for (int i = 0; i < 100000; i++) {
		int value = rand() % 100;
		addNode(tail1, value);
		addNode(tail2, value);
	}


	int quicksortComparisons = quicksort(head1, tail1);

	

	int optimizedComparisons = optimizedQuicksort(head2, tail2, 100000);
	//printList(head2, tail2);

	double improvement = (quicksortComparisons - optimizedComparisons) / quicksortComparisons;
	cout << optimizedComparisons << " " << quicksortComparisons << endl;;
	cout << "Optimization improved the comparison count by:\n" << improvement / 1. << "%";
	delete head1;
	delete tail1;
	delete head2;
	delete tail2;
}

void addNode(Node *tail, int newValue){
	Node *temp = tail->previous;
	temp->next = new Node();
	// value
	temp->next->value = newValue;
	// next
	temp->next->next = tail;
	// previous
	temp->next->previous = tail->previous;
	tail->previous = temp->next;


}

void moveNode(Node *moveMe, Node *afterMe) {
	Node *temp = moveMe;
	// Change previous pointer on temp->next
	temp->next->previous = temp->previous;
	// change next pointer on temp->previous
	temp->previous->next = temp->next;
	
	// change next pointer on temp
	temp->next = afterMe->next;
	// change previous pointer on temp->next
	temp->next->previous = temp;
	
	// change next pointer on afterMe
	afterMe->next = temp;
	// change previous pointer on temp
	temp->previous = afterMe;
}

void printList(Node *head, Node *tail) {
	Node *temp = head->next;
	while (temp != tail) {
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

int quicksort(Node *head, Node *tail) {
	Node *pivot = tail->previous;
	Node *temp = head;
	if (head->next == tail) return 1;

	int comparisons = 0;

	comparisons++;
	while (temp->next != pivot){
		comparisons++;
		if (temp->next->value > pivot->value) {
			moveNode(temp->next, pivot);
		} else {
			temp = temp->next;
		}
	}

	comparisons += quicksort(head, pivot);
	comparisons += quicksort(pivot, tail);

	return comparisons;
}

int optimizedQuicksort(Node *head, Node *tail, int length) {
	Node *pivot = tail->previous;
	Node *temp = head;
	int pivotIndex = length - 1;

	if (head->next == tail) return 1;

	int comparisons = 0;
	int listLength = 0;

	// if  statement
	comparisons++;
	if (length > 15) {
		// first check of the while
		comparisons++;
		while (temp->next != pivot){
			comparisons++;
			if (temp->next->value > pivot->value) {
				moveNode(temp->next, pivot);
				pivotIndex--;
			} else {
				temp = temp->next;
			}
		} 
	} else {
		comparisons += insertionSort(head, tail);
	}
		
	comparisons += optimizedQuicksort(head, pivot, pivotIndex);
	comparisons += optimizedQuicksort(pivot, tail, length - pivotIndex - 1);

	return comparisons;
}

int insertionSort (Node *head, Node *tail) {
	Node *index = head->next;
	Node *toBeSorted = index->next;
	bool sorted = false;
	int comparisons = 0;
	while (index->next != tail) {
		while (!sorted) {
			if (toBeSorted->value > toBeSorted->previous->value) {
				comparisons++;
				moveNode(toBeSorted->previous, toBeSorted);
			}else
				sorted = true;
		}
		index = index->next;
	}
	return comparisons;
}