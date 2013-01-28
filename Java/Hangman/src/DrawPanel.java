import java.awt.Graphics ;
import javax.swing.JPanel ;


/**
 * 
 * Draw the hangman.
 *
 */
public class DrawPanel extends JPanel{
		public void paintComponent(Graphics g){
			super.paintComponent(g) ;
			int width = getWidth() ;
			int height = getHeight() ;
			
			g.drawLine((width / 4), (height - 50), (3 * width / 4), (height- 50)) ; // start of rectangle
			g.drawLine((width / 4), (height - 80), (3 * width / 4), (height- 80)) ;
			g.drawLine((width / 4), (height - 50), (width / 4), (height- 80)) ;
			g.drawLine((3 * width / 4), (height - 50), (3 * width / 4), (height - 80)) ; //end of rectangle
			g.drawLine((width / 3), (height - 80), (width / 3), (height - 280)) ; // pole
			g.drawLine((width / 3), (height - 280), (width / 2), (height - 280)) ; // horizontal rafter
			g.drawLine((width / 2), (height - 280), (width / 2), (height - 250)) ; // rope
			
			g.drawOval(((width / 2) - 20), (height - 250), 40, 40) ; // head
			g.drawLine((width / 2), (height - 210), (width / 2), (height - 150)) ; // body
			g.drawLine(((width / 2)), (height - 150), ((width / 2) - 20), (height - 110)) ; // left leg
			g.drawLine(((width / 2)), (height - 150), ((width / 2) + 20), (height - 110)) ; // right leg
			g.drawLine((width / 2), (height - 190), ((width / 2) - 30), (height - 200)) ; // left arm
			g.drawLine((width / 2), (height - 190), ((width / 2) + 30), (height - 200)) ; // right arm
		}
	}
