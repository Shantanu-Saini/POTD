//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        vector<int> positives;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                positives.push_back(arr[i]);
            }
        }

        sort(positives.begin(), positives.end());
        positives.erase(unique(positives.begin(), positives.end()), positives.end());
        int size = positives.size();

        int ans = 1; // Start with the smallest positive number

        for (int i = 0; i < size; i++)
        {
            if (positives[i] == ans)
            {
                ans++; // Increment ans if the number is found in the array
            }
            else
            {
                break; // Break the loop if a missing number is found
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {

        // input number n
        int n;
        cin >> n;
        int arr[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        // calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends