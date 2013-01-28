using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace Ant_Pheromone_Trails
{
	public partial class Form1 : Form
	{
		static int numAnts;
		static int height = 500;
		static int width = 500;
		static int numFoodPiles;
		static int foodPerPile;
		static int frame;

		static Bitmap mapBitmap;
		Graphics mapGraphics;

		static Bitmap graphBitmap;
		Graphics graphGraphics;

		bool initialized = false;
		bool stopped = false;

		World w;

		Color[] colors;

		public Form1()
		{
			InitializeComponent(); 

			mapBitmap = new Bitmap(width, height);
			mapGraphics = Graphics.FromImage(mapBitmap);
			picture.BackgroundImage = mapBitmap;

			graphBitmap = new Bitmap(graph.Width, graph.Height);
			graphGraphics = Graphics.FromImage(graphBitmap);
			graph.BackgroundImage = graphBitmap;


			colors = new Color[] {Color.FromArgb(25,25,255), Color.FromArgb(50,50,255),
								    Color.FromArgb(75,75,255), Color.FromArgb(100,100,255),
									Color.FromArgb(125,125,255), Color.FromArgb(150,150,255),
								    Color.FromArgb(175,175,255), Color.FromArgb(200,200,255),
								    Color.FromArgb(250,250,255)};
			colors.Reverse();
		}

		private void buttonRun_Click(object sender, EventArgs e)
		{
			RunAnts();
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
				buttonStop.Visible = true;
				this.Update();
				while (!stopped)
				{
					w.TimeStep();
					Display();
					Thread.Sleep(0);
					frame++;
				}
			}
		}

		void Display()
		{
			mapGraphics.Clear(Color.White);
			graphGraphics.Clear(Color.White);
			DrawPheromone();

			DrawGraph();

			foreach (Anthill hill in w.anthills)
			{
				DrawAnthill(hill);
			}
			foreach (Food food in w.foods)
			{
				DrawFood(food);
			}
			foreach (Ant ant in w.ants)
			{
				DrawAnt(ant);
			}
			this.Text = "Total food eaten: " + w.totalFoodInAnthill;
			picture.Update();
			graph.Update();
			this.Refresh();
		}

		private void DrawGraph()
		{
			double height = graphBitmap.Height;
			double width = graphBitmap.Width;
			for (int i = 0; i < w.foods.Count; i++)
			{
				graphGraphics.FillRectangle(new SolidBrush(Color.Green), 
									 (int) (i * width / w.foods.Count),
									 (int) (height - (height * (w.foods[i].amount / foodPerPile))),
									 (int) (width / w.foods.Count),
									 (int) (height * (w.foods[i].amount / foodPerPile)));
			}
		}

		private void DrawPheromone()
		{
			for (int x = 0; x < width; x++)
			{
				for (int y = 0; y < height; y++)
				{
					// Draw pheromone
                    float pheremoneLevel = w.pheromone[x, y];
					if (pheremoneLevel > 0)
					{
						//try
						{
                            mapBitmap.SetPixel(x, y, Color.Blue);
                        }
						//catch (System.Exception)
						{
						}
					}
				}
			}
		}

		private void DrawFood(Food food)
		{
			SolidBrush brush = new SolidBrush(Color.Green);
			mapGraphics.FillEllipse(brush, food.location);
		}

		private void DrawAnt(Ant ant)
		{

			mapGraphics.DrawEllipse(new Pen(Color.Black), ant.loc);
			if (ant.hasFood)
			{
				SolidBrush brush = new SolidBrush(Color.LightGreen);
				mapGraphics.FillEllipse(brush, ant.loc);
			}
		}

		private void DrawAnthill(Anthill anthill)
		{
			SolidBrush brush = new SolidBrush(Color.Red);
			mapGraphics.FillEllipse(brush, anthill.location);
		}

		private void buttonInitialize_Click(object sender, EventArgs e)
		{
			GetValuesFromInterface();
			w = new World(width, height, numAnts, numFoodPiles, foodPerPile);
			initialized = true;
			Display();
		}

		private void GetValuesFromInterface()
		{
			numAnts = int.Parse(textNumAnts.Text);
			numFoodPiles = int.Parse(textNumFood.Text);
			foodPerPile = int.Parse(textFoodPerPile.Text);
		}

		private void buttonStop_Click(object sender, EventArgs e)
		{
			stopped = true;
			buttonStop.Visible = false;
			this.Update();
		}
	}
}
