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
        map<int, int> ans;
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            ans[arr[i]]++;
        }

        for (auto v : ans)
        {
            if (v.second > 1)
            {
                res.push_back(v.first);
            }
        }

        if (res.empty())
        {
            res.push_back(-1);
        }
        return res;
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