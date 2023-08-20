from typing import List


# Kadane's Algorithm
# https://shubo.io/maximum-subarray-problem-kadane-algorithm/
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        for i in range(1, len(nums)):
            if nums[i - 1] > 0:
                nums[i] += nums[i - 1]
        return max(nums)
