#include "CellularAutomata.h"
#include "Cell.h"
#include <cstdlib>
#include <ctime>



CellularAutomata::CellularAutomata()
{
	for (int i = 0; i < 80; i++)
	{
		_generation[i] = Cell();
	}
	// seed random with the current time
	srand((unsigned)time(0));
}

void CellularAutomata::RandomizeGeneration()
{
	for (int i = 0; i < 80; i++)
	{
		_generation[i].SetState((bool)(rand() % 2));
	}
}

void CellularAutomata::Update()
{
	// save old states to preserve discreteness
	bool parents [80];
	for (int i = 0; i < 80; i++)
	{
		parents[i] = _generation[i].GetState();
	}

	for (int i = 0; i < 80; i++)
	{
		// passes in neighbors' state, check for boundaries and returns false if first or last cell.
		_generation[i].CalculateState(i == 0 ? false : parents[i - 1], i == 80 ? false : parents[i + 1]);
	}
}