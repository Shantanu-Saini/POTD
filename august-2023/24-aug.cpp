//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2)
    {
        // Your code here
         int operand1 = 0, operand2 = 0, digit = 0, sign1 = 1, sign2 = 1;

        // Character to integer mapping
        int charToInt[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

        for (char c : s1) {
            if (c == '-') {
                sign1 = -1;
                continue;
            }
            digit = charToInt[c - '0'];
            operand1 = operand1 * 10 + digit;
        }

        for (char c : s2) {
            if (c == '-') {
                sign2 = -1;
                continue;
            }
            digit = charToInt[c - '0'];
            operand2 = operand2 * 10 + digit;
        }

        int result = operand1 * operand2 * (sign1 * sign2);
        string resultStr = to_string(result);
        return resultStr;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a;
        string b;
        cin >> a >> b;
        Solution obj;
        cout << obj.multiplyStrings(a, b) << endl;
    }
}
// } Driver Code Ends