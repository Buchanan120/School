// Edge.h
// Defines the Edge class.

#pragma once
#ifndef _EDGE_H_
#define _EDGE_H_
#include "Node.h"

class Edge {
public:
	Node *linkTo;
	Edge *next;

	Edge();
};
#endif