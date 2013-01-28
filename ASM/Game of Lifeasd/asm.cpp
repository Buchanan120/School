void calculate(bool mata[][H], bool matb[][H]) {
	unsigned int neighbors;
	__asm {		//x,y becomes x+width*y
		
		// 123
		// 4X6
		// 789

		// 1 = 
		mov edx, W
		// If not first row
			// If not Left edge
				// Check 1
	CHECK1:	
		cmp mata[eax (M + 1)], 0
		
		// Check 2
			// If not right edge
				// Check 3
		// If not left edge
			// check 4
		// If not right edge
			// Check 6
		// If not bottom row
			// If not left edge
				// Check 7
			// Check 8
			// If not right edge
				// Check 9

		//--------------------------------
/*
			if (mata[m][n] == 1 && neighbors < 2)
                matb[m][n] = 0;
            else if (mata[m][n] == 1 && neighbors > 3)
                matb[m][n] = 0;
            else if (mata[m][n] == 1 && (neighbors == 2 || neighbors == 3))
                matb[m][n] = 1;
            else if (mata[m][n] == 0 && neighbors == 3)
                matb[m][n] = 1;
*/

		// If alive && neighbors < 2
			// set dead
		// If alive && neighbors > 3
			// set dead
		// if alive && 2 or 3 neighbors
			// set alive
		// If dead && 3 neighbors
			// set alive