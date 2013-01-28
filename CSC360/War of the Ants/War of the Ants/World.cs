using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Threading;

namespace War_of_the_Ants
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
		public Anthill[] anthills;
		public List<Ant> blueAnts;
		public List<Ant> redAnts;
		public List<Food> foods;
		public Thread t;
		public const int ANTHILL = 1, SPACE = 0;
		public float[,] pheromone;
		public int height, width;
		public int totalFoodEatenByBlue = 0;
		public int totalFoodEatenByRed = 0;
		public int[,] field;
		static Random rand = new Random();

		public World(int initWidth, int initHeight, int numAnts, int numFoodPiles, int foodPerPile)
		{
			t = new Thread(TimeStep);
			height = initHeight;
			width = initWidth;
			field = new int[width + 50, height + 50];
			pheromone = new float[width + 50, height + 50];
			redAnts = new List<Ant>();
			blueAnts = new List<Ant>();
			foods = new List<Food>();
			anthills = new Anthill[2];
			// create anthill
            Location anthill0 = new Location(width / 4, height / 2);
            Location anthill1 = new Location(3 * width / 4, height / 2);
			anthills[0] = new Anthill(new Rectangle(anthill0.x - 7, anthill0.y - 7, 14, 14));
            anthills[1] = new Anthill(new Rectangle(anthill1.x - 7, anthill1.y - 7, 14, 14));
			// create ants
			for (int i = 0; i < numAnts; i++ )
            {
				redAnts.Add(new Ant(Ant.Affiliance.Red, this, new Rectangle(anthill0.x - 2, anthill0.y - 2, 4, 4)));
				blueAnts.Add(new Ant(Ant.Affiliance.Blue, this, new Rectangle(anthill1.x - 2, anthill1.y - 2, 4, 4)));
            }
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
			// red
			foreach (Ant ant in new List<Ant>(redAnts))
			{
				if (ant.isDead)
					redAnts.Remove(ant);
				else
					ant.Act();
            }
			// blue
            foreach (Ant ant in new List<Ant>(blueAnts))
            {
				if (ant.isDead)
					blueAnts.Remove(ant);
				else
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
                    pheromone[x, y] = pheromone[x, y] * Constants.EVAPORATION_RATE;
                }
            }

            // Diffusion
			for (int x = 0; x < width; x++)
			{
				for (int y = 0; y < height; y++)
				{
					if (pheromone[x, y] != 0)
					{
						float level = (pheromone[x, y] * Constants.DIFFUSION_RATE) / 8;

						nextPheromone[x, y] -= pheromone[x, y] * Constants.DIFFUSION_RATE;

						// neighbors
                        if (y > 0)
						    nextPheromone[x, y - 1] += level;
                        if (y < height)
						    nextPheromone[x, y + 1] += level;
                        if (x > 0)
                        {
                            nextPheromone[x - 1, y] += level;
                            if (y > 0)
                                nextPheromone[x - 1, y - 1] += level * 1.25F;
                            if (y < height)
                                nextPheromone[x - 1, y + 1] += level * 1.25F;
                        }
                        if (x < width)
                        {
                            nextPheromone[x + 1, y] += level;
                            if (y > 0)
                                nextPheromone[x + 1, y - 1] += level * 1.25F;
                            if (y < height)
                                nextPheromone[x + 1, y + 1] += level * 1.25F;
                        }

                    }
                    if (pheromone[x, y] > 2550)
                        pheromone[x, y] = 2550;
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
