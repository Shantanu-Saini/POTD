//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int MOD = 1000000007;

    unsigned long mod_pow(unsigned long base, unsigned long exp) {
        unsigned long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    unsigned long fact(unsigned long n) {
        if (n == 0) {
            return 1;
        }
        return (n * fact(n - 1)) % MOD;
    }

    int findCatalan(int n) {
        unsigned long t = n + 1;
        unsigned long s = 2 * n;
        
        unsigned long num = fact(s);
        unsigned long den = (fact(t) * fact(n)) % MOD;
        
        unsigned long den_inverse = mod_pow(den, MOD - 2);
        unsigned long ans = (num * den_inverse) % MOD;

        return static_cast<int>(ans);
    }

};

//{ Driver Code Starts.
int main() 
{
	int t;
	cin>>t;
	while(t--) {
	    
	    int n;
	    cin>>n;
	    Solution obj;
	    cout<< obj.findCatalan(n) <<"\n";    
	}
	return 0;
}
// } Driver Code Ends