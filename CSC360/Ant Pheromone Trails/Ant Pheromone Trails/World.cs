using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Threading;

namespace Ant_Pheromone_Trails
{
	class Location
	{
		public int x, y;

		public Location(int initX, int initY)
		{
			x = initX;
			y = initY;
		}
	}
	class World
	{
		public const int ANTHILL = 1, SPACE = 0;
		public int[,] field;
		public float[,] pheromone;
		public Ant[] ants;
		public List<Food> foods;
		public Anthill[] anthills;
		public int totalFoodInAnthill = 0;
		static Random rand = new Random();
		public int height, width;
		public Thread t;
        const float EVAPORATION_RATE = .99F;
        const float DIFFUSION_RATE = .1F;

		public World(int initWidth, int initHeight, int numAnts, int numFoodPiles, int foodPerPile)
		{
			t = new Thread(TimeStep);
			height = initHeight;
			width = initWidth;
			field = new int[width + 50, height + 50];
			pheromone = new float[width + 50, height + 50];
			ants = new Ant[numAnts];
			foods = new List<Food>();
			anthills = new Anthill[1];
			// create anthill
			anthills[0] = new Anthill(new Rectangle((width / 2) - 7, (height / 2) - 7, 14, 14));
			// create ants
			for (int i = 0; i < numAnts; i++ )
				ants[i] = new Ant(this, new Rectangle(width / 2 - 3, height / 2 - 3, 6, 6));
			// create food
			for (int i = 0; i < numFoodPiles; i++)
				foods.Add(new Food(new Rectangle((int)rand.Next(25, width - 25), (int)rand.Next(25, height - 25), 10, 10), foodPerPile));
		}

		public void TimeStep()
		{
			DissipatePheromone();
			for (int i = 0; i < foods.Count; i++)
			{
				if (foods[i].IsDepleted())
				{
					foods.RemoveAt(i);
				}
			}
			foreach (Ant ant in ants)
			{
				ant.Act();
			}			
		}

		private void DissipatePheromone()
		{
			float[,] nextPheromone = new float[width + 50, height + 50];

            // Evaporation
            for (int x = 0; x < width; x++)
            {
                for (int y = 0; y < height; y++)
                {
                    pheromone[x, y] = pheromone[x, y] * EVAPORATION_RATE;
                }
            }

            // Diffusion
			for (int x = 0; x < width; x++)
			{
				for (int y = 0; y < height; y++)
				{
					if (pheromone[x, y] != 0)
					{
						float level = (pheromone[x, y] * DIFFUSION_RATE) / 4;

                        nextPheromone[x, y] -= pheromone[x, y] * DIFFUSION_RATE;

						// neighbors
                        if (y > 0)
						    nextPheromone[x, y - 1] += level;
                        if (y < height)
						    nextPheromone[x, y + 1] += level;
                        if (x > 0)
                        {
                            nextPheromone[x - 1, y] += level;
                            if (y > 0)
                                nextPheromone[x - 1, y - 1] += level;
                            if (y < height)
                             nextPheromone[x - 1, y + 1] += level;
                        }
                        if (x < width)
                        {
                            nextPheromone[x + 1, y] += level;
                            if (y > 0)
                                nextPheromone[x + 1, y - 1] += level;
                            if (y < height)
                                nextPheromone[x + 1, y + 1] += level;
                        }

					}
                    //if (pheremone[x, y] > 2550)
                    //    pheremone[x, y] = 2550;
                    if (pheromone[x, y] < 1)
                        pheromone[x, y] = 0;
				}
			}
            for (int x = 0; x < width; x++)
            {
                for (int y = 0; y < height; y++)
                {
                    pheromone[x, y] = nextPheromone[x, y];
                }
            }
		}
    }
}
