#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;

        for (int i = 1; i < nums.size(); i++)
        {
            int curr = nums[i];
            if (mp.find(target - curr) == mp.end())
            {
                mp[curr] = i;
            }
            else
            {
                return {mp[target - curr], i};
            }
        }
    }
};