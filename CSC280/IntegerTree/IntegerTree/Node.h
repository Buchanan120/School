// Node.h
// Defines the Node class.

#pragma once
#ifndef _NODE_H_
#define _NODE_H_

#include "Edge.h"


class Node {
public:
	int value;
	Edge *head;

	Node();

	void addEdge(int from, int to);
	void print(Node * head);
};
#endif