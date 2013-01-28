using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace War_of_the_Ants
{
	class Ant
	{
		//public enum Directions { North, NE, East, SE, South, SW, West, NW };
		public enum Affiliance { Red, Blue };
		public enum Directions { East, NE, North, NW, West, SW, South, SE };
		public Directions dir;
		public Rectangle loc;
		public bool hasFood;
		public World world;
		public Rectangle home;
		static Random rand = new Random();
        float pheromoneStore = 1024;
		public bool isDead;
		public Ant[] enemyAnts;
		Affiliance affiliance;

		public Ant(Affiliance affiliance, World world, Rectangle home)
		{
			this.world = world;
			this.home = home;
			this.dir = (Directions)rand.Next(8);
			this.affiliance = affiliance;
			loc = home;
			hasFood = false;
			enemyAnts = new Ant[Constants.numAnts];
		}

		private void GetEnemyAntList()
		{
			switch (affiliance)
			{
				case Affiliance.Red:
					world.blueAnts.CopyTo(enemyAnts, 0);
					break;
				case Affiliance.Blue:
					world.redAnts.CopyTo(enemyAnts, 0);
					break;
			}
		}

		public void Act()
		{
			GetEnemyAntList();
			if (EnemyAntNearby())
			{
				try
				{
					Attack(GetNearbyEnemy());
				}
				catch (Exception)
				{
					return;
				}
			}
			// Bring food home
			else if (hasFood)
			{
				BringFoodHome();
				//ReleasePheromone();
			}
			// Find highest pheromone level
			else
			{
				// Get food if on top of it
				for (int i = 0; i < world.foods.Count; i++)
				{
					if (world.foods[i].location.IntersectsWith(loc))
					{
						GetFood(world.foods[i]);
						return;
					}
				}
				FindHighestPheromoneLevel();
			}
			Move();
		}

		private Ant GetNearbyEnemy()
		{
			foreach (Ant enemy in enemyAnts)
			{
				if (WithinSightRange(enemy.loc))
					return enemy;
			}
			throw new Exception("No nearby enemy");
		}

		private bool WithinSightRange(Rectangle location)
		{
			if (location.IntersectsWith(loc))
				return true;
			return false;
		}

		private void Attack(Ant target)
		{
			target.Kill();
		}

		private bool EnemyAntNearby()
		{
			foreach (Ant enemy in enemyAnts)
			{
				if (WithinSightRange(enemy.loc))
					return true;
			}
			return false;
		}

        private void ReleasePheromone()
        {
            float level = pheromoneStore * .05F;
            // drop an amount of pheromone in the world
            world.pheromone[loc.X, loc.Y] += level;

            // reduce my pheromone by that amount
            pheromoneStore -= level;
        }


		private void BringFoodHome()
		{
			if (home == loc)
			{
				hasFood = false;
				dir = dir - 4;
				if (dir < 0) dir += 8;
				switch(affiliance)
				{
					case Affiliance.Red:
						world.totalFoodEatenByRed++;
						break;
					case Affiliance.Blue:
						world.totalFoodEatenByBlue++;
						break;
				}
			}
			FaceHome();
		}

		private void FaceHome()
		{
			if (loc.X != home.X)
			{
				if (loc.X > home.X)
				{
					if (loc.Y != home.Y)
					{
						if (loc.Y > home.Y)
						{
							dir = Directions.NW;
						}
						else
							dir = Directions.SW;
					}
					else
						dir = Directions.West;
				}
				else
					if (loc.Y != home.Y)
					{
						if (loc.Y > home.Y)
						{
							dir = Directions.NE;
						}
						else
							dir = Directions.SE;
					}
					else
						dir = Directions.East;
			}
			else if (loc.Y != home.Y)
			{
				if (loc.Y > home.Y)
				{
					if (loc.Y != home.Y)
					{
						if (loc.Y > home.Y)
						{
							dir = Directions.NW;
						}
					}
					else
						dir = Directions.North;
				}
				else
				{
					if (loc.Y != home.Y)
					{
						if (loc.Y > home.Y)
						{
							dir = Directions.SW;
						}
					}
					else
						dir = Directions.South;
				}
			}

			// I'd like to replace the monster nested if else chain above with this,
			//	but the results are scary and I don't have time to fix it.
			//	Feel free to try this out for yourself.  The agents move in roughly the wrong direction.
			//Location self = new Location(loc.X, loc.Y);
			//Location target = new Location(home.X, home.Y);
			//dir = 8 - (Directions)GetSecondaryDirection(self, target);
		}

		/// <summary>
		/// Finds the closest direction from one point to another in an 8 neighbor system.
		/// </summary>
		/// <param name="start">Starting position</param>
		/// <param name="end">End position</param>
		/// <returns>Float direction 0-7 for use in an 8 neighbor system.</returns>
		private float GetSecondaryDirection(Location start, Location end)
        {
            // Find direction in radians from start to end points
            double direction = GetDirectionInRadians(start, end);

			// Convert from radians to secondary direction denoted by 0-7.
            // Get direction + pi/8 then divide by pi / 4 
            direction += Math.PI * .8;
            direction = (direction * 4) / Math.PI;
            return (float)direction;
        }

		/// <summary>
		/// Finds direction in radians from a start to an end point
		/// </summary>
		/// <param name="start">Starting position</param>
		/// <param name="end">End position</param>
		/// <returns>Direction in radians from start to end as double.</returns>
		private double GetDirectionInRadians(Location start, Location end)
		{
			if ((start.x - end.x) != 0)
				return Math.Atan((start.y - end.y) / (start.x - end.x));
			else if (start.y < end.y)
				return 3 * Math.PI;
			else return Math.PI / 2;
		}

		private void FindHighestPheromoneLevel()
		{
			float highestPheremone = 0F;

            if (world.pheromone[loc.X, loc.Y - 1] != highestPheremone)
			{
				highestPheremone = world.pheromone[loc.Y, loc.Y - 1];
				dir = Directions.North;
			}
			
			if (world.pheromone[loc.X + 1, loc.Y - 1] > highestPheremone)
			{
				highestPheremone = world.pheromone[loc.X + 1, loc.Y - 1];
				dir = Directions.NE;
			}
		
			if (world.pheromone[loc.X + 1, loc.Y] > highestPheremone)
			{
				highestPheremone = world.pheromone[loc.X + 1, loc.Y];
				dir = Directions.East;
			}
		
			if (world.pheromone[loc.X + 1, loc.Y + 1] > highestPheremone)
			{
				highestPheremone = world.pheromone[loc.X + 1, loc.Y - 1];
				dir = Directions.SE;
			}
		
			if (world.pheromone[loc.X, loc.Y + 1] > highestPheremone)
			{
				highestPheremone = world.pheromone[loc.X, loc.Y + 1];
				dir = Directions.South;
			}
		
			if (world.pheromone[loc.X - 1, loc.Y + 1] > highestPheremone)
			{
				highestPheremone = world.pheromone[loc.X - 1, loc.Y + 1];
				dir = Directions.SW;
			}
		
			if (world.pheromone[loc.X - 1, loc.Y] > highestPheremone)
			{
				highestPheremone = world.pheromone[loc.X - 1, loc.Y];
				dir = Directions.West;
			}
		
			if (world.pheromone[loc.X - 1, loc.Y - 1] > highestPheremone)
			{
				highestPheremone = world.pheromone[loc.X - 1, loc.Y - 1];
				dir = Directions.NW;
			}
		}

		private void Move()
		{
			{
				int temp = (int)rand.Next(20);
				if (temp == 0)
					dir -= 1;
				else if (temp == 1)
					dir += 1;
				if (dir < 0)
					dir += 1;
				else if (dir > (Directions)7)
					dir -= 1;
			}
			switch (dir)
			{
				case Directions.North:
					if (loc.Y >= 3)
						loc.Y -= 1;
					else
					{
						while (dir == Directions.North)
						{
							dir = (Directions)rand.Next(8);
						}
					}
					break;
				case Directions.NE:
					if (loc.Y >= 3 && loc.X < world.width - 3)
					{
						loc.Y -= 1;
						loc.X += 1;
					}
					else
					{
						while (dir == Directions.North || dir == Directions.NE || dir == Directions.East)
						{
							dir = (Directions)rand.Next(8);
						}
					}
					break;
				case Directions.East:
					if (loc.X < world.width - 3)
						loc.X += 1;
					else
					{
						while (dir == Directions.East)
						{
							dir = (Directions)rand.Next(8);
						}
					}
					break;
				case Directions.SE:
					if (loc.X < world.width - 3 && loc.Y < world.height - 3)
					{
						loc.X += 1;
						loc.Y += 1;
					}
					else
					{
						while (dir == Directions.East || dir == Directions.SE || dir == Directions.South)
						{
							dir = (Directions)rand.Next(8);
						}
					}
					break;
				case Directions.South:
					if (loc.Y < world.height - 3)
						loc.Y += 1;
					else
					{
						while (dir == Directions.South)
						{
							dir = (Directions)rand.Next(4);
						}
					}
					break;
				case Directions.SW:
					if (loc.X >= 3 && loc.Y < world.height - 3)
					{
						loc.Y += 1;
						loc.X -= 1;
					}
					else
					{
						while (dir == Directions.West || dir == Directions.SW || dir == Directions.South)
						{
							dir = (Directions)rand.Next(8);
						}
					}
					break;
				case Directions.West:
					if (loc.X >= 3)
						loc.X -= 1;
					else
					{
						while (dir == Directions.West)
						{
							dir = (Directions)rand.Next(4);
						}
					}
					break;
				case Directions.NW:
					if (loc.X >= 3 && loc.Y >= 3)
					{
						loc.X -= 1;
						loc.Y -= 1;
					}
					else
					{
						while (dir == Directions.West || dir == Directions.NW || dir == Directions.North)
						{
							dir = (Directions)rand.Next(8);
						}
					}
					break;
			}
		}

		private void GetFood(Food food)
		{
			hasFood = true;
            Location foodLocation = new Location(food.location.Left, food.location.Top);
			ReleasePheromoneOnFood(foodLocation);
			food.GetFood();
		}

		private void ReleasePheromoneOnFood(Location foodLocation)
		{
			world.pheromone[foodLocation.x, foodLocation.y] += pheromoneStore * .9F;
		}


		protected void Kill()
		{
			isDead = true;
		}
	}
}
