using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;

namespace MyCA
{
    public partial class MyCa : Form
    {
		bool[,] now = new bool[20, 20];
		bool[,] next = new bool[20, 20];
		CATile[,] ca = new CATile[20, 20];
		CATile[,] ruleAlive = new CATile[4, 4];
		CATile[,] ruleDead  = new CATile[4, 4];

        public MyCa()
        {
            InitializeComponent();

			for (int i = 0; i < 20; i++)
			    for (int j = 0; j < 20; j++)	
				{
					// Initialize grid display
					ca[i, j] = new CATile();
					ca[i, j].Left = i * 15;
					ca[i, j].Top = j * 15;
					this.panel1.Controls.Add(ca[i,j]);
					ca[i, j].Click += UpdateNow;

					// Initialize now and next arrays
					now[i, j] = next [i, j] = ca[i, j].alive;
				}
			
			// Initialize rules buttons
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
				{
					ruleDead[i, j] = new CATile();
					ruleDead[i, j].Top = 107 + (105 * j);
					ruleDead[i, j].Left = 57 + (84 * i);
					
					this.tabPage1.Controls.Add(ruleDead[i, j]);

					ruleAlive[i, j] = new CATile();
					ruleAlive[i, j].Top = 107 + (105 * j);
					ruleAlive[i, j].Left = 414 + (84 * i);
					ruleAlive[i, j].SetState(true);

					this.tabPage1.Controls.Add(ruleAlive[i, j]);
				}
		}

		private void saveToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (saveFileDialog.ShowDialog() == DialogResult.OK)
			{
				// The stream writer seems like it is the best option since it
				//	allows manipulation of a file stream
				StreamWriter writer = new StreamWriter(saveFileDialog.OpenFile());
				string[,] grid = new string[20, 20];
				for (int i = 0; i < 20; i++)
				{
					for (int j = 0; j < 20; j++)
					{
						if (now[i, j]) writer.Write("1");
						else writer.Write("0");
					}
					writer.WriteLine();
				}
				writer.Close();
			}
		}

		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			if (openFileDialog.ShowDialog() == DialogResult.OK)
			{
				// Stream and Stream Reader were also likely candidates.  
				//	They allow opening of existing files, as well as read access from them.
				Stream file = openFileDialog.OpenFile();
				StreamReader reader = new StreamReader(file);
				char[] newGrid = new char[400];


				try
				{
					for (int i = 0; i < 400; i++)
					{
						reader.Read(newGrid, i, 1);
					}

					for (int i = 0; i < 20; i++)
						for (int j = 0; j < 20; j++)
							now[i, j] = (newGrid[i * 20 + j] != '0');
					UpdateGrid();
				}
				catch (System.Exception ex)
				{
					MessageBox.Show("Error reading from file.  Please ensure the file is a 20 x 20 array of booleans", "Read Error");
				}
				finally
				{
					reader.Close();
				}
				
			}
		}

		private void randomizeToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Random rand = new Random();

			for (int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++)
					now[i, j] = rand.Next(2) != 0;

			UpdateGrid();
		}

		private void exitToolStripMenuItem_Click(object sender, EventArgs e)
		{
			this.Close();
		}

		private void buttonStep_Click(object sender, EventArgs e)
		{
			Step();
			UpdateGrid();
		}

		private void buttonFastForward_Click(object sender, EventArgs e)
		{
			int generations = 0;
			if (IsNumeric(textBoxFastForward.Text.ToString()))
			{
				generations = int.Parse(textBoxFastForward.Text.ToString());
			}
			for (int i = 0; i < generations; i++)
				Step();

			UpdateGrid();
		}

		private void UpdateNow(object sender, EventArgs e)
		{
			for (int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++)
				{
					now[i, j] = ca[j, i].alive;
				}
		}


		private void UpdateGrid()
		{
			for (int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++)
				{
					ca[j, i].alive = now[i, j];
					ca[j, i].Update();
				}
		}

		private void Step()
		{
			UpdateNow(new object(), new EventArgs());

			for (int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++)
				{
					next[i, j] = GetRule(i, j);
				}
			for (int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++)
				{
					now[i, j] = next[i, j];
				}
		}

		private bool GetRule(int x, int y)
		{
			bool above = now[x, (y + 19) % 20];
			bool below = now[x, (y + 21) % 20];
			bool left  = now[(x + 19) % 20, y];
			bool right = now[(x + 21) % 20, y];
			bool alive = now[x, y];

			byte rule = 0;
			if (above) rule += 1;
			if (left) rule += 2;
			if (right) rule += 4;
			if (below) rule += 8;

			if (alive)
				return ruleAlive[rule / 4, rule % 4].alive;
			else
				return ruleDead[rule / 4, rule % 4].alive;
		}


		// IsNumeric
			// Takes a string argument
			//	Checks if the string contains all numbers
			//	Returns a bool
		private static bool IsNumeric(string chkNumeric)
		{
			int intOutVal;
			bool isValidNumeric = false;
			isValidNumeric = int.TryParse(chkNumeric, out intOutVal);
			return isValidNumeric;
		}

		private void clearToolStripMenuItem_Click(object sender, EventArgs e)
		{
			for (int i = 0; i < 20; i++)
				for (int j = 0; j < 20; j++)
					now[i, j] = false;
			UpdateGrid();
		}
    }
}
