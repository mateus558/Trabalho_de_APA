from random import randint #library to generate random numbers
def randomName():
    names = ['Rafael', 'Mateus', 'Aleksander', 'Mattheus', 'Gabriel', 'Carlos', 'Maria', 'Laura', 'Paula', 'Roberta']
    index = randint(0, (len(names)-1))
    return names[index]

def generateData(n):
    for i in range (0,n+1,2):
        file.write(str(i) + '\n')
        file.write(randomName() + '\n')
    for j in range(n-1, 0, -2):
        file.write(str(j) + '\n')
        file.write(randomName() + '\n')

#main
file = open('List.txt', 'w')
n = input("What is the size of the list?\n")
generateData(n)
file.close()
