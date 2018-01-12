import copy

def splitOnEverySecondComma(rawNamesList):
	n = 2
	groups = rawNamesList.split(',')
	nameList = []
	while len(groups):
		nameList.append(','.join(groups[:n]))
		groups = groups[n:]
	return nameList

def buildList(line):
	rawList = line.split(':')
	# print(rawList)
	nameList = splitOnEverySecondComma(rawList[0])
	# print(nameList)
	return nameList

# def updateDB(list):

def buildGraph(lst):
	for scientist in lst:
		# print(scientist)
		lstCopy = copy.deepcopy(lst)
		lstCopy.remove(scientist)
		adjacencyList[scientist] = lstCopy  

def nomatch():
	return 'infinity'

def buildDB(line):
	lst = buildList(line)
	buildGraph(lst)
	

scenario = input()
pandn = input().split(' ')
p= int(pandn[0])
n= int(pandn[1])
# print("p", p)
# print("n", n)
db = {'Erdos, P.': 0}
adjacencyList = {}

for line in range(p):
	line = input()
	# print(line)
	buildDB(line)

print('db: ', db)
print('adjacencyList: ', adjacencyList)

# for line in range(n):
# 	findMatch(line)

	

print("Scenario", scenario)
