using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Diagnostics;

// This form is mostly the work of Michael Peters.  Minor changes made to accomodate my dll.

namespace LangtonsLoop
{
    public partial class Form1 : Form
    {
        Rule langtons;
        static World theCA;
        Bitmap bmp;
        Graphics gpx;
        private static int DIVISOR = 4;


        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            bmp = new Bitmap(gridBox.Width, gridBox.Height);
            gpx = Graphics.FromImage(bmp);
            gridBox.Image = bmp;
            // Initialize the CA here.
            langtons = new LangtonsLoop.Rule();
            theCA = new World(gridBox.Width / DIVISOR, gridBox.Height / DIVISOR, langtons);
            updateGraphics();
            gridBox.Refresh();
            Console.WriteLine("The CA has been created.");
        }

        private void goButton_Click(object sender, EventArgs e)
        {
            // Change goButton text to appropriate signal.
            goButton.Text = (goButton.Text == "Stop!") ? "Go!" : "Stop!";
            timer1.Enabled = !timer1.Enabled;
        }

        private void stepSimulation(object sender, EventArgs e)
        {
            theCA.Update();
            updateGraphics();
        }

        private void updateGraphics()
        {
            Color[] states = { Color.Black, Color.Blue, Color.Red, Color.Yellow, Color.White, Color.Green, Color.Orange, Color.Navy };
            int state = 0;
            // draw the grid.
            for (int i = 0; i < gridBox.Width / DIVISOR; i++)
                for (int j = 0; j < gridBox.Height / DIVISOR; j++)
                {
                    state = (int)theCA[i,j].State;
                    //gpx.DrawRectangle(new Pen(states[state]), i * 4, j * 4, 4, 4); 
                    SolidBrush theBrush = new SolidBrush(states[state]);
                    gpx.FillRectangle(theBrush, i * 4, j * 4, 4, 4);
                }
            gridBox.Refresh();
        }

        private void resetButton_Click(object sender, EventArgs e)
        {
            theCA = new World(gridBox.Width / DIVISOR, gridBox.Height / DIVISOR, langtons);
            updateGraphics();
            gridBox.Refresh();
        }
    }
}
