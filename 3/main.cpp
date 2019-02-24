#include <iostream>
#include <list>
#include <cmath>
#include <iterator>
using namespace std;

/*
Problem set:

The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of a given number N?
*/

bool isPrime(unsigned long long num)
{
  for(int k = 2; k <= (int)sqrt(num); k++)
    if(num % k == 0)
      return false;
  return true;
}

void findPrimes(list<unsigned long long>& lst)
{
  int bound = (int)1e6;
  for(unsigned long long i = 3; i < bound; i++)
  {
    if(isPrime(i))
    {
      lst.push_back(i);
    }
  }
}

int largestFactor(unsigned long long n, list<unsigned long long> lst)
{
  int largest = 2;
  for(list<unsigned long long>::iterator it = lst.begin(); it != lst.end(); it++)
  {
    if(*it > n)
      break;
    else if(n % *it == 0)
      largest = *it;
  }
  return largest;
}

int main()
{
  list<unsigned long long> lst;
  findPrimes(lst);

  int t;
  unsigned long long n;
  cout << "Number of test cases: ";
  cin >> t;
  for(int tcase = 0; tcase < t; tcase++)
  {
      cout << endl << "N: ";
      cin >> n;
      cout << "Largest prime factor: " << largestFactor(n, lst) << endl;
  }

  return 0;
}