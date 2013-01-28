using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace War_of_the_Ants
{
	public partial class Form1 : Form
	{
		static Bitmap mapBitmap;
		Graphics mapGraphics;

		bool initialized = false;
		bool stopped = false;

		World w;

		public Form1()
		{
			InitializeComponent(); 

			mapBitmap = new Bitmap(Constants.width, Constants.height);
			mapGraphics = Graphics.FromImage(mapBitmap);
			picture.BackgroundImage = mapBitmap;
		}

		private void buttonRun_Click(object sender, EventArgs e)
		{
			stopped = false;
			refreshTimer.Enabled = true;
		}

		private void RunAnts()
		{
			if (!initialized)
			{
				MessageBox.Show("Please initialize");
				Thread.Sleep(0);
			}
			else
			{
				this.Update();
				w.TimeStep();
				Display();
				Thread.Sleep(0);
			}
		}

		void Display()
		{
			mapGraphics.Clear(Color.Black);
			DrawPheromone();

			for (int i = 0; i < w.anthills.Count(); i++)
			{
				DrawAnthill(w.anthills[i], i == 0 ? Color.Red : Color.Blue);
			}
			foreach (Food food in w.foods)
			{
				DrawFood(food);
			}
			foreach (Ant ant in w.redAnts)
			{
				DrawAnt(ant,Color.Red);
            }
            foreach (Ant ant in w.blueAnts)
            {
                DrawAnt(ant, Color.Blue);
            }
			StringBuilder sb = new StringBuilder();
			sb.Append("Red: " + w.redAnts.Count +" ants, " + w.totalFoodEatenByRed + " food eaten :: Blue: " +
						w.blueAnts.Count + " ants, " + w.totalFoodEatenByBlue + " food eaten");
			this.Text = sb.ToString();
			picture.Update();
			this.Refresh();
		}

		private void DrawPheromone()
		{
			for (int x = 0; x < Constants.width; x++)
			{
				for (int y = 0; y < Constants.height; y++)
				{
					// Draw pheromone
                    float pheremoneLevel = w.pheromone[x, y];
					if (pheremoneLevel > 0)
					{
                        mapBitmap.SetPixel(x, y, Color.Purple);
					}
				}
			}
		}

		private void DrawFood(Food food)
		{
			SolidBrush brush = new SolidBrush(Color.Green);
			mapGraphics.FillEllipse(brush, food.location);
		}

		private void DrawAnt(Ant ant, Color color)
		{
            if (!ant.loc.IntersectsWith(new Rectangle(ant.home.Location.X, ant.home.Location.Y,14,14)))
            {
                mapGraphics.DrawEllipse(new Pen(color), ant.loc);
                if (ant.hasFood)
                {
                    SolidBrush brush = new SolidBrush(Color.Green);
                    mapGraphics.FillEllipse(brush, ant.loc);
                }
            }
		}

		private void DrawAnthill(Anthill anthill, Color color)
		{
			SolidBrush brush = new SolidBrush(color);
			mapGraphics.FillEllipse(brush, anthill.Location);
		}

		private void buttonInitialize_Click(object sender, EventArgs e)
        {
            buttonRun.BackColor = Color.Green;
			GetValuesFromInterface();
			w = new World(Constants.width, Constants.height, Constants.numAnts, 
							Constants.numFoodPiles, Constants.foodPerPile);
			initialized = true;
			Display();
		}

		private void GetValuesFromInterface()
		{
			Constants.numAnts = int.Parse(textNumAnts.Text);
			Constants.numFoodPiles = int.Parse(textNumFood.Text);
			Constants.foodPerPile = int.Parse(textFoodPerPile.Text);
		}

		private void refreshTimer_Tick(object sender, EventArgs e)
		{
			if (!stopped)
				RunAnts();
		}

		private void buttonStop_Click(object sender, EventArgs e)
		{
			stopped = true;
		}
	}
}
