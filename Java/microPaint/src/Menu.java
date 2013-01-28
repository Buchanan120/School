
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;

public class Menu extends JPanel {
	private JPanel buttonJPanel ;
	private JButton buttons[] ;
	public Menu() {
		buttons = new JButton[6] ;
		buttonJPanel = new JPanel() ;
		buttonJPanel.setLayout(new GridLayout(buttons.length,1)) ;
	
		// Initialize and label buttons
		buttons[0] = new JButton("Line") ;
		buttons[1] = new JButton("Rectangle") ;
		buttons[2] = new JButton("Circle") ;
		buttons[3] = new JButton("Triangle") ;
		buttons[4] = new JButton("Move") ;
		buttons[5] = new JButton("Exit") ;
		for(int i = 0; i < buttons.length; i++) {
				buttonJPanel.add(buttons[i]) ;	
		}
		add(buttonJPanel, BorderLayout.WEST) ;		

		buttons[0].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Line
						target.setDrawMode(DrawPanel.LINE);
					}
				}
		);
		buttons[1].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Rectangle
									
					}
				}
		);
		buttons[2].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Circle
						
					}
				}
		);
		buttons[3].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Triangle
						
					}
				}
		);
		buttons[4].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						// TODO: Add action for Move
						
					}
				}
		); 
		buttons[5].addActionListener(
				new ActionListener() {
					public void actionPerformed(ActionEvent event) {
						System.exit(0) ;
					}
				}
		); 
	}

}
