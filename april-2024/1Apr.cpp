#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = s.length();
        int cnt = 0;

        // removing ending spaces
        bool isChar = false;
        while (!isChar)
        {
            if (s[len - 1] == ' ')
                len--;
            else
                isChar = true;
        }

        for (int i = len - 1; i >= 0; i--)
        {
            if (s[i] == ' ')
                break;
            cnt++;
        }

        return cnt;
    }
};

int main()
{
    Solution sol;

    // Input string
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    // Length of last word
    cout << "Length of last word in \"" << input << "\": " << sol.lengthOfLastWord(input) << endl;

    return 0;
}
