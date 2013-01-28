using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ForestFire
{
	public partial class Form1 : Form
	{
		Bitmap bmp;
		Graphics gpx;
		World world;
		int height = 200;
		int width = 200;
		

		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			bmp = new Bitmap(gridBox.Width, gridBox.Height);
			gridBox.Image = bmp;
			gpx = Graphics.FromImage(bmp);
			world = GenerateWorldFromForm();
			DrawWorld();
			gridBox.Refresh();
			timer1.Enabled = true;
		}

		private World GenerateWorldFromForm()
		{
			return new World(width, height, 
				(int)uiGrassBurnTime.Value, (int)uiBrushBurnTime.Value, (int)uiTreeBurnTime.Value,
				double.Parse(uiGrassToGrass.Text), double.Parse(uiGrassToBrush.Text), double.Parse(uiGrassToTree.Text),
				double.Parse(uiBrushToGrass.Text), double.Parse(uiBrushToBrush.Text), double.Parse(uiBrushToTree.Text),
				double.Parse(uiTreeToGrass.Text), double.Parse(uiTreeToBrush.Text), double.Parse(uiTreeToTree.Text),
				uiUpdateStyle.SelectedIndex == 0);
		}

		private void DrawWorld()
		{
			// CellType { Grass, Brush, Tree, Water, BareEarth }
			Color[] types = { Color.Green, Color.Goldenrod, Color.DarkGreen, Color.Blue, Color.Brown };
			int type = 0;
			for (int x = 0; x < width; x++)
				for (int y = 0; y < height; y++)
				{
					type = (int)world[x, y].Type;
					SolidBrush b = new SolidBrush(types[type]);
					gpx.FillRectangle(b, x * 4, y * 4, 4, 4);
				}
		}

		private void stepSimulation(object sender, EventArgs e)
		{
			world.Update();
			DrawWorld();
		}

		private void btnInitialize_Click(object sender, EventArgs e)
		{
			world = GenerateWorldFromForm();
		}

		private void btnRun_Click(object sender, EventArgs e)
		{
			timer1.Enabled = !timer1.Enabled;
			if (timer1.Enabled) btnRun.Text = "Stop";
			else btnRun.Text = "Run";
		}
	}
}
