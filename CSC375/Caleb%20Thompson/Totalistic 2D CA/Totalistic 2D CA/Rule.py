import System.Collections.Generic.List

class Rule:
    """A rule can tell you the next state for a cell
    given the current state of that cell and
    the number of live neighbors of that cell"""
    
    def GetNextState(currentState, numberOfLiveNeighbors):
        return

class GenericRule(Rule):
    """This rule class will accept any totalistic rule for a 2 state CA"""
    survivalCounts = List<int>()
    birthCounts = List<int>()
    
    def __init__(self, survivalCounts, birthCounts):
        self.survivalCounts.AddRange(survivalCounts)
        self.birthCounts.AddRange(birthCounts)
        
    def GetNextState(self, currentState, numberOfLiveNeighbors):
        if currentState == CellState.ALIVE:
            if survivalCounts.Contains(numberOfLiveNeighbors):
                return CellState.ALIVE
            else:
                return CellState.DEAD
        else:
            if birthCounts.Contains(numberOfLiveNeighbors):
                return CellState.ALIVE
            else:
                return CellState.DEAD
            

    
    
