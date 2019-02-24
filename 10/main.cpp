#include <iostream>
#include <vector>
using namespace std;

/*
Problem set:
The sum of the primes below 10 is 2+3+5+7=17.

Find the sum of all the primes not greater than given N.
*/

// Generate primes below N
unsigned long long sieve(long long n, vector<unsigned long long>& primes)
{
  vector<bool> arr(n, 0);
  for(int i = 2; i < n; i++)
    if(!arr[i])
      for(int j = i + i; j < n; j += i)
        arr[j] = 1;
    
  unsigned long long sum = 0;
  for(int i = 2; i < arr.size(); i++)
  {
    if(!arr[i])
      sum += i;
    primes[i] = sum;
  }
  return sum;
}

int main()
{
  // this is the max limit of hackerrank's test inputs
  // precomputing all the sums
  vector<unsigned long long> primes(1000000);
  sieve(1000000, primes);
  int t;
  cout << "Number of test cases: ";
  cin >> t;
  for(int a0 = 0; a0 < t; a0++)
  {
      int n;
      cout << endl << "N: ";
      cin >> n;
      cout << "Sum: " << primes[n] << endl;
  }
  return 0;
}