#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> ans;
        map<int, int> mp;

        for (int i : nums)
        {
            mp[i]++;
        }

        for (auto h : mp)
        {
            if (h.second >= 2)
            {
                ans.push_back(h.first);
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    cout << "Original array: ";
    for (int num : nums)
    {
        cout << num << " ";
    }
    cout << endl;

    vector<int> duplicates = sol.findDuplicates(nums);

    cout << "Duplicate elements: ";
    for (int num : duplicates)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
