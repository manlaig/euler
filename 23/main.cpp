#include <iostream>
#include <map>
using namespace std;

#define MAX_LIMIT_TO_CHECK 28123
#define MIN_LIMIT_TO_CHECK 12

/*
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
A number N is called deficient if the sum of its proper divisors is less than N and it is called abundant if this sum exceeds N.
As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two abundant numbers is 24.
By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.
Given , print YES if it can be expressed as sum of two abundant numbers, else print NO.
*/

int getProperDivisorSum(int input)
{
    if(input <= 0)  return 0;
    int sum = 0;
    for(int i = 1; i < input; i++)
        if(input % i == 0)
            sum += i;
    return sum;
}

void isSumOf2AbundantNum(int num, map<int, bool> abundantNums)
{
    /*numbers above this macro is guaranteed to be represented as sum of 2 abundant numbers*/
    if(num >= MAX_LIMIT_TO_CHECK)
    {
        cout << "YES\n";
        return;
    }
    
    /*numbers below this macro cannot be represented as sum of 2 abundant numbers*/
    if(num >= MIN_LIMIT_TO_CHECK)
    {
        for(auto it = abundantNums.begin(); it != abundantNums.end(); it++)
        {
            if(abundantNums.find(num - it->first) != abundantNums.end())
            {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main()
{
    map<int, bool> abundantNums;
    for(int i = MIN_LIMIT_TO_CHECK; i < MAX_LIMIT_TO_CHECK; i++)
        if(getProperDivisorSum(i) > i)
            abundantNums[i] = true;

    cout << "Number of test cases: ";
    int test_cases;
    cin >> test_cases;

    int input;
    for(int i = 0; i < test_cases; i++)
    {
        cout << "N: ";
        cin >> input;
        isSumOf2AbundantNum(input, abundantNums);
    }
}