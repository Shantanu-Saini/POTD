//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> find(int arr[], int n, int x)
    {
        // code here
        // find all occurence of x in arary
        vector<int> indexs;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                indexs.push_back(i);
            }
        }
        int s = indexs.size();
        if (s <= 0)
        {
            return {-1, -1};
        }
        else if(s == 1){
            return {indexs[0], indexs[0]};
        }
        else{
            return {indexs[0], indexs[s - 1]};
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends