from typing import List

# Use two pointer, sliding window


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) < 2:
            return 0  # No transaction

        max_price = 0
        slow_pointer = 0
        fast_pointer = 1

        while fast_pointer < len(prices):
            curr_profit = prices[fast_pointer] - prices[slow_pointer]

            if prices[fast_pointer] > prices[slow_pointer]:
                max_price = max(max_price, curr_profit)

            else:  # slow pointer incr. Try to find a lower price
                slow_pointer = fast_pointer

            fast_pointer += 1

        return max_price
