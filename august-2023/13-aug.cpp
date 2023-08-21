//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int MOD = 1000000007;
    int nthFibonacci(int n){
        // code here
        int prev1 = 1;
        int prev2 = 0;
        for(int i=2; i<n+1; i++){
            int curr = prev1 % MOD + prev2 % MOD;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1 % MOD;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends