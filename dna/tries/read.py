from csv import reader, DictReader
from sys import argv, exit
import copy


people = {
    
}


def main():
    if len(argv) != 2:
        print("Missing command-line argument")
        exit(1)
    
    
    with open(argv[1], 'r') as source:
        #Writes the str patterns into an array
        stuff = reader(source)
        row1 = next(stuff)
        strs = []
        for x in range(1,len(row1)):
            strs.append(row1[x])
        
        #Puts the rest of the names into a dictionary of people
        #Keys are the number arrays and values are the names
        temp = []    
        for row in stuff:
            tee = row[0]
            for z in range(1,len(row)):
                temp.append(row[z])   
            key = ', '.join(temp.copy())
            people[key] = tee
            temp.clear()

    print(strs)
    print(people)
    
    if '2, 8, 3' in people:
        print(f"Found {people['2, 8, 3']}")

    




main() 