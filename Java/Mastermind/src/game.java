import java.util.Random;
import java.util.Scanner;

public class game {

	/**
	 * Caleb Thompson
	 * Java Programming I
	 * 28 January 2008
	 */
	public static void main(String[] args) {
		int n ;
		int guess[][] = new int[4][10] ;
		int blackPegs = 0 ;
		int whitePegs = 0 ;
		int codeColor ;
		int guessColor ;
		int codeGuess ;
		int answer ;
		boolean exit = false ;
		boolean replay ;

		String[] color = new String[6] ;

		color[0] = "Red" ;
		color[1] = "Orange" ;
		color[2] = "Yellow" ;
		color[3] = "Green" ;
		color[4] = "Blue" ;
		color[5] = "Purple" ;

		Random randColor = new Random() ;
		Scanner scan = new Scanner(System.in) ;

		// ==Creates code array==
		int code[] = new int[4] ;

		// ===Randomly fills code array with colors===
		for(int i = 0; i <= 3; i++){
			code[i] = randColor.nextInt(5) ;
		}

		do {
			/*
			// ==Prints code for debug==
			for(int i = 0; i <= 3; i++) { 
				System.out.println(color[code[i]]) ;
			}
			*/
			n = 0 ;
			do {
				blackPegs = 0 ;
				whitePegs = 0 ;

				// ==Print out key and number of remaining guesses==
				System.out.println("Red    = 0") ;
				System.out.println("Orange = 1") ;
				System.out.println("Yellow = 2") ;
				System.out.println("Green  = 3") ;
				System.out.println("Blue   = 4") ;
				System.out.println("Purple = 5\n") ;
				System.out.println("You have " + (10 - n) + " guesses remaining.\n") ;

				// codeGuess set outside of 6 so that with no input the check later will fail

				codeGuess = 6 ;

				int e = 1 ;

				for(int i = 0; i < 4;){
					// ==Error message that prints if user input is outside of bounds==
					if(i == e) {

						System.out.println("Your input does not correspond to one of the colors.") ;
						System.out.println("Please try again.") ;
					}

					e = i ;

					// ==Requests input from user==
					System.out.println("Please make your selection for space number: " + (i + 1)) ;
					codeGuess = scan.nextInt() ;

					// ===Only inputs code and increases number if within bounds===
					if(codeGuess >= 0 && codeGuess <= 5) {
						guess[i][n] = codeGuess ;
						i++ ;
					}

				}

				// Prints all guesses thus far
				System.out.println( "Your guesses so far: " );
				for(int i = 0; i < (n + 1); i++) {
					for( int j = 0; j < guess.length; j++ ) {
						if( !(j < guess.length - 1) ) {
							System.out.print( color[guess[j][i]]+ "\n" );
						} else {
							System.out.print( color[guess[j][i]] + ", " );
						}
						
					}
					
				}
				// ==White Pegs==
				for(int i = 0; i <= 5; i++){ 
					codeColor = 0 ;
					// ===Count color in code===
					for(int j = 0; j <= 3; j++){
						if(code[j] == i){
							codeColor++ ;
						}

					}

					guessColor = 0 ;
					// ===Count color in guess===
					for(int j = 0; j <= 3; j++){
						if(guess[j][n] == i){
							guessColor++ ;
						}

					}

					// ===Increase number of white pegs by lesser of codeColor or guessColor===
					if(codeColor > guessColor)
						whitePegs += guessColor ;
					else whitePegs += codeColor ;

				}

				// ==Black Pegs==
				for(int i = 0; i <= 3; i++){ 
					if(code[i] == guess[i][n]) {
						blackPegs++ ;
					}
					
				}

				System.out.println("\nThe number of correct colors in their correct places (black pegs) is " + blackPegs) ;
				System.out.println("The number of correct colors, which are incorrectly placed (white pegs), is " + (whitePegs - blackPegs)) ;

				if(blackPegs == 4) {
					exit = true ;
				}

				n++ ;

			}while(!exit && n < 10) ;

			if(n < 10) {
				System.out.println("\nCongratulations.  You won.") ;
			} else 
				// Checks to see if the game was won
				if(exit == false) {
					System.out.println("\nSorry, you lost.") ;
				}
			System.out.println("Would you like to play again?\n\tYes = 0\n\tNo  = 1") ;
			answer = scan.nextInt() ;
			if(answer == 0) {
				replay = true ;
			}else {
				replay = false ;
			}
		}while(replay) ;
		
	}

}



