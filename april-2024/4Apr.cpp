#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    // Function to calculate the nesting depth of a VPS represented by string s
    int maxDepth(string s)
    {
        int maxDepth = 0; // Variable to store the maximum nesting depth encountered
        int len = 0;      // Variable to keep track of current nesting depth

        // Iterate through each character in the string
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {          // If the character is an opening parenthesis
                len++; // Increment the nesting depth
            }
            else if (s[i] == ')')
            {          // If the character is a closing parenthesis
                len--; // Decrement the nesting depth
            }
            // Update the maximum nesting depth encountered so far
            maxDepth = max(maxDepth, len);
        }

        return maxDepth; // Return the maximum nesting depth
    }
};

int main()
{
    Solution solution; // Create an instance of the Solution class

    // Test cases
    string s1 = "(1+(2*3)+((8)/4))+1";
    string s2 = "(1)+((2))+(((3)))";

    // Calculate and output the nesting depth for each test case
    cout << "Nesting depth of \"" << s1 << "\" : " << solution.maxDepth(s1) << endl;
    cout << "Nesting depth of \"" << s2 << "\" : " << solution.maxDepth(s2) << endl;

    return 0;
}
