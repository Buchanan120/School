using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;

namespace Genetic_Algorithm
{
    public partial class GA : Form
	{
		int _popSize = 0;
		double _mutationRate = 0;
		double _elitism = 0;
		int _target = 0;
		int _numCoins = 0;
		int _genCount = 0;
		Genome[] _initialPopulation;

		bool[] _coinsUsed = new bool[6];
		bool _initialized;
        bool _solutionFound;
		Random rand = new Random();
		public enum CoinValues { pennies = 1, nickels = 5, dimes = 10, quarters = 25, halfDollars = 50, dollars = 100 };
		public enum CoinNames { pennies, nickels, dimes, quarters, halfDollars, dollars };

        public GA()
        {
            InitializeComponent();
		}

        private void buttonRun_Click(object sender, EventArgs e)
        {
			if (_initialized)
			{
				int numGenerations = Int32.Parse(textNumGenerations.Text.ToString());
				for (int generation = 0; generation < numGenerations; generation++)
				{
					_initialPopulation = RunGA(_initialPopulation);
					if (checkStopAtTarget.Checked)
					{
						if (_solutionFound)
							break;
					}
						
				}
			}
			else
			{
				MessageBox.Show("You must initialize the GA.");
			}

		}

		private void buttonInitialize_Click(object sender, EventArgs e)
		{
			GetValuesFromInterface();
			textOutput.Clear();
			_initialized = true;
            _solutionFound = false;
			_genCount = 0;
			_initialPopulation = CreateRandomPopulation(_popSize, _coinsUsed);
		}

        private void GetValuesFromInterface()
        {
            _popSize = Int32.Parse(textPopulationSize.Text.ToString());
            _mutationRate = Double.Parse(textMutationRate.Text.ToString());
            _elitism = Double.Parse(textElitism.Text.ToString());
            _numCoins = Int32.Parse(textNumCoins.Text.ToString());
            _target = Int32.Parse(textTargetValue.Text.ToString());
            _coinsUsed[(int)CoinNames.pennies] = checkPennies.Checked;
            _coinsUsed[(int)CoinNames.nickels] = checkNickels.Checked;
            _coinsUsed[(int)CoinNames.dimes] = checkDimes.Checked;
            _coinsUsed[(int)CoinNames.quarters] = checkQuarters.Checked;
            _coinsUsed[(int)CoinNames.halfDollars] = checkHalfDollars.Checked;
            _coinsUsed[(int)CoinNames.dollars] = checkDollars.Checked;
        }

		private Genome[] RunGA(Genome[] population)
		{
			population = OrganizeGeneration(population);
			Genome[] nextGen = CreateNextGeneration(population);
			nextGen.CopyTo(population, 0);
			_genCount++;
			population = OrganizeGeneration(population);
			DisplayGeneration(population, _genCount);
			_solutionFound = SolutionFound(population);
			return population;
		}

		private Genome[] OrganizeGeneration(Genome[] population)
		{
			// Order genes in population by fitness
			IEnumerable<Genome> orderedPopulation = population.OrderBy(genome => genome.Fitness(_target));
			return orderedPopulation.ToArray<Genome>();
		}

		private void DisplayGeneration (Genome[] population, int genCount)
        {
			textOutput.Clear();
			StringBuilder sb = new StringBuilder(100 * _popSize);
			foreach (Genome genome in population)
			{
				int[] current = genome.ToArray();

				sb.Append(genome.Fitness(_target).ToString()
					+ "\t0.01: " + GetPaddedValue(current[(int)CoinNames.pennies], 2)
					+ " 0.05: " + GetPaddedValue(current[(int)CoinNames.nickels], 2)
					+ " 0.10: " + GetPaddedValue(current[(int)CoinNames.dimes], 2)
					+ " 0.25: " + GetPaddedValue(current[(int)CoinNames.quarters], 2)
					+ " 0.50: " + GetPaddedValue(current[(int)CoinNames.halfDollars], 2)
					+ " 1.00: " + GetPaddedValue(current[(int)CoinNames.dollars], 2)
					+ " Total: " + GetDollarValue(genome).ToString()
					+ "\r\n");
			}
			textOutput.Text = sb.ToString();
			this.Text = "Generation #" + genCount;
			this.Update();
			Thread.Sleep(25);
        }

		private Genome[] CreateRandomPopulation(int _popSize, bool[] _coinsUsed)
		{
			Genome[] population = new Genome[_popSize];
			for (int i = 0; i < _popSize; i++)
				population[i] = new Genome();
			int numCoinsRemaining = _numCoins;
			// Get random values which add up to _numCoins
			for (int genome = 0; genome < _popSize; genome++)
			{
				for (int coin = 0; coin < 5; coin++)
				{
					if (_coinsUsed[coin])
					{
						population[genome].Set(coin, rand.Next(numCoinsRemaining));
						numCoinsRemaining -= population[genome].Get(coin);
					}
				}
				population[genome].Set(5, numCoinsRemaining);
				numCoinsRemaining = _numCoins;
			}
			// Further randomize by changing order of values randomly
			foreach (Genome genome in population)
			{
				genome.Randomize();
				for (int i = 0; i < 6; i++)
				{
					if (!_coinsUsed[i])
					{
						if (genome.Get(i) != 0)
						{
							int indexToSwapWith = genome.Find(0);
							genome.Swap(i, indexToSwapWith);
						}
					}
				}
			}
			return population;
		}

		private Genome[] CreateNextGeneration(Genome[] population)
		{
			Genome[] nextGen = new Genome[_popSize];
			int numGenesToKeep = (int)(_popSize * _elitism);
			//for (int i = 0; i < numGenesToKeep; i++)
			//{
			//    nextGen[i] = population[i].ToArray();
			//}
			//nextGen = population.ToArray();
			population.ToArray().CopyTo(nextGen, 0);
			for (int i = numGenesToKeep; i < _popSize; i++)
			{
				Genome copyOfParent = PickAFitParent(population);
				Genome child = ApplyMutation(copyOfParent);
				nextGen[i] = child;
			}
			return OrganizeGeneration(nextGen);
		}

        private Genome PickAFitParent(Genome[] population)
        {
            int parentIndex1 = rand.Next(_popSize);
            int parentIndex2 = rand.Next(_popSize);

            Genome parent;

			if (population[parentIndex1].Fitness(_target) < population[parentIndex2].Fitness(_target))
				parent = population[parentIndex1];
			else
                parent = population[parentIndex2];

            return parent.Clone();
        }

		private Genome ApplyMutation(Genome genome)
		{
			for (int gene = 0; gene < _numCoins; gene++)
			{
				if (rand.NextDouble() < _mutationRate)
				{
					int numIndicesToSkip = rand.Next(4) + 1; // Avoids using the same index
					int startIndex = rand.Next(6);
					// Make sure neither of the indices we are swapping are spaces for population not being used.
					while (!_coinsUsed[startIndex])
					{
						startIndex = rand.Next(6);
					}
					// complicated check ensures that we are checking inside the array
					while (!_coinsUsed[(startIndex + numIndicesToSkip) % 6])
					{
						numIndicesToSkip = rand.Next(4) +1;
					}
					int amountToSwap = rand.Next(genome[startIndex]);
					genome[startIndex] -= amountToSwap;
					genome[(numIndicesToSkip + startIndex) % 6] += amountToSwap;
				}
			}
			return genome;
		}

		private bool SolutionFound(Genome[] population)
		{
			foreach (Genome genome in population)
			{
				if (genome.Fitness(_target) == 0)
				    return true;
			}
			return false;
		}

		private double GetDollarValue(Genome genome)
		{
			double dollarValue = 0;
			dollarValue +=
				+ genome.Get((int)CoinNames.pennies) * ((double)CoinValues.pennies / 100)
				+ genome.Get((int)CoinNames.nickels) * ((double)CoinValues.nickels / 100)
				+ genome.Get((int)CoinNames.dimes) * ((double)CoinValues.dimes / 100)
				+ genome.Get((int)CoinNames.quarters) * ((double)CoinValues.quarters / 100)
				+ genome.Get((int)CoinNames.halfDollars) * ((double)CoinValues.halfDollars / 100)
				+ genome.Get((int)CoinNames.dollars) * ((double)CoinValues.dollars / 100);
			return dollarValue;
		}

		private void PrintPaddedValue(int value, int numberOfDesiredDigits)
		{
			if (value.ToString().Length < numberOfDesiredDigits)
			{
				for (int i = 0; i < numberOfDesiredDigits - value.ToString().Length; i++)
					Console.Write("0");
			}

			Console.Write(value);
		}

		private string GetPaddedValue(int value, int numberOfDesiredDigits)
		{
			StringBuilder sb = new StringBuilder(numberOfDesiredDigits);
			if (value.ToString().Length < numberOfDesiredDigits)
			{
				for (int i = 0; i < numberOfDesiredDigits - value.ToString().Length; i++)
					sb.Append("0");
			}

			sb.Append(value.ToString());
			return sb.ToString();
		}
    }
}
