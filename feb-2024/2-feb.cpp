//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string s)
    {
        // Your code here
        int n = s.length();
        int num = 0;
        int sign = 1;
        int i = 0;
        if (s[0] == '-')
        {
            sign = -1;
            i = 1;
        }

        for (; i < n; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num *= 10;
                int dig = s[i] - '0';
                num += dig;
            }
            else
            {
                return -1;
            }
        }

        return num * sign;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}
// } Driver Code Ends