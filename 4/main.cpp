#include <iostream>
#include <list>
using namespace std;

/*
Problem set:

A palindromic number reads the same both ways. The smallest 6 digit palindrome made from the product of two 3-digit numbers is 101101 = 143 * 707. 

Find the largest palindrome made from the product of two 3-digit numbers which is less than N.
*/

bool isPalindrome(int num)
{
  list<int> lst;
  while(num > 0)
  {
    lst.push_back(num % 10);
    num /= 10;
  }
  while(!lst.empty())
  {
    if(lst.front() != lst.back())
      return false;
    lst.pop_front();
    if(!lst.empty())
      lst.pop_back();
  }
  return true;
}

bool factorable(int num)
{
  for(int i = 100; i <= 999; ++i)
    for(int j = 100; j <= 999; ++j)
      if(i * j == num)
        return true;
  return false;
}

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
      for(int i = n; i > 0; i--)
        if(isPalindrome(i) && factorable(i))
        {
          cout << i << endl;
          break;
        }
  }
  return 0;
}
