//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> duplicates(int arr[], int n)
    {
        // code here
        // map<int, int> ans;
        // vector<int> res;
        // for (int i = 0; i < n; i++)
        // {
        //     ans[arr[i]]++;
        // }

        // for (auto v : ans)
        // {
        //     if (v.second > 1)
        //     {
        //         res.push_back(v.first);
        //     }
        // }

        // if (res.empty())
        // {
        //     res.push_back(-1);
        // }
        // return res;
        int max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }

        // Initialize hash array with zeros
        int hash[max + 1] = {0}; // We add 1 to accommodate values from 0 to max

        for (int i = 0; i < n; i++)
        {
            hash[arr[i]]++;
        }

        vector<int> ans;

        for (int i = 0; i <= max; i++)
        { // Iterate from 0 to max
            if (hash[i] > 1)
            {
                ans.push_back(i);
            }
        }

        if (ans.empty())
        {
            ans.push_back(-1);
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends