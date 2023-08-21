//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    sort(a.begin(), a.end());
    
    long long minDiff = LLONG_MAX;
    
    // Traverse the array with 'end' pointer
    for (int end = m - 1; end < n; ++end) {
        // Calculate the difference between the current end and start
        int start = end - m + 1;
        long long diff = a[end] - a[start];
        minDiff = min(minDiff, diff);
    }
    
    return minDiff;
    
    }   
};


//{ Driver Code Starts.
int main() {
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		vector<long long> a;
		long long x;
		for(long long i=0;i<n;i++)
		{
			cin>>x;
			a.push_back(x);
		}
		
		long long m;
		cin>>m;
		Solution ob;
		cout<<ob.findMinDiff(a,n,m)<<endl;
	}
	return 0;
}
// } Driver Code Ends