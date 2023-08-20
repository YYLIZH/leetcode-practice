#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;
        int middle;

        while (low <= high)
        {
            middle = low + (high - low) / 2;

            if (nums[middle] == target)
            {
                return middle;
            }
            else if (nums[middle] > target)
            {
                high = middle - 1;
            }
            else
            {
                low = middle + 1;
            }
        }
        return -1;
    }
};