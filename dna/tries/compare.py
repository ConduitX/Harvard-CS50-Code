from csv import reader, DictReader
from sys import argv, exit
import copy


people = {

}


def main():
    if len(argv) != 3:
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


    with open(argv[2], 'r') as txt:
        s = txt.read()
        nums = []
        p = 0
        #Make an array for the numbers after checking them
        for f in strs:
            n = check(strs[p], s)
            nums.append(n)
            n = 0
            p += 1
    
    end = ", ".join(map(str, nums))  #Make int array a str array
    
    if end in people:
        print(f"{people[end]}")
    else:
        print("No match")
        

#Check txt file for chains of strs
def check(st, text):
    #check for the longest str length
    #return value of longest length
    x = 0
    l = len(st)
    longest = 0
    current = 0
    while x+l < len(text):
        #if you find a match, add to the current chain
        if text[x:l+x] == st:
            current += 1
            x += l-1
        else:
            #Replace the longest if the current
            if current > longest:
                longest = current
                current = 0
            #Reset the current count
            else:
                current = 0
        x += 1
    
    return longest


main()