""" Problem Set:
2^9 = 512 and the sum of its digits is 5+1+2=8.

What is the sum of the digits of the number  2^N?
"""

numOfTestCases = int(input("Enter number of test cases: "))

# ask for input for each test case
for i in range(numOfTestCases):
  userIn = int(input("\nInput number: "))
  
  # the ** operates on integer numbers only
  # we want to get a large integer number
  num = 2 ** userIn

  sum = 0
  # getting access to each individual digit of 'num'
  while num > 0:
    sum += int(num % 10)

    num = num // 10
    """
/ division operator doesn't work for large integers

/ operator tries to return a float, which results in an OverflowError if the return is larger than float supports

so, we use the // operator to get an integer back from division
    """
  
  print("Answer: " + str(sum))

  sum = 0
