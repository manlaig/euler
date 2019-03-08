#include <iostream>
using namespace std;

/*
Problem set:
Find the sum of the digits in the number N!

ex: 4! = 4 * 3 * 2 * 1 = 24
The sum is 2 + 4 = 6
*/

long factorial(int num)
{
    long sum = 1;
    for(int i = 2; i <= num; i++)
        sum *= i;
    return sum;
}

int main()
{
    int t;
    cout << "Number of test cases: ";
    cin >> t;

    for(int test_case = 0; test_case < t; test_case++)
    {
        int n, sum = 0;
        cout << "\nN: ";
        cin >> n;
        long fact = factorial(n);
        cout << "F: " << fact << endl;
        while(fact > 0)
        {
            sum += fact % 10;
            fact /= 10;
        }
        cout << sum << endl;
    }
}