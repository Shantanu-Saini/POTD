//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    bool equalPartition(int N, int arr[])
    {
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }

        // If the sum is odd, equal partition is not possible
        if (sum % 2 != 0)
        {
            return false;
        }

        sum /= 2; // We want to find a subset with sum 'sum'

        // Create a 2D DP table to store whether it's possible to achieve each sum using elements
        vector<vector<bool>> dp(N + 1, vector<bool>(sum + 1, false));

        // Initialization: It's always possible to achieve a sum of 0 with an empty subset
        for (int i = 0; i <= N; i++)
        {
            dp[i][0] = true;
        }

        // Dynamic programming to fill the DP table
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                // If the current element is greater than the current sum 'j', exclude it
                if (arr[i - 1] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    // Include the current element or exclude it
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        return dp[N][sum];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends