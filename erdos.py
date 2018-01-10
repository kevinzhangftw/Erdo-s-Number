
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

def updateDB(list):
	for scientist in list:
		if scientist == 'Erdos, P.':
			continue
		else:
			db.update({scientist:1})


def areErdosNeighbors(list):
	for scientist in list:
		if scientist == 'Erdos, P.':
			return True
	return False

# def areErdosGreatNeighbors(list):


def nomatch():
	return 'infinity'

def buildDB(line):
	lst = buildList(line)
	if areErdosNeighbors(lst):
		updateDB(lst)
	# elif areErdosGreatNeighbors(list):
	# 	updateDB(list)
	else:
		nomatch()
	

scenario = input()
pandn = input().split(' ')
p= int(pandn[0])
n= int(pandn[1])
# print("p", p)
# print("n", n)
db = {'Erdos, P.': 0}

for line in range(p):
	line = input()
	# print(line)
	buildDB(line)

print(db)

# for line in range(n):
# 	findMatch(line)

	

print("Scenario", scenario)
