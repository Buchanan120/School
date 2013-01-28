class CellState:
    ALIVE = CellState()
    DEAD = CellState()
    
    def __unicode__(self):
        if self == ALIVE: return "ALIVE"
        if self == DEAD: return "DEAD"
        

