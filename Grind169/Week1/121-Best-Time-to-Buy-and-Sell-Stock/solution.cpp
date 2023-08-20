#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_price = 0;

        int left=0;
        int right=1;

        while (right<prices.size()){
            int curr_profit=prices[right]-prices[left];

            if (prices[left]<prices[right]){
                max_price=max(max_price,curr_profit);
            } else {
                left=right;
            }

            right++;
        }

        return max_price;

    }
};