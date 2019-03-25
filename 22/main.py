"""
You are given around five-thousand first names,
begin by sorting it into alphabetical order.
Then, working out the alphabetical value for each name,
multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list in sample is sorted into alphabetical order,
PAMELA, which is worth 16+1+13+5+12+1=48, is the 5th name in the list.
So, PAMELA would obtain a score of 5 * 48 = 240.

You are given  queries, each query is a name, you have to print the score.
"""

lst = []
t = int(input("Number of names: "))

for i in range(t):
    lst.append(input("Name " + str(i+1) + ": "))
    
lst.sort()

queries = int(input("Number of queries: "))

for query in range(queries):
    name = input("Name to score: ")
    for i in range(len(lst)):
        if(lst[i] == name):
            #score the name
            score = 0
            for letter in range(len(name)):
                score += ord(name[letter]) - ord('A') + 1
            print("Score: " + str(score * (i+1)))
            break