#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#define H 32 //Define height
#define W 32 //Define width
int now[H][W], next[H][W]; //Creates now and then matrixes
using namespace std;


void clear(int mat[][W]) { //Sets matrix to all dead
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
			mat[i][j] = 0;
	}
}

void randSeed(int mat[][H]) { //Randomly seeds matrix
	srand (time(NULL)); //Windows
	//srand (52461435) ; //Linux (not random)
    for (int i = 0; i < W; i++) {
        for (int j = 0; j < H; j++)
            mat[i][j] = rand() % 2;
    }
}

void print(int mat[][W]) { //Prints matrix to screen
	cout << setw(3) << " ";
	for (int i = 0; 5*i < W; i++) // Print the index numbers across the top.
		cout << setw(5) << (5 * i + 1);
	cout << endl;
	for (int j = 0; j < H; j++){
		cout << setw(3) << j+1;
		for (int k = 0; k < W; k++)
		{
			if (mat[j][k]) cout << char(219); // This is the 'alive' block.
			else cout << "-";
		}
		cout << endl;
	}
}

void calculate() {
	unsigned int neighbors;
	for (int m = 0; m < H; m++) {
		for (int n = 0; n < W; n++) {
			neighbors = 0;
			//Begin counting number of neighbors:			
			
			// 123
			// 4x6		Array locations for ease of reading
			// 789

			_asm{
				mov ebx, W
				CHECKTOPLEFT:
				cmp m, 0
					ja CHECKTOPLEFT2		// Skip border check and check neighbor top left

					// "else"
					jmp CHECKTOP		// Skip border check and check for neighbor above
					
				CHECKTOPLEFT2:
				cmp n, 0
					ja TOPLEFTINC			// increment neighbors
					// "else"
					jmp CHECKTOP			// Check neighbor above, skip border check
					
					TOPLEFTINC:			// Increment neighbors for current space
					
					// Get the address of m-1, n-1
					mov eax, m
					dec eax
					mul bx			// Convert to array coordinates
					add eax, n
					dec eax
					
					cmp now[eax * 4], 0
						jna CHECKTOP			// Check neighbor above
					// "else"
						inc neighbors
					
					
				CHECKTOP:		// Check space 2

				cmp m, 0
					ja TOPINC
					// "else"
					jmp CHECKTOPRIGHT		// Check for neighbor to top right
					
					TOPINC:		// Increment neighbors for current space
					
					// Get the address of m-1, n
					mov eax, m
					dec eax
					mul bx
					add eax, n
					
					cmp now[eax * 4], 0
						jna CHECKTOPRIGHT		// Check for neighbor to top right
					// "else"
						inc neighbors
				
				CHECKTOPRIGHT:			// Check for border
				cmp m, 0
					ja CHECKTOPRIGHT2			// Check for neighbor to top right
					// "else"
					jmp CHECKLEFT			// Check for neighbor to left
				
				CHECKTOPRIGHT2:					// Check neighbor top right
				cmp m, W
					jb TOPRIGHTINC
					// "else"
					jmp CHECKLEFT
					
					TOPRIGHTINC:			// Increment neighbors for current space
					// Get the address of m-1, n+1
					mov eax, m
					dec eax
					mul bx
					add eax, n
					inc eax
					
					cmp now[eax * 4], 0
						jna CHECKLEFT			// Check neighbor to left
					// "else"
						inc neighbors
				
				CHECKLEFT:			// Check neighbor to left
				cmp n, 0
					ja LEFTINC
					// "else"
					jmp CHECKRIGHT			// Check neighbor to right
					
					LEFTINC:			// Increments neighbors for current space
					// Get the address of m, n-1
					mov eax, m
					mul bx
					add eax, n
					dec eax
					
					cmp now[eax * 4], 0
						jna CHECKRIGHT		// Check neighbor to right
					// "else"
						inc neighbors
				
				CHECKRIGHT:		// Check for neighbors to right
				cmp n, W
					jb RIGHTINC			// Increment neighbors
					// "else"
					jmp CHECKBOTTOMLEFT			// Check for neighbors bottom left
					
					RIGHTINC:
					// Get the address of m, n+1
					mov eax, m
					mul bx
					add eax, n
					inc eax
					
					cmp now[eax * 4], 0
						jna CHECKBOTTOMLEFT
					// "else"
						inc neighbors
				
				CHECKBOTTOMLEFT:
				cmp m, H
					jb CHECKBOTTOMLEFT2				// Check for neighbors bottom left
					// "else"
					jmp CHECKBOTTOM
					
				CHECKBOTTOMLEFT2:			// Check for edge
				cmp n, 0			// if m = H then the space is on the edge
					ja BOTTOMLEFTINC		// if not on the edge
					// "else"
					jmp CHECKBOTTOM		// otherwise,
					
					BOTTOMLEFTINC:				// Check for neighbors bottom left
					// Get the address of m+1, n-1
					mov eax, m
					inc eax
					mul bx
					add eax, n
					dec eax
					
					cmp now[eax * 4], 0
						jna CHECKBOTTOM
					// "else"
						inc neighbors
				
				CHECKBOTTOM:			// Check for border

				cmp m, H
					jb BOTTOMINC
					// "else"
					jmp CHECKBOTTOMRIGHT
					
					BOTTOMINC:			// increment neghbors
					// Get the address of m+1, n
					mov eax, m
					inc eax
					mul bx
					add eax, n
					
					cmp now[eax * 4], 0
						jna CHECKBOTTOMRIGHT
					// "else"
						inc neighbors
				
				CHECKBOTTOMRIGHT:
				cmp m, H
					jb CHECKBOTTOMRIGHT2
					// "else"
					jmp DONEFINDINGNEIGHBORS
				CHECKBOTTOMRIGHT2:
				cmp n, W
					jb BOTTOMRIGHTINC
					// "else"
					jmp DONEFINDINGNEIGHBORS
					
					BOTTOMRIGHTINC:
					// Get the address of m+1, n+1
					mov eax, m
					inc eax
					mul bx
					add eax, n
					inc eax
					
					cmp now[eax * 4], 0
						jna DONEFINDINGNEIGHBORS
					// "else"
						inc neighbors
				
				DONEFINDINGNEIGHBORS:
			}
			


			//Apply rules to the cell:
			_asm{
				// set eax to the index of current cell:
				mov ebx, W
				mov eax, m
				mul bx
				add eax, n
				
				LONLINESS:				// If less than 2 neighbors, kill
					//if (now[m][n] == 1 && neighbors < 2)
					cmp now[eax * 4], 0
					jna BIRTH
					cmp neighbors, 2
					jb DIE
				CROWDING:				// If more than 3 neighbors, kill
					//else if (now[m][n] == 1 && neighbors > 3)
					cmp now[eax * 4], 0
					jna BIRTH
					cmp neighbors, 3
					ja DIE
				LIVEON:					// If exactly 2 or 3 neighbors and alive, no change
					//else if (now[m][n]==1&&(neighbors == 2 || neighbors == 3))
					cmp now[eax * 4], 0
					jna BIRTH
					cmp neighbors, 2
					je LIVE
					cmp neighbors, 3
					je LIVE
				BIRTH:					// If 3 neighbors and dead, new life
					//else if (now[m][n] == 0 && neighbors == 3)
					cmp now[eax * 4], 0
					ja DONE
					cmp neighbors, 3
					je LIVE
				DIE:						// logic to kill
					mov next[eax * 4], 0
					jmp DONE
				LIVE:					// logic to live/bear life
					mov next[eax * 4], 1
					jmp DONE
				DONE:
					// DONE
			}
		}
	}
}

void swap(int mata[][W], int matb[][W]) {
	// Replaces first matrix with second
	for (int m = 0; m < H; m++){
		for (int n = 0; n < W; n++){
			mata[m][n] = matb[m][n];
		}
	}
}


int main() {
	int seed ; //Seed with random number or use manual input to seed?

	int x, y, cont; //Used for user input
	
	cout << left << "Welcome to Conway's Game of Life." << endl << endl;
	cout << "The Rules of Life:" << endl;
	cout << "1. Any live cell with fewer than two live neighbors dies, as if by loneliness." << endl;
	cout << "2. Any live cell with more than three live neighbors dies, as if by \novercrowding." << endl;
	cout << "3. Any live cell with two or three live neighbors lives, unchanged." << endl;
	cout << "4. Any dead cell with exactly three live neighbors comes to life." << endl << endl;
	cout << "To play: Press any key to begin. Enter the column and row of a cell to make \nalive, separated by a space. ";
	cout << "When you are ready, enter \"-1\" to begin the \nsimulation. Then enter any number to continue or \"-1\" to quit." << endl;
	cin.get();
	cout << "Press 1 to randomly seed the array.  Otherwise, press any key and you will be \ngiven the option to seed the array manually." ;
	cin >> seed ;
	if (seed != 1) {
		cout << "To play: Press any key to begin. Enter the column and row of a cell to make \n         alive, separated by a space. ";
		cout << "When you are ready, enter \"-1\" to begin \n         the simulation. Then enter any number to continue or \"-1\" to quit." << endl;
		cin.get() ;
		clear(now) ;
	}else{
		randSeed(now) ;
	}
    
	print(now);
	
	do { //Get initial state
		cin >> x;
		if (x == -1) {
			break; //User is done inputting
		}
		cin >> y;
		now[y-1][x-1] = 1; //Sets cell to alive
		print(now); //Updates screen
	}while(x != -1);
	cont = 1 ;
	do { //Keep updating new generations
		while(cont > 0) {
			clear(next);
			calculate();
			swap(now, next);
			print(now);
			cont-- ;
		}
		cout << "Please enter the desired number of iterations:" << endl ;
		cin >> cont ;

	}while(cont != -1);
	
	return 0;
}