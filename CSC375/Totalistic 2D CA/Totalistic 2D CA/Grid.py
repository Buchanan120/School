import System.Collections.Generic.List

class Grid:
    rowCount = 0
    columnCount = 0
    cells = []
    
    def __init__(self, rowCount, columnCount, rule):
        self.rowCount = rowCount
        self.columnCount = columnCount
        
        self._CreateCells(rule)
        
    def _CreateCells(self, rule):
        for row in xrange(self.rowCount):
            self.cells.append([])
            for column in xrange(self.columnCount):
                self.cells[row].append(Cell(rule))
        for row in xrange(self.rowCount):
            for column in xrange(self.columnCount):
                self._linkCellToNeighbors(row, column)
    
    
    def _linkCellToNeighbors(self, rowIndex, columnIndex):
        neighbors = self._GetNeighborsAround(rowIndex, columnIndex)
        cells[rowIndex][columnIndex].AddNeighbors(neighbors)
        
    def _GetNeighborsAround(self, rowIndex, columnIndex):
        neighbors = List<Cell>()
        
        rowAboveIndex = (self.rowCount + rowIndex - 1) % self.rowCount
        rowBelowIndex = (self.rowCount + rowIndex + 1) % self.rowCount
        columnToLeftOfIndex = (self.columnCount + columnIndex - 1) % self.columnCount
        columnToRightOfIndex = (self.columnCount + columnIndex + 1) % self.columnCount
        
        neighbors.Add(self.cells[rowAboveIndex][columnToLeftOfIndex])
        neighbors.Add(self.cells[rowAboveIndex][columnIndex])
        neighbors.Add(self.cells[rowAboveIndex][columnToRightOfIndex])
        
        neighbors.Add(self.cells[rowIndex][columnToLeftOfIndex])
        neighbors.Add(self.cells[rowIndex][columnToRightOfIndex])
        
        neighbors.Add(self.cells[rowBelowIndex][columnToLeftOfIndex])
        neighbors.Add(self.cells[rowBelowIndex][columnIndex])
        neighbors.Add(self.cells[rowBelowIndex][columnToRightOfIndex])
        
        return neighbors
    
    def GetCellStateAt(self, rowIndex, columnIndex):
        return cells[rowIndex, columnIndex].CurrentState
    def SetCellStateAt(self, rowIndex, columnIndex, newState):
        cells[rowIndex, columnIndex].CurrentState = newState
        
    def UpdateAllCells(self):
        for c in cells:
            c.DetermineNextState()
        for c in cells:
            c.TransitionToNextState()