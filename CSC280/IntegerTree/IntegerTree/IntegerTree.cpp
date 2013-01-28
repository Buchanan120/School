#include <iostream>
#include "Node.h"
#include "Edge.h"

using namespace std;

int main() {
	Node *root = new Node();
	root->value = 42;

	int value;
	int parent;
	
	while (true) {
		root->print();
		cout << "Enter the value you would like to insert into the tree.\n";
		cin >> value;
		cout << "Enter the parent you would like.";
		cin >> parent;
		root->addEdge(parent, value);
	}

	return 0;
}
