class CellStateSystem:
    """ This class mantians the current state of a cell,
        and insures that we cannot transition to the next state
        for that cell without having already determined the next state.
        
        The intended call order is SetNextState() then TransitionToNextState().
        Each call to TransitionToNextState() must be preceded by a call to SetNextState()."""
        
    currentState = CellState.DEAD
    nextState = None
    
    def SetNextState(self, nextState):
        self.nextState = nextState
        
    def TransitionToNextState(self):
        if self.nextState == None:
            print "Cannot transition to next state.  You must first determin next state."
        currentState = nextState
        nextState = None
        
    def GetCurrentState(self):
        return self.currentState