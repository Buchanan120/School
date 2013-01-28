using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Genetic_Algorithm
{
	public enum CoinValues { pennies = 1, nickels = 5, dimes = 10, quarters = 25, halfDollars = 50, dollars = 100 };
	public enum CoinNames { pennies, nickels, dimes, quarters, halfDollars, dollars };

	class Genome
	{
		int[] _genes = new int[6];
		Random rand = new Random();

		public Genome()
		{
			for (int i = 0; i < 6; i++)
				_genes[i] = 0;
		}
		public Genome(int[] values)
		{
			for (int i = 0; i < 6; i++)
				_genes[i] = values[i];
		}

		public void Set(int index, int value)
		{
			_genes[index] = value;
		}

		public int Get(int index)
		{
			return _genes[index];
		}

		public void Randomize()
		{
			_genes.OrderBy(x => rand.Next()).ToArray();
		}

		public void Swap(int first, int second)
		{
			int temp = _genes[first];
			_genes[first] = _genes[second];
			_genes[second] = temp;
		}

		public int Find(int value)
		{
			for (int i = 0; i < 6; i++)
			{
				if (_genes[i] == value)
					return i;
			}
			return -1;
		}

        public int[] ToArray()
        {
            return _genes;
        }

		public int this[int index]
		{
			get
			{
				if (index < 0 || index >= 6)
				{
					throw new IndexOutOfRangeException();
				}
				return _genes[index];
			}
			set
			{
				if (index < 0 || index >= 6)
				{
					throw new IndexOutOfRangeException();
				}

				_genes[index] = value;
			}
		}

        public Genome Clone()
        {
            Genome aGenome = new Genome();
            for (int i = 0; i < 6; i++)
                aGenome.Set(i, Get(i));

            return aGenome;
        }

		public int Fitness(int target)
		{
			int fitness = target * -1;
			fitness +=
				(Get((int)CoinNames.pennies) * (int)CoinValues.pennies) +
				(Get((int)CoinNames.nickels) * (int)CoinValues.nickels) +
				(Get((int)CoinNames.dimes) * (int)CoinValues.dimes) +
				(Get((int)CoinNames.quarters) * (int)CoinValues.quarters) +
				(Get((int)CoinNames.halfDollars) * (int)CoinValues.halfDollars) +
				(Get((int)CoinNames.dollars) * (int)CoinValues.dollars);

			if (fitness < 0)
				fitness *= -1;
			return fitness;
		}
    }
}
