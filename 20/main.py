"""
Problem set:
Find the sum of the digits in the number N!

ex: 4! = 4 * 3 * 2 * 1 = 24
The sum is 2 + 4 = 6
"""

def factorial(num):
    sum = 1;
    for i in range(2, num+1, 1):
        sum *= i;
    return sum;

t = int(input("Number of test cases: "))

for test_case in range(t):
  n = int(input("\nN: "))
  sum = 0;

  fact = factorial(n);
  while(fact > 0):
    sum += fact % 10;
    fact = fact // 10;
  print(sum)