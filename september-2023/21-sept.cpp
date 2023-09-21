//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if (n <= 0)
            return 0;

        int dp[n];
        dp[0] = arr[0]; // Maximum money if we loot the first house

        // For the second house, we take the maximum of the first and second house money
        dp[1] = max(arr[0], arr[1]);

        // For each subsequent house, we have two options:
        // 1. Don't loot this house (in which case, the maximum money is the same as the previous house).
        // 2. Loot this house (in which case, we add the money from this house and the maximum money from two houses back).
        for (int i = 2; i < n; i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
        }

        // The final answer is in dp[n-1]
        return dp[n - 1];
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends