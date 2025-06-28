#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        sort(coins.begin(), coins.end());

        for (int a = 0; a <= amount; a++)
        {
            for (auto c : coins)
            {
                if (a - c >= 0)
                {
                    dp[a] = min(dp[a], 1 + dp[a - c]);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};