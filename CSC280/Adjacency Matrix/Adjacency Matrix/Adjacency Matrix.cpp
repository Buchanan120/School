// Adjacency Matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void addEdge(int pAdjMatrix[][6], int v1, int v2)
{
	pAdjMatrix[v1][v2] = 1;
	pAdjMatrix[v2][v1] = 1;
}
void removeEdge(int pAdjMatrix[][6], int v1, int v2)
{
	pAdjMatrix[v1][v2] = 0;
	pAdjMatrix[v2][v1] = 0;
}

void printMat(int pAdjMatrix[][6])
{
	cout << " 012345" << endl;
	for(int i = 0; i < 6; i++)
	{
		cout << i;
		for (int j = 0; j < 6; j++)
		{
			cout << pAdjMatrix[j][i];
		}
		cout << endl;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int adjMatrix[6][6];

	for(int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			adjMatrix[j][i] = 0;
		}
	}
	printMat(adjMatrix);
	cout << endl << endl;

	addEdge(adjMatrix, 4, 5);
	addEdge(adjMatrix, 3, 1);

	printMat(adjMatrix);
	cout << endl << endl;

	removeEdge(adjMatrix, 1, 3);

	printMat(adjMatrix);
	return 0;
}

