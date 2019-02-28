#include <iostream>
#include <stack>
using namespace std;

/*
Given a number, write it in words.
The highest number possible in a test case is 1 000 000 000 000
This algorithm can be easily extended to support larger numbers
*/

string digits[] = {"", "One", "Two", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen",
    "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string doubleDigits[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty",
    "Seventy", "Eighty", "Ninety"};
string threeDigits[] = {"", "Thousand", "Million", "Billion", "Trillion"};

int main()
{
    int testcase_count;
    stack<string> to_words;

    cout << "Number of test cases: ";
    cin >> testcase_count;

    for(int i = 0; i < testcase_count; i++)
    {
        long n;

        // to count for thousand, million, billion, etc
        int iteration = 0;

        cout << endl << "N: ";
        cin >> n;

        if(!n)
        {
            cout << "Zero" << endl;
            continue;
        }

        for(; n > 0; n /= 1000, iteration++)
        {
            // looping through the number by hundreds
            int curr = n % 1000;

            /*
            correctly wording 'curr' and storing it in a string
            then adding that string to the stack,
            the ordering is correct this way
            */
            string q = "";

            /*
            outputs thousand, million, etc.
            obviously, we don't want to output it on 0
            */
            if(iteration > 0 && curr != 0)
                to_words.push(threeDigits[iteration] + " ");

            if(curr >= 100)
            {
                q += digits[curr / 100] + " Hundred ";
                curr = curr % 100;
            }

            if(curr >= 10 && curr < 20)
            {
                q += digits[curr] + " ";
                curr = curr % 10;
            } else
            {
                if(curr >= 20)
                {
                    q += doubleDigits[curr / 10 - 2] + " ";
                    curr = curr % 10;
                }
                if(curr > 0)
                    q += digits[curr] + " ";
            }

            to_words.push(q);
        }

        while(!to_words.empty())
        {
            cout << to_words.top();
            to_words.pop();
        }
        cout << endl;
    }

    return 0;
}
