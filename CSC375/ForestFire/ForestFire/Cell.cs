using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ForestFire
{
	public class Cell
	{
		public enum CellType { Grass, Brush, Tree, Water, BareEarth };
		private CellType type;
		private World world;
		private bool burning;
		private int burnTimeLeft;
		private int grassBurnTime;
		private int brushBurnTime;
		private int treeBurnTime;
		private static Random rand;

		public Cell(World world, CellType type, int grassBurnTime, int brushBurnTime, int treeBurnTime)
		{
			// TODO: Complete member initialization
			this.type = type;
			this.world = world;
			this.grassBurnTime = grassBurnTime;
			this.brushBurnTime = brushBurnTime;
			this.treeBurnTime = treeBurnTime;
			rand = new Random();
		}

		public bool Burning
		{
			get { return burning; }
			set { 
				if (value)
				{
					// Water and Bare Earth cannot burn.  This prevents that from happening, albiet quietly.
					if (this.type == CellType.Water || this.type == CellType.BareEarth)
						burning = false;
					else
						switch (this.type)
						{
							case CellType.Grass:
								burnTimeLeft = grassBurnTime;
								break;
							case CellType.Brush:
								burnTimeLeft = brushBurnTime;
								break;
							case CellType.Tree:
								burnTimeLeft = treeBurnTime;
								break;
							default:
								throw new ArgumentException("Cell.Burning.set cannot find the specified CellType (How did you get here?).");
						}
				}
				else
					burning = value; 
			}
		}

		public CellType Type
		{
			get { return type; }
			set { type = value; }
		}


		internal void Update()
		{
			if (burning)
			{
				if (burnTimeLeft <= 0)
					this.type = CellType.BareEarth;
				else
					burnTimeLeft--;
			}
			else
			{
				if (this.type != CellType.Water && this.type != CellType.BareEarth)
				{
					if (rand.NextDouble() >= GetChanceToStartBurning())
						this.Burning = true;
				}
			}
		}

		private double GetChanceToStartBurning()
		{
			return world.GetChanceToStartBurning(this);
		}

	}
}
