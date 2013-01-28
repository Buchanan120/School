// Josephus.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
};

void addPrisoner(Node *head, Node *tail, int value);
Node * executePrisoner (Node *head, Node *deleteMe);

void main() {
	// Set up structure of linked list
	Node *head = new Node();
	Node *tail = new Node();
	head->next = tail;
	tail->next = head;

	// Declarations
	int nPrisoners;
	int nSkip;

	// Set up linked list
	cout << "How many prisoners?\n";
	cin >> nPrisoners;
	cout << "How many to skip?\n";
	cin >> nSkip;
	for(int i = 0; i < nPrisoners; i++)
		addPrisoner(head, tail, i+1);

	// Make the list circular
	// point last element before tail to element after head
	Node *temp = head;
	while (temp->next != tail)
		temp = temp->next;
	temp->next = head ->next;
	delete tail;

	// Execute prisoners until there is only one left
	int nPrisonersLeft = nPrisoners;
	Node *current = head->next;
	while(nPrisonersLeft != 1) {
		for(int i = 0; i < (nSkip - 1); i++)
			current = current->next;
		current = executePrisoner(head, current);
		nPrisonersLeft--;
	}

	// Output
	cout << endl << "I'd say that in this case, you probably want to be prisoner number "
		 << head->next->data << endl;

	// Clean up
	delete head;
}

void addPrisoner(Node *head, Node *tail, int value) {
	Node *temp = head;
	while (temp->next != tail) {
		temp = temp->next;
	}
	temp->next = new Node();
	temp->next->data = value;
	temp->next->next = tail;
}

Node * executePrisoner (Node *head, Node *deleteMe) {
	Node *temp = head;
	while (temp->next != deleteMe) 
		temp = temp->next;
	temp->next = deleteMe->next;
	return temp->next;
}