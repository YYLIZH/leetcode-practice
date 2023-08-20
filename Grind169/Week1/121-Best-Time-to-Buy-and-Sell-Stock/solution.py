from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # use two pointer
        max_price = 0

        left = 0
        right = 1

        while right < len(prices):
            curr_profit = prices[right] - prices[left]

            if prices[right] > prices[left]:
                max_price = max(max_price, curr_profit)
            else:
                left = right

            right += 1

        return max_price
