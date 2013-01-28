using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Euclid
{
    public partial class EuclidWiz : Form
    {

        public EuclidWiz()
        {
            InitializeComponent();
            AcceptButton = btnFindGCD ;
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click_1(object sender, EventArgs e)
        {

        }

        private void btnFindGCD_Click(object sender, EventArgs e) {
            // Test input
            string testString1 = textBoxNumber1.Text.Trim();
            string testString2 = textBoxNumber2.Text.Trim();
            int testNum;
            bool test1Pass = int.TryParse(testString1, out testNum);
            bool test2Pass = int.TryParse(testString2, out testNum);
            if (test1Pass && test2Pass) {
                // Get text from textBoxes and save to variables for calculations
                int num1 = Convert.ToInt32(textBoxNumber1.Text);
                int num2 = Convert.ToInt32(textBoxNumber2.Text);

                // The meat
                while (num2 != 0) {
                    int dummyVariable = num2;
                    num2 = num1 % num2;
                    num1 = dummyVariable;
                }
                labelGCD.Text = "The greatest common divisor is "
                    + Convert.ToString(num1);
            }else
                labelGCD.Text = "Invalid input.";
        }
    }
}
