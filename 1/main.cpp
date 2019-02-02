#include <iostream>

/* O(1) algorithm */
unsigned long long findMultFormula(int n)
{
  if(n < 1)
    return 0;

  unsigned long long n3, n5, n15;
  n3 = 3 * std::max((n-1)/3 * ((n-1)/3+1) / 2, 0);
  n5 = 5 * std::max((n-1)/5 * ((n-1)/5+1) / 2, 0);
  n15 = 15 * std::max((n-1)/15 * ((n-1)/15+1) / 2, 0);

  return n3 + n5 - n15;
}

/* 
  O(n) algorithm 
  used to check the correctness of the O(1) algorithm
*/
unsigned long long findMultAlgorithm(int n)
{
    unsigned long long sum = 0, i = 3, j = 5;
    
    while(i < n && j < n)
    {
        sum += i;
        if(j % 3 != 0 || j % 5 != 0)
            sum += j;
        i += 3;
        j += 5;
    }
    while(i < n)
    {
        sum += i;
        i += 3;
    }
    while(j < n)
    {
        sum += j;
        j += 5;
    }
    return sum;
}

int main()
{    
    int t, n;
    std::cout << "Number of test cases:";
    std::cin >> t;
    for(int i = 0; i < t; i++)
    {
        std::cout << "test " << i+1 << ": ";
        std::cin >> n;

        std::cout << findMultFormula(n) << std::endl;
    }
    return 0;
}
