#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
Problem set: What is the Nth prime number?
*/

// fill 'primes' array with primes up to 'n'
void sieve(long n, vector<int>& primes)
{
  vector<bool> arr(n, true);
  for (long p=2; p <= sqrt(n); p++) 
    if (arr[p]) 
      // checking off all multiples of p, but not p 
      // if p hasn't been checked off, then it's a prime
      for (long i = p + p; i <= n; i += p) 
        arr[i] = false; 

  int index = 0;
  for (long p=2; p <= n; p++) 
    if (arr[p]) 
      primes[index++] = p;
} 

int main()
{
  /* this has been coded just to pass hackerrank's project euler #7, i used their maximum limit of N, which was 10^4*/
  // i hope i can find better solutions later on
  int max = 10000, n;
  vector<int> primes(max);
  sieve(100000, primes);
  cout << "N: ";
  cin >> n;
  cout << "Nth prime number: " << primes[n-1] << endl;
}
