from random import randint #library to generate random numbers
def randomName():
    names = ['Rafael', 'Mateus', 'Aleksander', 'Mattheus', 'Gabriel', 'Carlos', 'Maria', 'Laura', 'Paula', 'Roberta', 'Adriel', 'Edmar', 'Marcela', 'Robson']
    lastNames = ['Souza', 'Santos', 'Oliveira', 'Silva', 'Ribeiro', 'Amaral', 'Lima', 'Carvalho', 'Ferreira', 'Costa', 'Gomes', 'Ribeiro', 'Teixeira', 'Rocha']
    index = randint(0, (len(names)-1))
    return (names[index]+ ' ' + lastNames[index])

def generateList(n):
    fullName = []
    for i in range (0, n):
        fullName.append(randomName())
    #list without repeated elements
    for i in range (0,n-1,2):
        ListNoR.write(str(i) + '\n')
        ListNoR.write(fullName[i] + '\n')
    for i in range(n-1, 0, -2):
        ListNoR.write(str(i) + '\n')
        ListNoR.write(fullName[i] + '\n')
    #list in ascending order
    for i in range(0, n):
        ListAOrd.write(str(i) + '\n')
        ListAOrd.write(fullName[i] + '\n')
    #list in descending order
    for i in range(n-1, -1, -1):
        ListDOrd.write(str(i) + '\n')
        ListDOrd.write(fullName[i] + '\n')

#main
ListNoR = open('ListNoR.txt', 'w') #list without repeated elements
ListAOrd = open('ListAOrd.txt', 'w') #list in ascending order
ListDOrd = open('ListDOrd.txt', 'w')#List in descending order
n = input("What is the size of the list?\n")
generateList(n)
ListNoR.close()
ListAOrd.close()
ListDOrd.close()
