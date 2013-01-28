#include <iostream>
#include "CellularAutomata.h"
#include "Cell.h"

int main()
{
	unsigned int rule;
	CellularAutomata ca;
	std::cout << "Welcome to the 1 dimensional 2 state 3 neighbor Cellular Automata generator." << std::endl;
		 
	do
	{
		std::cout << "Please input the rule you would like (integer 0-255)." << std::endl;
		std::cin >> rule;
	}
	while (!std::cin.fail() && (rule < 0 || rule > 255));

	// create CA
	ca = CellularAutomata();

	// ask whether the user would like to step or run the ca
		// if step
			// on enter, call update
		// else
			// use a timer to step each half second, output entire generation and endl
}