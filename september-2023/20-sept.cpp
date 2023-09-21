//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> rotate(int N, int D)
    {
        // code here.
        vector<int> results;

        // Ensure D is within the range [0, 16)
        D = D % 16;

        // Perform left rotation
        int leftRotatedN = ((N << D) | (N >> (16 - D))) & 0xFFFF;
        results.push_back(leftRotatedN);

        // Perform right rotation
        int rightRotatedN = ((N >> D) | (N << (16 - D))) & 0xFFFF;
        results.push_back(rightRotatedN);

        return results;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, d;
        cin >> n >> d;
        Solution ob;
        vector<int> res = ob.rotate(n, d);
        cout << res[0] << endl
             << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends