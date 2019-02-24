#include <iostream>
using namespace std;

/*
Problem set:

2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible (divisible with no remainder) by all of the numbers from 1 to N?
*/

int main()
{
  int t;
  cout << "Number of test cases: ";
  cin >> t;
  for(int tcase = 0; tcase < t; tcase++)
  {
    int n;
    cout << endl << "N: ";
    cin >> n;
    for(int i = n; ; i++)
    {
        bool t = true;
        for(int j = 1; j <= n; j++)
            if(i % j)   t = false;
        if(t)
        {
            cout << "Answer: " << i << endl;
            break;
        }
    }
  }
  return 0;
}