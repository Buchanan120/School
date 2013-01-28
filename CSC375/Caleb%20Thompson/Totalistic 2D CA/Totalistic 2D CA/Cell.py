class Cell:
    """description of class"""
    
    state = CellStateSystem()
    neighbors = Neighbors()
    rule
    
    def __init__(self, rule):
        self.rule = rule
    
    def DetermineNextState(self):
        nextState = self.rule.GetNextState(self.state.CurrentState, self.neighbors.CountLiveNeighbors())
        self.state.SetNextState(nextState)
        
    def TransitionToNextState(self):
        self.state.TransistionToNextState()
    
    def GetCurrentState(self):
        return self.state
    def SetCurrentState(self,state):
        self.state.SetNextState(state)
        self.state.TransitionToNextState()
        
    def AddNeighbors(self, neighbors):
        self.neighbors.AddNeighbors(neighbors)
        
    


)