using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Drawing;

namespace MyCA
{
	class CATile : Button
	{
		public bool alive;

		public CATile()
		{
			Size = new System.Drawing.Size(15, 15);
			BackColor = Color.White;
			alive = false;

			Click += TileClicked;
		}

		public CATile(bool alive)
		{
			Size = new System.Drawing.Size(15, 15);
			BackColor = Color.White;
			this.alive = alive;
		}

		public void TileClicked(object sender, EventArgs e)
		{
			alive = !alive;
			Update();
		}

		
		public void Update()
		{
			if (alive) BackColor = Color.Black;
			else BackColor = Color.White;
		}


		public void SetState(bool alive)
		{
			this.alive = alive;
			Update();
		}
	}
}
