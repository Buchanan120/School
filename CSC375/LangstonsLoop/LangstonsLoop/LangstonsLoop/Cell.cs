using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace LangtonsLoop
{
    public class Cell
    {
        public enum CellState { Nothing, Null }
        World world;
        CellState currentState;
        CellState nextState;
        Rule rule;

        public Cell(World world, CellState initialState, Rule rule)
        {
            this.world = world;
            this.currentState = initialState;
            this.rule = rule;
        }

        public CellState State
        {
            get { return currentState; }
            set { nextState = value; changeState(); }
        }

        private Dictionary<String, Cell> getNeighborList()
        {
            return world.getNeighborList(this);
        }

        internal void determineNextState()
        {
            Dictionary<String, Cell> neighbors = getNeighborList();
            nextState = (Cell.CellState)rule.ruleIndex[
                (int)currentState, 
                (int)neighbors["Up"].State, 
                (int)neighbors["Right"].State, 
                (int)neighbors["Down"].State, 
                (int)neighbors["Left"].State];
        }

        internal void changeState()
        {
            if (nextState == CellState.Null)
            {
                throw new Exception("Cannot change state while nextState is CellState.Null");
            }
            this.currentState = this.nextState;
            this.nextState = CellState.Null;
        }

    }
}
