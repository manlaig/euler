"""
Work out the first ten digits of the sum of N 50 digit numbers.
"""

t = int(input("Number of inputs to add: "))
sum = 0
for i in range(t):
  num = int(input(str(i+1) + "th number: ").strip())
  sum += num;
print("First 10 digits of sum: " + str(sum)[:10])
