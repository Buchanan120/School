import java.awt.BorderLayout;
import java.awt.Checkbox;
import java.awt.CheckboxGroup;
import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.GridLayout;
import java.awt.Panel;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;


public class Interface {
    public static void main(String[] args) {

        JFrame frame = new JFrame("uPaint");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        ItemPanel panel = new ItemPanel() ; // Canvas / Drawing workspace
        MenuGrid menu = new MenuGrid(panel) ; // Tool selection menu
        ColorPanel colors = new ColorPanel(panel) ; // Color selection menu

        frame.add(panel) ;
        frame.add(menu, BorderLayout.WEST) ;
        frame.add(colors, BorderLayout.SOUTH) ;
        frame.setBackground(Color.WHITE) ;
        frame.setSize(800,600) ;
        frame.setVisible(true) ;
    }
}

@SuppressWarnings("serial")
class ItemPanel extends Panel implements MouseListener, MouseMotionListener {
    // Define cases for button functions
    public static final int SCRIBBLE = 0 ;
    public static final int LINE = 1 ;
    public static final int TRIANGLE = 2 ;
    public static final int ELLIPSE = 3 ;
    public static final int RECTANGLE = 4 ;
    public static final int MOVE = 5 ;
    public static final int CLEAR = 6 ;
    public static final int FAN = 7;
    public static final int SQUAREBRUSH = 8;
    public static final int ROUNDBRUSH = 9;
    int mode = SCRIBBLE ;
    int brushsize = 5;

    // Vectors are arrays.
    // Robots are different from cyborgs.
    // coords is an array of rectangles, the coordinates of which are used to draw the shapes.
    Vector<Rectangle> coords = new Vector<Rectangle>() ;

    // colors is the array of colors corresponding to the shapes in the rectangle vector.
    Vector<Color> colors = new Vector<Color>() ;

    // shapes is a vector that contains the type of the current shape in the rectangle vector
    // Allowed inputs are SCRIBBLE, LINE, TRIANGLE, etc
    Vector<Integer> shapes = new Vector<Integer>();

    // global coordinates used in drawing and painting shapes.
    int x1, y1 ;
    int x2, y2 ;
    // initial location of mouse when drawing rectangles and ellipses
    int rx1, ry1 ;

    public ItemPanel() {
        setBackground(Color.WHITE);

        // Listen to the mouse inside the canvas
        addMouseMotionListener(this);
        addMouseListener(this);
    }

    public void setDrawMode(int mode) {
        switch(mode) {
        // If the mode is at all legal...
        case SCRIBBLE:
        case LINE:
        case TRIANGLE:
        case ELLIPSE:
        case RECTANGLE:
        case MOVE:
        case FAN:
        case SQUAREBRUSH:
        case ROUNDBRUSH:
            // ...set it.
            this.mode = mode;
            break;

            // Otherwise:
        default:
            // Shit bricks
            throw new IllegalArgumentException() ;
        }
    }

    public void mouseClicked(MouseEvent e) {
    }

    public void mouseEntered(MouseEvent e) {
    }

    public void mouseExited(MouseEvent e) {
    }

    public void mousePressed(MouseEvent e) {
        e.consume();
        switch (mode) {
        case LINE:
            System.out.print("\nBeginning line");
            x1 = e.getX();
            y1 = e.getY();
            colors.addElement(getForeground()) ;
            // Will remain a dot unless dragged b/c x2 == -1
            x2 = -1;
            break;

        case SCRIBBLE:
            System.out.print("\nBeginning Freeform");
            // getForeground() takes the ink color from the radio buttons
            // Needs to be added here in order for the
            //    lines to show on the canvas as they're drawn.
            colors.addElement(getForeground());
            // Will remain a dot unless dragged b/c x2 == -1
            coords.addElement(new Rectangle(e.getX(), e.getY(), -1, -1));
            shapes.addElement(new Integer(SCRIBBLE));
            x1 = e.getX();
            y1 = e.getY();
            break;

        case RECTANGLE:
            System.out.print("\nBeginning Rectangle") ;
            x1 = e.getX() ;
            y1 = e.getY() ;
            rx1 = e.getX() ;
            ry1 = e.getY() ;
            colors.addElement(getForeground()) ;
            // Will remain a dot unless dragged b/c x2 == -1
            x2 = -1 ;
            y2 = -1 ;
            break ;

        case ELLIPSE:
            System.out.print("\nBeginning Ellipse") ;
            x1 = e.getX() ;
            y1 = e.getY() ;
            rx1 = e.getX() ;
            ry1 = e.getY() ;
            colors.addElement(getForeground()) ;
            // Will remain a dot unless dragged b/c x2 == -1
            x2 = -1 ;
            y2 = -1 ;
            break ;

        case TRIANGLE:
            System.out.print("\nBeginning Triangle");
            x1 = e.getX();
            y1= e.getY();
            rx1 = x1;
            ry1 = y1;
            colors.addElement(getForeground());
            x2 = x1;
            y2 = y1;
            break;

        case FAN:
            System.out.print("\nBeginning fan");
            colors.addElement(getForeground());
            // Will remain a dot unless dragged b/c x2 == -1
            coords.addElement(new Rectangle(e.getX(), e.getY(), -1, -1));
            shapes.addElement(new Integer(FAN));
            x1 = e.getX();
            y1 = e.getY();
            break;
        case SQUAREBRUSH:
            System.out.print("\nBeginning square brush");
            colors.addElement(getForeground());
            coords.addElement(new Rectangle(e.getX()-brushsize, e.getY() - brushsize, (brushsize*2)+e.getX(), (brushsize*2)+e.getY()));
            shapes.addElement(new Integer(RECTANGLE));
            break;
        case ROUNDBRUSH:
            System.out.print("\nBeginning round brush");
            colors.addElement(getForeground());
            coords.addElement(new Rectangle(e.getX()-brushsize, e.getY() - brushsize, (brushsize*2)+e.getX(), (brushsize*2)+e.getY()));
            shapes.addElement(new Integer(ELLIPSE));
            break;

        default:
            break ;
        }
        repaint() ;
    }

    public void mouseReleased(MouseEvent e) {
        e.consume();

        switch (mode) {
        case LINE:
            System.out.println("Ending a line");

            // color already added upon click
            coords.addElement(new Rectangle(x1, y1, e.getX(), e.getY()));
            shapes.addElement(new Integer(LINE));

            // housecleaning for next shape.  element has already been painted.
            x2 = -1;

            break;

        case SCRIBBLE:
            System.out.println("Ending a stroke");
            break;

        case RECTANGLE:
            System.out.println("Ending a Rectangle") ;

            //colors.addElement(getForeground()) ; // Moved to mouse click event.
            // Will remain a dot unless dragged b/c x2 == -1
            coords.addElement(new Rectangle(x1, y1, x2, y2));
            shapes.addElement(new Integer(RECTANGLE));

            // Housekeeping for next shape.  Element has already been painted.
            x2 = -1;

            break;

        case ELLIPSE:
            System.out.println("Ending an Ellipse") ;

            //colors.addElement(getForeground()) ;
            // Will remain a dot unless dragged b/c x2 == -1
            coords.addElement(new Rectangle(x1, y1, x2, y2)) ;
            shapes.addElement(new Integer(ELLIPSE));

            // Housekeeping for next shape.  element has already been painted.
            x2 = -1;

            break;

        case TRIANGLE:
            System.out.println("Ending a Triangle");

            coords.addElement(new Rectangle(x1, y1, x2, y2));
            shapes.addElement(new Integer(TRIANGLE));

            x1 = -1;
            y1 = -1;
            x2 = -1;
            y2 = -1;
            break;
        case FAN:
            System.out.println("Ending a fan");
            break;
        case ROUNDBRUSH:
        case SQUAREBRUSH:
            System.out.println("Done");
            break;

        default:
        }
        repaint();
    }

    public void mouseDragged(MouseEvent e) {
        e.consume() ;

        int w, h;

        switch(mode) {
        case LINE:
            System.out.print("-");
            x2 = e.getX() ;
            y2 = e.getY() ;
            break;

        case SCRIBBLE:
            System.out.print("~");

            colors.addElement(getForeground()) ;
            coords.addElement(new Rectangle(x1, y1, e.getX(), e.getY())) ;
            shapes.addElement(new Integer(SCRIBBLE));

            x1 = e.getX() ;
            y1 = e.getY() ;

            break;

        case RECTANGLE:
            System.out.print("-") ;

            /* Rectangles are stored x1, y1, width, height.
             * And none of these numbers can be negative.
             * In order to make this work, (x1,y1) needs to be the top left corner.
             *
             * The following code does that by:
             * remembering where the rectangle was started (rx1, ry1), and comparing that to
             * the current mouse position, (e.getX(),e.getY()).
             *
             * By knowing which corner is the top left, and finding the width using the abs() function,
             * we can store the rectangle with no problems.
             *
             * --Kenny
             */
            w = Math.abs(rx1 - e.getX());
            h = Math.abs(ry1 - e.getY());

            // drag down
            if( ry1 < e.getY()) {
                y1 = ry1;
            }

            // drag up
            if ( ry1 > e.getY()){
                y1 = ry1 - h;
            }

            // drag right
            if( rx1 < e.getX()) {
                x1 = rx1;
            }

            // drag left
            if ( rx1 > e.getX()){
                x1 = rx1 - w;
            }

            x2 = x1 + w;
            y2 = y1 + h;

            break ;

        case ELLIPSE:
            System.out.print("-") ;

            w = Math.abs(rx1 - e.getX());
            h = Math.abs(ry1 - e.getY());

            // drag down
            if( ry1 < e.getY()) {
                y1 = ry1;
            }

            // drag up
            if ( ry1 > e.getY()){
                y1 = ry1 - h;
            }

            // drag right
            if( rx1 < e.getX()) {
                x1 = rx1;
            }

            // drag left
            if ( rx1 > e.getX()){
                x1 = rx1 - w;
            }

            x2 = x1 + w;
            y2 = y1 + h;

            break ;

        case TRIANGLE:
            System.out.print("-") ;

            w = Math.abs(rx1 - e.getX());
            h = Math.abs(ry1 - e.getY());

            // drag down
            if( ry1 < e.getY()) {
                y1 = ry1;
            }

            // drag up
            if ( ry1 > e.getY()){
                y1 = ry1 - h;
            }

            // drag right
            if( rx1 < e.getX()) {
                x1 = rx1;
            }

            // drag left
            if ( rx1 > e.getX()){
                x1 = rx1 - w;
            }

            x2 = x1 + w;
            y2 = y1 + h;

            break ;

        case FAN:
            System.out.print("<");
            if(!e.isControlDown()) {
                colors.addElement(getForeground()) ;
                coords.addElement(new Rectangle(x1, y1, e.getX(), e.getY())) ;
                shapes.addElement(new Integer(FAN));
            }

            // With these commented out, the line will always start from the point that was first clicked.
            // This is fun for me.
            // --Kenny
            //x1 = e.getX() ;
            //y1 = e.getY() ;

            break;
            
        case SQUAREBRUSH:
            System.out.print("*");
            colors.addElement(getForeground());
            coords.addElement(new Rectangle(e.getX()-brushsize, e.getY() - brushsize, (brushsize*2)+e.getX(), (brushsize*2)+e.getY()));
            shapes.addElement(new Integer(RECTANGLE));
            break;
            
        case ROUNDBRUSH:
            System.out.print("*");
            colors.addElement(getForeground());
            coords.addElement(new Rectangle(e.getX()-brushsize, e.getY() - brushsize, (brushsize*2)+e.getX(), (brushsize*2)+e.getY()));
            shapes.addElement(new Integer(ELLIPSE));
            break;

        default:
        }
        repaint();
    }

    public void mouseMoved(MouseEvent e) {/*Nothin'*/}

    public void paint(Graphics g) {
        int nPixels = coords.size();

        // Draw current shape
        g.setColor(getForeground()) ;
        for(int i = 0; i < nPixels; i++) {
            // Takes the rectangle in coords at the current element
            // sets x's and y's
            Rectangle p = (Rectangle)coords.elementAt(i) ;

            // Takes color out of colors at the current element
            g.setColor((Color)colors.elementAt(i)) ;

            switch(shapes.elementAt(i)){
            case LINE:
            case SCRIBBLE:
            case FAN:
                if(p.width != -1) {
                    // Draws a line if not meant to be a dot.
                    g.drawLine(p.x, p.y, p.width, p.height) ;
                    //System.out.println("(" + p.x + "," + p.y + "), (" + p.width + "," + p.height + ")");
                }
                else {
                    // Only draws a dot
                    g.drawLine(p.x, p.y, p.x, p.y) ;
                }
                if(mode == LINE) {
                    g.setColor(getForeground()) ;

                    if(x2 != -1) {
                        g.drawLine(x1, y1, x2, y2);
                    }
                }
                break;
            case RECTANGLE:
                if(p.width != -1) {
                    // Draws a rectangle if not meant to be a dot.
                    // The rectangle will have to be stored topleft to bottomright:
                    g.fillRect(p.x, p.y, Math.abs(p.width - p.x), Math.abs(p.height - p.y)) ;

                }
                else {
                    // Only draws a dot
                    g.drawLine(p.x, p.y, p.x, p.y) ;
                }

                /* I just realized why this isn't always true:
                 * what follows is the temporary drawing code.
                 *
                 * --Kenny
                 */
                if(mode == RECTANGLE) {
                    g.setColor(getForeground()) ;

                    if(x2 != -1) {
                        g.drawRect(x1, y1, Math.abs(x2 - x1), Math.abs(y2 - y1));
                    }
                }
                break;
            case ELLIPSE:
                if(p.width != -1) {
                    // Draws an ellipse if not meant to be a dot.
                    g.fillOval(p.x, p.y, Math.abs(p.width - p.x), Math.abs(p.height - p.y)) ;
                }
                if(mode == ELLIPSE) {
                    g.setColor(getForeground()) ;
                    if(x2 != -1) {
                        g.drawOval(x1, y1, Math.abs(x2 - x1), Math.abs(y2 - y1));
                    }
                }
                break;
            case TRIANGLE:
                if(p.width != -1){
                    int[] xpoints = {p.x,p.x, p.width};
                    int[] ypoints = {p.y, p.height, p.height};
                    g.fillPolygon(xpoints, ypoints, 3);
                }
                if (mode == TRIANGLE){
                    g.setColor(getForeground());
                    int[] xpoints = {x1, x1, x2};
                    int[] ypoints = {y1, y2, y2};
                    g.drawPolygon(xpoints, ypoints, 3);
                }
                break;
            default:
                break;
            }
        }
    }

}

//    Dear Java,
//        SHUT UP!

//    Love,
//    Kenny
@SuppressWarnings("serial")
class MenuGrid extends JPanel {
    ItemPanel target ;

    private JPanel buttonJPanel ;
    private JButton buttonsGrid[][] ;

    public MenuGrid(final ItemPanel target) {
        this.target = target ;
        buttonsGrid = new JButton[5][2] ;
        buttonJPanel = new JPanel() ;
        buttonJPanel.setLayout(new GridLayout(buttonsGrid.length+1,1)) ;

        /* The following is the grid of buttons on the left panel.
         * It holds all the buttons in a 2D array so that they can
         * look nice. Caleb is so artsy.
         *
         * They look like crap when the computer doesn't support full unicode.
         *
         * --Kenny
         */

        // SCRIBBLE
        // buttonName = new JButton("label") ;
        buttonsGrid[0][0] = new JButton("~") ;

        // buttonName.setToolTipText("alt-text") ;
        buttonsGrid[0][0].setToolTipText("SCRIBBLE Tool");

        // Line
        buttonsGrid[0][1] = new JButton(new Character('\uFF3C').toString()) ;
        buttonsGrid[0][1].setToolTipText("Line Tool");

        // Triangle
        buttonsGrid[1][0] = new JButton(new Character('\u25B3').toString()) ;
        buttonsGrid[1][0].setToolTipText("Triangle Tool");

        // Ellipse
        buttonsGrid[1][1] = new JButton(new Character('\u25EF').toString()) ;
        buttonsGrid[1][1].setToolTipText("Ellipse Tool");

        // Rectangle
        buttonsGrid[2][0] = new JButton(new Character('\u25A0').toString()) ;
        buttonsGrid[2][0].setToolTipText("Filled Rectangle Tool");

        // Fan
        buttonsGrid[2][1] = new JButton("Fan") ;
        buttonsGrid[2][1].setToolTipText("Fan Tool");

        // Square Brush
        buttonsGrid[3][0] = new JButton("Square Brush");
        buttonsGrid[3][0].setToolTipText("Square Brush");

        // Round Brush
        buttonsGrid[3][1] = new JButton("Round Brush");
        buttonsGrid[3][1].setToolTipText("Round Brush");

        // Clear
        buttonsGrid[4][0] = new JButton("Clear") ;
        buttonsGrid[4][0].setToolTipText("Clear the Canvas") ;

        // Move
        buttonsGrid[4][1] = new JButton(new Character('\u21C6').toString()) ;
        buttonsGrid[4][1].setToolTipText("Move") ;

        for(int i = 0; i < buttonsGrid.length; i++) {
            for(int j = 0; j < 2; j++)
                buttonJPanel.add(buttonsGrid[i][j]) ;    
        }
        add(buttonJPanel, BorderLayout.WEST) ;        

        buttonsGrid[0][0].addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent event) {
                        // Add action for SCRIBBLE
                        target.setDrawMode(ItemPanel.SCRIBBLE);

                    }
                }
        );

        buttonsGrid[0][1].addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent event) {

                        // Add action for Line
                        target.setDrawMode(ItemPanel.LINE);

                        // Fixes problem with not drawing shapes when vector is empty
                        if(target.colors.size() == 0) {
                            AddElementToVector() ;
                        }
                    }
                }
        );

        buttonsGrid[1][0].addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent event) {
                        // Add action for Triangle
                        target.setDrawMode(ItemPanel.TRIANGLE);
                    }
                }
        );

        buttonsGrid[1][1].addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent event) {
                        // Add action for ellipse
                        target.setDrawMode(ItemPanel.ELLIPSE);
                        // Fixes problem with not drawing shapes when vector is empty
                        //if(target.colors.size() == 0) {
                        AddElementToVector() ;
                        //}
                    }
                }
        );

        buttonsGrid[2][0].addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent event) {
                        // Add action for Rectangle
                        target.setDrawMode(ItemPanel.RECTANGLE);
                        // Fixes problem with not drawing shapes when vector is empty
                        if(target.colors.size() == 0) {
                            AddElementToVector() ;
                        }
                    }
                }
        );

        buttonsGrid[2][1].addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent event) {
                        // Add action for Fan
                        target.setDrawMode(ItemPanel.FAN);
                    }
                }
        );

        // Clear
        buttonsGrid[4][0].addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent event) {
                        target.coords.removeAllElements() ;
                        target.colors.removeAllElements() ;
                        target.shapes.removeAllElements() ;
                        // Fixes problem with not drawing shapes after clear
                        AddElementToVector() ;

                        target.repaint() ;
                    }
                }
        );

        buttonsGrid[4][1].addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent event) {
                        // Add action for Move
                        target.setDrawMode(ItemPanel.MOVE);
                    }
                }
        );

        buttonsGrid[3][0].addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent event) {
                        // Add action for Square Brush
                        target.setDrawMode(ItemPanel.SQUAREBRUSH);
                    }
                }
        );

        buttonsGrid[3][1].addActionListener(
                new ActionListener() {
                    public void actionPerformed(ActionEvent event) {
                        // Add action for Round Brush
                        target.setDrawMode(ItemPanel.ROUNDBRUSH);
                    }
                }
        );


    }

    public void AddElementToVector() {    
        target.colors.addElement(getBackground()) ;
        target.coords.add(new Rectangle(-1, -1, 1, 1)) ;
        target.shapes.addElement(new Integer(1));
    }
}

@SuppressWarnings("serial")
class ColorPanel extends JPanel implements ItemListener {
    ItemPanel target ;

    public ColorPanel(ItemPanel target) {
        this.target = target ;
        setLayout(new FlowLayout()) ;
        setBackground(Color.lightGray) ;
        target.setForeground(Color.red) ;
        CheckboxGroup group = new CheckboxGroup();

        // Incoming color checkboxes:
        Checkbox b;
        add(b = new Checkbox(null, group, false));
        b.addItemListener(this);
        b.setForeground(Color.red);
        add(b = new Checkbox(null, group, false));
        b.addItemListener(this);
        b.setForeground(Color.yellow);
        add(b = new Checkbox(null, group, false));
        b.addItemListener(this);
        b.setForeground(Color.green);
        add(b = new Checkbox(null, group, false));
        b.addItemListener(this);
        b.setForeground(Color.blue);
        add(b = new Checkbox(null, group, false));
        b.addItemListener(this);
        b.setForeground(Color.white);
        add(b = new Checkbox(null, group, true));
        b.addItemListener(this);
        b.setForeground(Color.black);

        target.setForeground(b.getForeground());
    }

    public void paint(Graphics g) {
        Rectangle r = getBounds();
        g.setColor(Color.lightGray);
        g.draw3DRect(0, 0, r.width, r.height, false);

        int n = getComponentCount();
        for(int i=0; i<n; i++) {
            Component comp = getComponent(i);

            // Draw the checkboxen.
            if (comp instanceof Checkbox) {
                Point loc = comp.getLocation();
                Dimension d = comp.getSize();

                g.setColor(comp.getForeground());
                g.drawRect(loc.x-1, loc.y-1, d.width+1, d.height+1);
            }
        }
    }

    public void itemStateChanged(ItemEvent e) {
        if (e.getSource() instanceof Checkbox) {
            target.setForeground(((Component)e.getSource()).getForeground());
        }
    }
}

