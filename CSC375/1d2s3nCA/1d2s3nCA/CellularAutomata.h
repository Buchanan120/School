
#pragma once
#ifndef CELLULARAUTOMATA_H_
#define CELLULARAUTOMATA_H_
#include "Cell.h"
class CellularAutomata
{
private:
	Cell _generation [80];
public:
	CellularAutomata();
	void Update();
	void RandomizeGeneration();
};

#endif