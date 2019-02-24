#include <iostream>
using namespace std;

/*
Find the greatest product of K consecutive digits in the N digit number.
*/
int main()
{
    int t;
    cout << "Number of test cases: ";
    cin >> t;
    for(int a0 = 0; a0 < t; a0++)
    {
        int n;
        int k;
        cout << "K: ";
        cin >> k;
        string num;
        cout << "Number: ";
        cin >> num;

        n = num.size();
        long sum = 1;
        long largest = 0;
        for(int i = 0; i <= n-k; i++)
        {
          for(int j = i; j < i+k; j++)
          {
            if(num[j] == '0')
            {
                sum = 0;
                break;
            }
            sum *= (int)num[j] - 48;
          }
          if(sum > largest)
            largest = sum;
          sum = 1;
        }
        cout << "Largest: " << largest << endl;
    }
    return 0;
}
