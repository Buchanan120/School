// I used http://richardbowles.tripod.com/cpp/linklist/linklist.htm
// for a linked list refresher.
#include <iostream>
#include <queue>
using namespace std;

// Here is what I'm putting into my linked list.
struct node
{
	// Vertex being linked to
	int vertexNumber;
	// Pointer to next node
	node * nextNode;
};

class edge
{
public:
	int smallVertex;
	int bigVertex;
	bool isLessThan(edge otherEdge)
	{
		// Return true if firstEdge is smaller than secondEdge
		if(smallVertex < otherEdge.smallVertex)
			return true;
		else if(smallVertex > otherEdge.smallVertex)
			return false;
		else if(smallVertex == otherEdge.smallVertex)
		{
			if(bigVertex < otherEdge.bigVertex)
				return true;
			else if(bigVertex > otherEdge.bigVertex)
				return false;
		}
	}
	bool operator< (const edge & anEdge)
	{
		return isLessThan(anEdge);
	}
};
void addSingleEdge(node* listONodes[], int from, int to)
{
	node* temp;
	node* currentPointer;
	
	temp = new node;
	temp->nextNode = NULL;
	temp->vertexNumber = to;

	if(listONodes[from] == NULL)
	{
		listONodes[from] = temp;
	}
	else
	{
		currentPointer = listONodes[from];

		while(currentPointer->nextNode != NULL)
		{
			currentPointer = currentPointer->nextNode;
		}
		currentPointer->nextNode = temp;
	}
}
void addEdge(node* listONodes[], int v1, int v2)
{
	addSingleEdge(listONodes, v1, v2);
	addSingleEdge(listONodes, v2, v1);
}
void removeSingleEdge(node* listONodes[], int from, int to)
{
	if(listONodes[from] == NULL)
		return;
	node * currentPointer;

	currentPointer = listONodes[from];

	if(currentPointer->vertexNumber == to)
	{
		if(listONodes[from]->nextNode == NULL)
			listONodes[from] = NULL;
		else
			listONodes[from] = currentPointer->nextNode;
	}
	else
	{
		while((currentPointer->nextNode != NULL) && 
			  (currentPointer->nextNode->vertexNumber != to))
		{
			currentPointer = currentPointer->nextNode;
		}
		// Make sure the thing we even want is there
		if(currentPointer->nextNode == NULL)
			return;
		currentPointer->nextNode = currentPointer->nextNode->nextNode;
	}
}
void removeEdge(node* listONodes[], int v1, int v2)
{
	removeSingleEdge(listONodes, v1, v2);
	removeSingleEdge(listONodes, v2, v1);
}

void printList(node* listONodes[], int size)
{
	node* currentPointer = NULL;
	for(int i = 0; i < size; i++)
	{
		cout << i << ": ";

		currentPointer = listONodes[i];
		// Print the nodes linked from here
		while(currentPointer != NULL)
		{
			// Output the current node
			cout << currentPointer->vertexNumber;
			cout << "->";
			// Go to the next node
			currentPointer = currentPointer->nextNode;
		}

		cout << "NULL" << endl;
	}
}

void traverseBreadthFirst(node* listONodes[], int size){
	int * isVisited = new int[size];
	queue<int> nodesToVisit;
	int currentNode;
	node * tempNode;
	bool hasContinuousStructure = false;
	vector<edge> edgesToCheck;
	edge tempEdge;

	// Initialize our array that keeps track of visited nodes
	for(int i = 0; i < size; i++)
		isVisited[i] = 0;

	// For each vertex in out listONodes,
	for(int i = 0; i < size; i++)
	{
		// Add that node to the queue of nodes.
		nodesToVisit.push(i);
		
		edgesToCheck.clear();

		while(nodesToVisit.empty() != true)
		{
			currentNode = nodesToVisit.front();
			nodesToVisit.pop();

			if(isVisited[currentNode])
			{
				continue;
			}
			else
			{
				isVisited[currentNode] = 1;

				if(listONodes[currentNode] == NULL)
				{
					continue;
				}
				else
				{
					tempNode = listONodes[currentNode];
					while(tempNode != NULL)
					{
						bool isUniqueEdge = true;
						if(currentNode < tempNode->vertexNumber)
						{
							tempEdge.smallVertex = currentNode;
							tempEdge.bigVertex = tempNode->vertexNumber;
						}
						else
						{
							tempEdge.smallVertex = tempNode->vertexNumber;
							tempEdge.bigVertex = currentNode;
						}
						
						// Check edgesToCheck for a copy of this edge
						for(int j = 0; j < (int)edgesToCheck.size(); j++)
						{
							if(edgesToCheck[j].bigVertex == tempEdge.bigVertex
								&& edgesToCheck[j].smallVertex == tempEdge.smallVertex)
							{
								isUniqueEdge = false;
							}
						}

						if(isUniqueEdge)
						{
							edgesToCheck.push_back(tempEdge);
						}
						
						nodesToVisit.push(tempNode->vertexNumber);
						tempNode = tempNode->nextNode;
					} // Done enqueueing verticies to check
				}
			} // End of new node code -- getting next node
		} // End of inner while loop -- queue is empty
		
		// Make sure we even have a continuous structure;
		// we'd look foolish printing an empty array
		hasContinuousStructure = false;
		for(int j = 0; j < size; j++)
		{
			if(isVisited[j] == 1)
			{
				hasContinuousStructure = true;
				break;
			}
		}
		if(hasContinuousStructure)
		{
			// As of here, we've checked one continuous structure
			// Let's print it out
			cout << "These nodes form one continuous structure:" << endl;
			for(int j = 0; j < size; j++)
			{
				if(isVisited[j] == 1)
				{
					cout << j << endl;
					isVisited[j] = 2;
				}
			}

			int * cycleCheck = new int[size];
			for(int j = 0; j < size; j++)
			{
				cycleCheck[j] = 0;
			}

			// Add my edges to this array
			while(!edgesToCheck.empty())
			{
				tempEdge = edgesToCheck.back();
				edgesToCheck.pop_back();

				// For each edge added, check each vertex
				// If we find one where both are are visited, return a cycle
				if(cycleCheck[tempEdge.bigVertex] == 1
					&& cycleCheck[tempEdge.smallVertex] == 1)
				{
					cout << "And they contain a cycle." << endl;
					break;
				}
				else
				{
					cycleCheck[tempEdge.bigVertex] = 1;
					cycleCheck[tempEdge.smallVertex] = 1;
				}
			}
			cout << endl << endl;
		}
	} // End of outer for loop -- done traversing
	return;
}

int main()
{
	int size;
	int vertex1;
	int vertex2;

	cout << "Please enter a number of nodes:" << endl;
	cin  >> size;

	node ** adjacencyList = new node*[size];

	for(int i = 0; i < size; i++){
		adjacencyList[i] = NULL;
	}
	cout << endl << "Here's the empty map:" << endl;
	printList(adjacencyList, size);

	cout << endl << endl;

	cout << "We're gonna add some edges. "
		<< "Enter the same number twice to quit." << endl;
	do
	{
		cout << "Enter vetex one:" << endl;
		cin  >> vertex1;
		cout << "Enter vetex two:" << endl;
		cin  >> vertex2;
		if(vertex1 != vertex2)
		{
			addEdge(adjacencyList, vertex1, vertex2);
			cout << "Edge between " << vertex1 << " and "
				<< vertex2 << " added successfully." << endl << endl;
		}
	}while(vertex1 != vertex2);


	printList(adjacencyList, size);

	cout << endl << endl;
	
	traverseBreadthFirst(adjacencyList, size);

	cout << "Now we're gonna remove some edges. "
		<< "Enter the same number twice to quit." << endl;
	do
	{
		cout << "Enter vetex one:" << endl;
		cin  >> vertex1;
		cout << "Enter vetex two:" << endl;
		cin  >> vertex2;
		if(vertex1 != vertex2)
		{
			removeEdge(adjacencyList, vertex1, vertex2);
			cout << "Edge between " << vertex1 << " and "
				<< vertex2 << " removed successfully." << endl << endl;
		}
	}while(vertex1 != vertex2);
	
	printList(adjacencyList, size);

	traverseBreadthFirst(adjacencyList, size);

	return 0;
}