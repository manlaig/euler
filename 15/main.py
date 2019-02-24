from math import factorial

"""
Starting in the top-left corner of a M x N grid, and only being able to move to the right and down, how many routes are there to the bottom-right corner?

We can come up with a O(1) solution if we use combinatorics
"""

# m choose n (mCn)
def choose(n, m):
  return factorial(n) // (factorial(m)*factorial(n-m))

t = int(input("Number of test cases: "))

for i in range(t):
  s = input("\nEnter format n m: ")
  lst = s.split(" ")
  n = int(lst[0])
  m = int(lst[1])

  a = int(choose(n+m, n))

  print("Paths: " + str(a))
