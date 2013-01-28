#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node *next;
};

void push(Node *head, int i) {
	Node *temp = new Node();
	temp->next = head->next;
	temp->data = i;
	head->next = temp;
}

// Don't call without elements in stack besides head
int pop(Node *head) {
	if (head->next != NULL) {
		int giveThisBack;
		Node *temp = head->next;
		head->next = temp->next;
		giveThisBack = temp->data;
		delete temp;
		return giveThisBack;
	}else
		throw std::runtime_error("RAGEQUIT No elements in stack");
}

void print(Node *head) {
	Node *temp = head ->next;
	while (temp != NULL) {
		cout << temp->data << ",";
		temp = temp->next;
	}
}

int countElementsInStack(Node *head) {
	int count = 0;
	if (head->next != NULL) {
		Node *current = head->next;
		while (current->next != NULL) {
			count++;
		}
	}	
	return count;
}
void showTowers (Node *firstTower, Node *secondTower, Node *thirdTower) {
	cout << "\nFirst Tower: ";
	print(firstTower);
	cout << "\nSecond Tower: ";
	print(secondTower);
	cout << "\nThird Tower: ";
	print(thirdTower);
	cout << endl;
}
void solveTowersOfHanoi(int numDisks, Node *firstTower, Node *thirdTower, Node *secondTower) {
	if (numDisks == 1)
		push(thirdTower, pop(firstTower));
	else {
		solveTowersOfHanoi(numDisks - 1, firstTower, secondTower, thirdTower);
		push(thirdTower, pop(firstTower));
		solveTowersOfHanoi(numDisks-1, secondTower, thirdTower, firstTower);
	}
}

void main() {
	Node *firstTower = new Node();
	Node *secondTower = new Node();
	Node *thirdTower = new Node();
	firstTower->next = NULL;
	secondTower->next = NULL;
	thirdTower->next = NULL;

	for (int i = 0; i < 7; i++) {
		push(firstTower, 7 - i);
	}
	showTowers (firstTower, secondTower, thirdTower);
	//from this *tower, to this *tower, using this *tower.
	solveTowersOfHanoi(7, firstTower, thirdTower, secondTower);
	showTowers (firstTower, secondTower, thirdTower);
}