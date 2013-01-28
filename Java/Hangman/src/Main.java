/**
 * Caleb Thompson
 * Java Programming I
 * February 2009
 */

import java.io.BufferedReader ;
import java.io.File ;
import java.io.FileReader ;
import java.util.Random ;
import javax.swing.JFrame ;

/**
 * 
 * The main function and JFrame
 * Word selection
 *
 */

public class Main {

	public static void main(String[] args) {
		JFrame main = new JFrame("Hangman") ;
		SelectGame select = new SelectGame() ;
		main.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		main.setResizable(false) ;
		main.setSize(400,500) ;
		select.addComponentToPane(main.getContentPane());
		main.setVisible(true) ;
		String word = getWord("dictionary.dat") ;
		System.out.println(word) ;


	} 

	private static String getWord(String filename){
		Random random = new Random() ;
		int randWord = random.nextInt(100) ;
		String word = null ;
		try {
			// File -> Stream -> Reader
			File dictionary = new File(filename) ;
			FileReader inStream = new FileReader(dictionary) ;
			BufferedReader in = new BufferedReader(inStream) ;

			//read first line
			String line ;
			for(int i = 0; i <= randWord; i++){
				line = in.readLine();
				if(line == null)
					i = (i + 1) ;
				else
					word = line ;
			}
			in.close() ;
			inStream.close() ;
		}
		catch(Exception e) {
			System.out.println("Shit's fucked.") ;
		}
		return word ;
	}
}