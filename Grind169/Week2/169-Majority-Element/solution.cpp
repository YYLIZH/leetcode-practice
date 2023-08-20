#include <vector>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cnt = 1;
        int res = nums[0];
        int major = nums.size() / 2;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == res)
            {
                cnt += 1;
            }
            else
            {
                cnt -= 1;
            }

            if (cnt == 0)
            {
                res = nums[i];
                cnt = 1;
            }

            if (cnt > major)
            {
                return res;
            }
        }

        return res;
    }
};