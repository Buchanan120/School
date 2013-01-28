using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace GetTicks
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            AcceptButton = buttonCalculate ;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void textHours_TextChanged(object sender, EventArgs e)
        {

        }

        private void labelMinutes_Click(object sender, EventArgs e)
        {

        }

        private void textMinutes_TextChanged(object sender, EventArgs e)
        {

        }

        private void labelSeconds_Click(object sender, EventArgs e)
        {

        }

        private void textSeconds_TextChanged(object sender, EventArgs e)
        {

        }

        private void labelTicks_Click(object sender, EventArgs e)
        {

        }

        private void textTicks_TextChanged(object sender, EventArgs e)
        {

        }

        private void labelHours_Load(object sender, EventArgs e)
        {

        }
        private void buttonCalculate_Click(object sender, EventArgs e)
        {
            textResult.Text = "Working...";

            // Test input
            string hours = textHours.Text.Trim();
            string minutes = textMinutes.Text.Trim();
            string seconds = textSeconds.Text.Trim();
            string ticks = textTicks.Text.Trim();
            int testNum;
            bool testHours = int.TryParse(hours, out testNum);
            bool testMinutes = int.TryParse(minutes, out testNum); 
            bool testSeconds = int.TryParse(seconds, out testNum);
            bool testTicks = int.TryParse(ticks, out testNum);
            if (testHours && testMinutes && testSeconds && testTicks)
            {
                // Get text from textBoxes and save to variables for calculations
                int ticksHours = Convert.ToInt32(hours);
                int ticksMinutes = Convert.ToInt32(minutes);
                int ticksSeconds = Convert.ToInt32(seconds);
                int ticksTicks = Convert.ToInt32(ticks);
 
                // The meat
                int _ticks = 0;
                _ticks += ticksHours * 360000;
                _ticks += ticksMinutes * 6000;
                _ticks += ticksSeconds * 100;
                _ticks += ticksTicks;
                
                textResult.Text = Convert.ToString(_ticks);
            }
            else
                textResult.Text = "Invalid input.";
        }
    }
}
