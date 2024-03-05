//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n)
    {
        // Your code here
        vector<int> small(n);
        vector<int> large(n);

        small[0] = a[0];
        large[n - 1] = a[n - 1];
        int sm = a[0];
        int la = a[n - 1];

        for (int i = 1; i < n; i++)
        {
            sm = min(sm, a[i]);
            small[i] = sm;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            la = max(la, a[i]);
            large[i] = la;
        }

        int j = 0;
        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            while (j < n && small[i] <= large[j])
            {
                ans = max(ans, j - i);
                j++;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

/* Driver program to test above functions */
int main()
{
    int T;
    // testcases
    cin >> T;
    while (T--)
    {
        int num;
        // size of array
        cin >> num;
        int arr[num];

        // inserting elements
        for (int i = 0; i < num; i++)
            cin >> arr[i];
        Solution ob;

        // calling maxIndexDiff() function
        cout << ob.maxIndexDiff(arr, num) << endl;
    }
    return 0;
}
// } Driver Code Ends