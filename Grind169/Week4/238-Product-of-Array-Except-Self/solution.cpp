#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> ans(n);
        // Marking the left product of each number. For example, leftProduct[5] is the left prduct of nums[5]
        vector<int> leftProduct(n);
        // Marking the right product of each number. For example, rightProduct[5] is the right product of nums[5]
        vector<int> rightProduct(n);

        leftProduct[0] = 1; // For nums[0], it's left product should be always 1
        for (int i = 1; i < n; i++)
        {
            leftProduct[i] = leftProduct[i - 1] * nums[i - 1];
        }

        rightProduct[n - 1] = 1; // For nums[n-1], it's right product should be always 1
        for (int i = n - 2; i >= 0; i--)
        {
            rightProduct[i] = rightProduct[i + 1] * nums[i + 1];
        }

        for (int i = 0; i < n; i++)
        {
            ans[i] = leftProduct[i] * rightProduct[i];
        }

        return ans;
    }
};