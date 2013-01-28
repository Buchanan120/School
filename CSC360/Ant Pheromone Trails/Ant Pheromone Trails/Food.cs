﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Ant_Pheromone_Trails
{
	class Food
	{
		public Rectangle location;
		public int amount;
		public bool depleted = false;

		public Food(Rectangle l, int foodAmount)
		{
			location = l;
			amount = foodAmount;
		}

		public void GetFood()
		{
			amount--;
		}

		public bool IsDepleted()
		{
			if (amount <= 0)
				depleted = true;
			return depleted;
		}
	}
}
