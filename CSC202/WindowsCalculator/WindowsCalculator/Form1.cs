using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace WindowsCalculator
{
    public partial class Calculator : Form
    {
        // Will hold values input
        private double value1;
        private double value2;

        // Holds temporary variables
        private double tempValue;

        private bool hasDecimal = false;
        private bool input = true;

        // variable to hold which operator we are using
        private string function = string.Empty;

        public Calculator()
        {
            InitializeComponent();
        }

        private void buttonEquals_Click(object sender, EventArgs e)
        {
			if (textBox1.Text.Length != 0)
			{
				Calculate();
			}			
        }

        private void num0_Click(object sender, EventArgs e)
        {
            if (input)
            {
                if (textBox1.Text == "0")
                    textBox1.Text = num0.Text;
                else
                    textBox1.Text += num0.Text;
            
            }
        }

        private void num1_Click(object sender, EventArgs e)
        {
            if (input)
            {
                if (textBox1.Text == "0")
                    textBox1.Text = num1.Text;
                else
                    textBox1.Text += num1.Text;
            }
            else
            {
                textBox1.Text = num1.Text;
                // toggle input to true
                input = true;
            }
        }

        private void num2_Click(object sender, EventArgs e)
        {
            if (input)
            {
                if (textBox1.Text == "0")
                    textBox1.Text = num2.Text;
                else
                    textBox1.Text += num2.Text;
            }
            else
            {
                textBox1.Text = num2.Text;
                // toggle input to true
                input = true;
            }
        }

        private void num3_Click(object sender, EventArgs e)
        {
            if (input)
            {
                if (textBox1.Text == "0")
                    textBox1.Text = num3.Text;
                else
                    textBox1.Text += num3.Text;
            }
            else
            {
                textBox1.Text = num3.Text;
                // toggle input to true
                input = true;
            }
        }

        private void num4_Click(object sender, EventArgs e)
        {
            if (input)
            {
                if (textBox1.Text == "0")
                    textBox1.Text = num4.Text;
                else
                    textBox1.Text += num4.Text;
            }
            else
            {
                textBox1.Text = num4.Text;
                // toggle input to true
                input = true;
            }
        }

        private void num5_Click(object sender, EventArgs e)
        {
            if (input)
            {
                if (textBox1.Text == "0")
                    textBox1.Text = num5.Text;
                else
                    textBox1.Text += num5.Text;
            }
            else
            {
                textBox1.Text = num5.Text;
                // toggle input to true
                input = true;
            }
        }

        private void num6_Click(object sender, EventArgs e)
        {
            if (input)
            {
                if (textBox1.Text == "0")
                    textBox1.Text = num6.Text;
                else
                    textBox1.Text += num6.Text;
            }
            else
            {
                textBox1.Text = num6.Text;
                // toggle input to true
                input = true;
            }
        }

        private void num7_Click(object sender, EventArgs e)
        {
            if (input)
            {
                if (textBox1.Text == "0")
                    textBox1.Text = num7.Text;
                else
                    textBox1.Text += num7.Text;
            }
            else
            {
                textBox1.Text = num7.Text;
                // toggle input to true
                input = true;
            }
        }

        private void num8_Click(object sender, EventArgs e)
        {
            if (input)
            {
                if (textBox1.Text == "0")
                    textBox1.Text = num8.Text;
                else
                    textBox1.Text += num8.Text;
            }
            else
            {
                textBox1.Text = num8.Text;
                // toggle input to true
                input = true;
            }
        }

        private void num9_Click(object sender, EventArgs e)
        {
            if (input)
            {
                if (textBox1.Text == "0")
                    textBox1.Text = num9.Text;
                else
                    textBox1.Text += num9.Text;
            }
            else
            {
                textBox1.Text = num9.Text;
                // toggle input to true
                input = true;
            }
        }

        private void buttonDecimal_Click(object sender, EventArgs e)
        {
			if (input && !hasDecimal)
			{
				if (textBox1.Text.Length != 0)
				{
					if (textBox1.Text != "0")
					{
						textBox1.Text += buttonDecimal.Text;
						hasDecimal = true;
					}
				}
				else
				{
					textBox1.Text = "0.";
				}
			}
        }

		private void buttonAdd_Click(object sender, EventArgs e)
		{
			if (textBox1.Text.Length != 0)
			{
				if (function == string.Empty)
				{
					value1 = System.Double.Parse(textBox1.Text);
					textBox1.Text = string.Empty;
				}
				else
				{
					Calculate();
				}
				function = "Add";
				hasDecimal = false;
			}
		}

		private void buttonSubtract_Click(object sender, EventArgs e)
		{
			if (textBox1.Text.Length != 0)
			{
				if (function == string.Empty)
				{
					value1 = System.Double.Parse(textBox1.Text);
					textBox1.Text = string.Empty;
				}
				else
				{
					Calculate();
				}
				function = "Subtract";
				hasDecimal = false;
			}
		}

		private void buttonMultiply_Click(object sender, EventArgs e)
		{
			if (textBox1.Text.Length != 0)
			{
				if (function == string.Empty)
				{
					value1 = System.Double.Parse(textBox1.Text);
					textBox1.Text = string.Empty;
				}
				else
				{
					Calculate();
				}
				function = "Multiply";
				hasDecimal = false;
			}
		}

		private void buttonDivide_Click(object sender, EventArgs e)
		{
			if (textBox1.Text.Length != 0)
			{
				if (function == string.Empty)
				{
					value1 = System.Double.Parse(textBox1.Text);
					textBox1.Text = string.Empty;
				}
				else
				{
					Calculate();
				}
				function = "Divide";
				hasDecimal = false;
			}
		}

		private void buttonPowers_Click(object sender, EventArgs e)
		{
			if (textBox1.Text.Length != 0)
			{
				if (function == string.Empty)
				{
					value1 = System.Double.Parse(textBox1.Text);
					textBox1.Text = string.Empty;
				}
				else
				{
					Calculate();
				}
				function = "Powers";
				hasDecimal = false;
			}
		}

		private void buttonSqRoot_Click(object sender, EventArgs e)
		{
			if (textBox1.Text.Length != 0)
			{
				tempValue = System.Double.Parse(textBox1.Text);
				tempValue = System.Math.Sqrt(tempValue);
				textBox1.Text = tempValue.ToString();

				hasDecimal = false;
			}
		}

		private void buttonInverse_Click(object sender, EventArgs e)
		{
			double returnText = 1 / System.Double.Parse(textBox1.Text);
			textBox1.Text = returnText.ToString();

			hasDecimal = false;
		}

		private void buttonClear_Click(object sender, EventArgs e)
		{
			textBox1.Text = string.Empty;

			value1 = 0;
			value2 = 0;

			function = string.Empty;

			hasDecimal = false;
		}

		private void buttonSine_Click(object sender, EventArgs e)
		{
			if (textBox1.Text.Length != 0)
			{
				tempValue = System.Double.Parse(textBox1.Text);
				tempValue = System.Math.Sin(tempValue);
				textBox1.Text = tempValue.ToString();

				hasDecimal = false;
			}
		}

		private void buttonCosine_Click(object sender, EventArgs e)
		{
			if (textBox1.Text.Length != 0)
			{
				tempValue = System.Double.Parse(textBox1.Text);
				tempValue = System.Math.Cos(tempValue);
				textBox1.Text = tempValue.ToString();

				hasDecimal = false;
			}
		}

		private void buttonTangent_Click(object sender, EventArgs e)
		{
			if (textBox1.Text.Length != 0)
			{
				tempValue = System.Double.Parse(textBox1.Text);
				tempValue = System.Math.Tan(tempValue);
				textBox1.Text = tempValue.ToString();

				hasDecimal = false;
			}
		}

		private void Calculate()
		{
			value2 = System.Double.Parse(textBox1.Text);

			// Which calculation are we doing?
			switch (function)
			{
				case "Add":
					value1 = value1 + value2;
					break;
				case "Subtract":
					value1 = value1 + value2;
					break;
				case "Divide":
					value1 = value1 / value2;
					break;
				case "Multiply":
					value1 = value1 * value2;
					break;
				case "Powers":
					value1 = System.Math.Pow(value1, value2);
					break;
			}

			textBox1.Text = value1.ToString();
			input = false;
		}
    }
}
