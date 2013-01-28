using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ForestFire
{
	public class World
	{
		private Cell[,] grid;
		public int height;
		public int width;
		private static Random rand;
		private bool synchronous;
		double grassToGrassChance;
		double grassToBrushChance;
		double grassToTreeChance;
		double brushToGrassChance;
		double brushToBrushChance;
		double brushToTreeChance;
		double treeToGrassChance;
		double treeToBrushChance;
		double treeToTreeChance;

		public World(int width, int height, 
			int grassBurnTime, int brushBurnTime, int treeBurnTime, 
			double grassToGrassChance, double grassToBrushChance, double grassToTreeChance, 
			double brushToGrassChance, double brushToBrushChance, double brushToTreeChance, 
			double treeToGrassChance, double treeToBrushChance, double treeToTreeChance,
			bool synchronous)
		{
			rand = new Random();
			this.synchronous = synchronous;
			this.width = width;
			this.height = height;

			this.grassToGrassChance = grassToGrassChance;
			this.grassToBrushChance = grassToBrushChance;
			this.grassToTreeChance = grassToTreeChance;

			this.brushToGrassChance = brushToGrassChance;
			this.brushToBrushChance = brushToBrushChance;
			this.brushToTreeChance = brushToTreeChance;

			this.treeToGrassChance = treeToGrassChance;
			this.treeToBrushChance = treeToBrushChance;
			this.treeToTreeChance = treeToTreeChance;

			grid = new Cell[width, height];
			for (int x = 0; x < width; x++)
				for (int y = 0; y < height; y++)
					grid[x, y] = new Cell(this, (Cell.CellType)rand.Next(5), grassBurnTime, brushBurnTime, treeBurnTime);
		}

		public void Update()
		{
			if (synchronous)
			{
				for (int x = 0; x < width; x++)
					for (int y = 0; y < height; y++)
						grid[x, y].Update();
			}
			else
			{
				// asynchronus updating
			}
		}

		public double GetChanceToStartBurning(Cell cell)
		{
			if (cell.Type == Cell.CellType.Water || cell.Type == Cell.CellType.BareEarth) return 0;
			for (int x = 0; x < width; x++)
			{
				for (int y = 0; y < height; y++)
				{
					if (grid[x, y] == cell)
					{
						double chanceToBurn = 0;
						try
						{
							if (grid[x, y - 1].Burning)
							{
								chanceToBurn += GetChanceToBurnFromFuelTypes(grid[x, y].Type, grid[x, y - 1].Type);
							}
						}
						catch (IndexOutOfRangeException e)
						{
							if (y != 0)
								throw e;
							// otherwise, nothing is wrong.
						}
						try
						{
							if (grid[x, y + 1].Burning)
							{
								chanceToBurn += GetChanceToBurnFromFuelTypes(grid[x, y].Type, grid[x, y - 1].Type);
							}
						}
						catch (IndexOutOfRangeException e)
						{
							if (y != height - 1)
								throw e;
							// otherwise, nothing is wrong.
						}
						try
						{
							if (grid[x - 1, y].Burning)
							{
								chanceToBurn += GetChanceToBurnFromFuelTypes(grid[x, y].Type, grid[x, y - 1].Type);
							}
						}
						catch (IndexOutOfRangeException e)
						{
							if (x != 0)
								throw e;
							// otherwise, nothing is wrong.
						}
						try
						{
							if (grid[x + 1, y].Burning)
							{
								chanceToBurn += GetChanceToBurnFromFuelTypes(grid[x, y].Type, grid[x, y - 1].Type);
							}
						}
						catch (IndexOutOfRangeException e)
						{
							if (x != width - 1)
								throw e;
							// otherwise, nothing is wrong.
						}
						return chanceToBurn;
					}
				}
			}
			throw new Exception("World.GetNumberOfBurningNeighbors cannot find the specified cell.");
		}

		/// <summary>
		/// Finds chance of burning from user-set variables
		/// </summary>
		/// <param name="typeTo">The Cell.CellType that the fire might spread to.</param>
		/// <param name="typeFrom">The Cell.CellType that the fire might spread from.</param>
		/// <throws>Exception when it cannot find the specified combination of from/to types.</throws>
		/// <returns>The percentage chance of fire spreading from a cell of type typeFrom to a cell of type typeFrom</returns>
		private double GetChanceToBurnFromFuelTypes(Cell.CellType typeTo, Cell.CellType typeFrom)
		{
			switch (typeFrom)
			{
				case Cell.CellType.Grass:
					switch (typeTo)
					{
						case Cell.CellType.Grass:
							return this.grassToGrassChance;
						case Cell.CellType.Brush:
							return this.grassToBrushChance;
						case Cell.CellType.Tree:
							return this.grassToTreeChance;
						default:
							throw new Exception("World.GetChanceToBurnFromFuelTypes cannot find the specified typeTo/typeFrom combination.");
					}
				case Cell.CellType.Brush:
					switch (typeTo)
					{
						case Cell.CellType.Grass:
							return this.brushToGrassChance;
						case Cell.CellType.Brush:
							return this.brushToBrushChance;
						case Cell.CellType.Tree:
							return this.brushToTreeChance;
						default:
							throw new Exception("World.GetChanceToBurnFromFuelTypes cannot find the specified typeTo/typeFrom combination.");
					}
				case Cell.CellType.Tree:
					switch (typeTo)
					{
						case Cell.CellType.Grass:
							return this.treeToGrassChance;
						case Cell.CellType.Brush:
							return this.treeToBrushChance;
						case Cell.CellType.Tree:
							return this.treeToTreeChance;
						default:
							throw new Exception("World.GetChanceToBurnFromFuelTypes cannot find the specified typeTo/typeFrom combination.");
					}
				default:
					throw new Exception("World.GetChanceToBurnFromFuelTypes cannot find the specified typeTo/typeFrom combination.");
			}
		}

		public Cell this[int x, int y]
		{
			get { return this.grid[x, y]; }
			set { this.grid[x, y] = value; }
		}

	}
}
