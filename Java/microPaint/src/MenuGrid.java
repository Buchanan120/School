/*
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;

public class MenuGrid extends JPanel {
	private JPanel buttonJPanel ;
	private JButton buttonsGrid[][] ;
	public MenuGrid() {
		buttonsGrid = new JButton[3][2] ;
		buttonJPanel = new JPanel() ;
		buttonJPanel.setLayout(new GridLayout(buttonsGrid.length+1,1)) ;
	
		// Initialize and label buttons
		//Form:
			// buttonName = new JButton("label") ;
			// buttonName.setToolTipText("alt-text") ;
		// Brush
		//buttonsGrid[0][0] = new JButton(new Character('\u03DA').toString()) ;
		buttonsGrid[0][0] = new JButton("~") ;
		buttonsGrid[0][0].setToolTipText("Brush Tool");
		// Line
		buttonsGrid[0][1] = new JButton(new Character('\uFF3C').toString()) ;
		buttonsGrid[0][1].setToolTipText("Line Tool");
		// Triangle
		buttonsGrid[1][0] = new JButton(new Character('\u25B3').toString()) ;
		buttonsGrid[1][0].setToolTipText("Triangle Tool");
		// Circle
		buttonsGrid[1][1] = new JButton(new Character('\u25EF').toString()) ;
		buttonsGrid[1][1].setToolTipText("Circle Tool");
		// Rectangle
		buttonsGrid[2][0] = new JButton(new Character('\u25A0').toString()) ;
		buttonsGrid[2][0].setToolTipText("Filled Rectangle Tool");
		// Move
		buttonsGrid[2][1] = new JButton(new Character('\u21C6').toString()) ;
		buttonsGrid[2][1].setToolTipText("Move");
		
		for(int i = 0; i < buttonsGrid.length; i++) {
			for(int j = 0; j < 2; j++)
				buttonJPanel.add(buttonsGrid[i][j]) ;	
		}
		add(buttonJPanel, BorderLayout.WEST) ;		

		buttonsGrid[0][0].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Line
						
					}
				}
		);
		buttonsGrid[0][1].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Rectangle
									
					}
				}
		);
		buttonsGrid[1][0].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Circle
					}
				}
		);
		buttonsGrid[1][1].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Triangle
						
					}
				}
		);
		buttonsGrid[2][0].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Triangle
						
					}
				}
		);
		buttonsGrid[2][1].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Triangle
						
					}
				}
		);

	}

}
*/
