#include "Cell.h"

Cell::Cell()
{
	_on = false;
}

Cell::Cell(Cell & prototype)
{
	_on = prototype._on;
	for (int i = 0; i < 8; i++)
	{
		_rule[i] = prototype._rule[i];
	}
}

void Cell::CalculateState(bool left, bool right)
{
	int rule = 0;
	if (left) rule += 4;
	if (_on) rule += 2;
	if (right) rule += 1;

	_on = _rule[rule];
}

bool Cell::GetState()
{
	return _on;
}
void Cell::SetState(bool on)
{
	_on = on;
}

void Cell::SetRule(bool rule[8])
{
	for (int i = 0; i < 8; i++)
	{
		_rule[i] = rule[i];
	}
}

Cell Cell::operator = (const Cell & aCell) {
	_on = aCell._on;
	for (int i = 0; i < 8; i++)
	{
		_rule[i] = aCell._rule[i];
	}
	return *this ;
}