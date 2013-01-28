// Node.cpp
// Logic for the Node class

#include "Node.h"
#include <iostream>
using namespace std;

Node::Node() {
	value = 0;
	head = NULL;
}

void Node::addEdge(int from, int to){
	Edge *current;
	current = head;
	if (this->value == from) {
		// add a new edge to linked list
		// return
	}
	while (current != NULL) {
		addEdge(current->linkTo, to);
		current = current->next;
	}
}

void Node::print(Node * head) {
	Edge *current;
	current = this->head;
	cout << this->head->value << endl;
	while (current != NULL) {
		print(current->linkTo);
		current = current->next;
	}
	
}