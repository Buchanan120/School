#pragma once
#ifndef CELL_H_
#define CELL_H_

class Cell
{
private:
	// the cell's current state
	bool _on;
	// the cell's rule
	bool _rule[8];
public:
	Cell();
	Cell(Cell & prototype);
	// returns the cell's current state
	bool GetState();
	// sets the cell's current state
	void SetState(bool on);
	// sets the rule for all cells as rule is a static member
	void SetRule(bool rule[8]);
	// calculate and set new state
	void CalculateState(bool left, bool right);
	Cell operator= (const Cell & aCell);
};

#endif