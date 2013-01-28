class CA:
    grid
    
    def __init__(self, numberOfRows, numberOfColumns, rule):
        grid = Grid(numberOfRows, NumberOfColumns, rule)
        
    def GetCellStateAt(self, rowIndex, columnIndex):
        return self.grid.GetCellStateAt(rowIndex, columnIndex)
    def SetCellStateAt(self, rowIndex, columnIndex, value):
        self.grid.SetCellStateAt(rowIndex, columnIndex, value)
        
    def UpdateCA(self):
        self.grid.UpdateAllCells()


