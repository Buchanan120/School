import csv
def ParseFile(f):
    reader = csv.reader(open(f, 'r'), dialect='excel')
    return list(reader)

def GetListSortedByTotalLifetimeGross(itemList):
    itemList.sort(key = lambda item:item[3])
    for item in itemList:
        print(item)
        
def GetHighestGrossingFilmForStudios(itemList):
    itemList.sort(key = lambda item:item[3])
    itemList.sort(key = lambda item:item[2])
    currentStudio = ""
    for item in itemList:
        if item[2] != currentStudio:
            currentStudio = item[2]
            print([item[2], item[1], item[3], item[6]])
            
GetListSortedByTotalLifetimeGross(ParseFile('BoxOffice.csv'))
GetHighestGrossingFilmForStudios(ParseFile('BoxOffice.csv'))


