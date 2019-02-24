#include <iostream>
using namespace std;

/*
The sum of the squares of the first 3 natural numbers is, 1^2 + 2^2 + 3^2 = 14.

The square of the sum of the first 3 natural numbers is, (1 + 2 + 3)^2 = 36.

Hence the absolute difference between the sum of the squares of the first 3 natural numbers and the square of the sum is 36 - 14 = 22.

Find the absolute difference between the sum of the squares of the first N natural numbers and the square of the sum.
*/

int main()
{
  int t;
  cout << "Number of test cases: ";
  cin >> t;
  for(int a0 = 0; a0 < t; a0++)
  {
      int n;
      cout << endl << "N: ";
      cin >> n;
      
      long a = n * (n+1) / 2;
      a = a * a;
      
      long sum = 0;
      for(int i = 1; i <= n; i++)
          sum += i * i;
      cout << "Answer: " << a - sum << endl;
  }
  return 0;
}