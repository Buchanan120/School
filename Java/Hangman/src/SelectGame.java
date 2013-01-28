import java.awt.BorderLayout ;
import java.awt.CardLayout ;
import java.awt.Container ;
import java.awt.event.ItemEvent ;
import java.awt.event.ItemListener ;
import javax.swing.JButton ;
import javax.swing.JComboBox ;
import javax.swing.JLabel ;
import javax.swing.JPanel ;
import javax.swing.JTextField ;



/**
 * 
 * 
 *
 */

public class SelectGame implements ItemListener {
    JPanel cards; //a panel that uses CardLayout
    final static String GUESSLETTER = "Guess a letter" ;
    final static String GUESSWORD = "Guess the answer" ;
    
    public void addComponentToPane(Container pane) {
        //Put the JComboBox in a JPanel to get a nicer look.
        JPanel comboBoxPane = new JPanel() ; //use FlowLayout
		DrawPanel draw = new DrawPanel() ;		
        JLabel label = new JLabel() ;
        label.setText("Your guess:") ;
        String comboBoxItems[] = { GUESSLETTER, GUESSWORD } ;
        JComboBox cb = new JComboBox(comboBoxItems) ;
        cb.setEditable(false) ;
        cb.addItemListener(this) ;
        comboBoxPane.add(cb) ;
        
        //Create the "cards".
        JPanel card1 = new JPanel() ;
        card1.add(new JTextField("", 1)) ;
        card1.add(new JButton("Guess")) ;
        
        JPanel card2 = new JPanel() ;
        card2.add(label) ;
        card2.add(new JTextField("", 20)) ;
        card2.add(new JButton("Answer")) ;
        
        //Create the panel that contains the "cards".
        cards = new JPanel(new CardLayout()) ;
        cards.add(card1, GUESSLETTER) ;
        cards.add(card2, GUESSWORD) ;
        
        pane.add(comboBoxPane, BorderLayout.NORTH) ;
        pane.add(cards, BorderLayout.SOUTH) ;
        pane.add(draw, BorderLayout.CENTER) ;
    }
    
    public void itemStateChanged(ItemEvent evt) {
        CardLayout cl = (CardLayout)(cards.getLayout()) ;
        cl.show(cards, (String)evt.getItem()) ;
    }
    
}
