using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace LangtonsLoop
{
    public class World
    {
        public Cell[,] grid;
        int height, width;
        private int p;
        private int p_2;
        private System.Data.Rule langtons;

        public World(int width, int height, Rule rule)
        {
            int[,] seedRule = { {0,2,2,2,2,2,2,2,2,0,0,0,0,0,0}, 
                                {2,1,7,0,1,4,0,1,4,2,0,0,0,0,0}, 
                                {2,0,2,2,2,2,2,2,0,2,0,0,0,0,0},
                                {2,7,2,0,0,0,0,2,1,2,0,0,0,0,0},
                                {2,1,2,0,0,0,0,2,1,2,0,0,0,0,0},
                                {2,0,2,0,0,0,0,2,1,2,0,0,0,0,0},
                                {2,7,2,0,0,0,0,2,1,2,0,0,0,0,0},
                                {2,1,2,2,2,2,2,2,1,2,2,2,2,2,0},
                                {2,0,7,1,0,7,1,0,7,1,1,1,1,1,2},
                                {0,2,2,2,2,2,2,2,2,2,2,2,2,2,0} };
            this.height = height;
            this.width = width;
            grid = new Cell[width, height];

            //initialize cells
            for (int x = 0; x < width; x++)
                for (int y = 0; y < height; y++)
                    grid[x, y] = new Cell(this, Cell.CellState.Nothing, rule);


            // create initial loop
            int startX = width/2 - 7;
            int startY = height/2 - 5;
            for (int x = 0; x < 10; x++)
                for (int y = 0; y < 15; y++)
                {
                    grid[startX + x, startY + y].State = (Cell.CellState)seedRule[y, x];
                    Console.WriteLine('[' + x + ',' + y + ']');
                }
            
        }

        public void Update()
        {
            for (int x = 0; x < width; x++)
            {
                for (int y = 0; y < height; y++)
                {
                    this.grid[x, y].determineNextState();
                    this.grid[x, y].changeState();
                }
            }
        }

        internal Dictionary<String, Cell> getNeighborList(Cell cell)
        {
            for (int x = 0; x < width; x++)
                for (int y = 0; y < height; y++)
                    if (grid[x, y] == cell)
                    {
                        Dictionary<String, Cell> neighbors = new Dictionary<string, Cell>();
                        neighbors.Add("Up", grid[x, y - 1]);
                        neighbors.Add("Down", grid[x, y + 1]);
                        neighbors.Add("Left", grid[x - 1, y]);
                        neighbors.Add("Right", grid[x + 1, y]);
                        return neighbors;
                    }
            throw new Exception("Cell called World.getNeighborList, but is not contained in grid.");

        }

        public Cell this[int x, int y]
        {
            get { return grid[x, y]; }
        }
    }
}
