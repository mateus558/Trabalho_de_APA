from random import randint #library to generate random numbers
def randomName():
    names = ['Rafael', 'Mateus', 'Aleksander', 'Mattheus', 'Gabriel', 'Carlos', 'Maria', 'Laura', 'Paula', 'Roberta', 'Adriel', 'Edmar', 'Marcela', 'Robson']
    lastNames = ['Souza', 'Santos', 'Oliveira', 'Silva', 'Ribeiro', 'Amaral', 'Lima', 'Carvalho', 'Ferreira', 'Costa', 'Gomes', 'Ribeiro', 'Teixeira', 'Rocha']
    index = randint(0, (len(names)-1))
    return (names[index]+ ' ' + lastNames[index])

def generateList(n):
    fullName = []
    listIndex = []
    for i in range (0, n):
        fullName.append(randomName())
        listIndex.append(i)
    #list in random order
    for i in range (0,n):
        randIndex = randint(0,len(listIndex)-1)
        ListRO.write(str(listIndex[randIndex]) + '\n')
        ListRO.write(fullName[listIndex[randIndex]] + '\n')
        listIndex.pop(randIndex)
    #list in ascending order
    for i in range(0, n):
        ListAOrd.write(str(i) + '\n')
        ListAOrd.write(fullName[i] + '\n')
    #list in descending order
    for i in range(n-1, -1, -1):
        ListDOrd.write(str(i) + '\n')
        ListDOrd.write(fullName[i] + '\n')
    #almost ordered list
    ListAmOrd.write(str(n-1) + '\n')
    ListAmOrd.write(fullName[n-1] + '\n')
    for i in range(1, n-1):
        ListAmOrd.write(str(i) + '\n')
        ListAmOrd.write(fullName[i] + '\n')
    ListAmOrd.write(str(0) + '\n')
    ListAmOrd.write(fullName[0] + '\n')


#main
n = input("What is the size of the list?\n")
ListRO = open('ListRO{}.txt'.format(n), 'w') #list in random order
ListAOrd = open('ListAOrd{}.txt'.format(n), 'w') #list in ascending order
ListDOrd = open('ListDOrd{}.txt'.format(n), 'w') #List in descending order
ListAmOrd = open('ListAmOrd{}.txt'.format(n), 'w') #almost ordered list
generateList(n)
ListRO.close()
ListAOrd.close()
ListDOrd.close()
ListAmOrd.close()
