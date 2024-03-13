#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotInteger(int n)
    {
        int totalSum = (n * (n + 1)) / 2;

        int currentSum = 0;

        for (int i = 1; i <= n; i++)
        {
            currentSum += i;
            if (currentSum * 2 == totalSum + i)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    Solution sol;

    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    int pivot = sol.pivotInteger(n);
    if (pivot != -1)
    {
        cout << "The pivot integer is: " << pivot << endl;
    }
    else
    {
        cout << "There is no pivot integer for the given value of n." << endl;
    }

    return 0;
}
