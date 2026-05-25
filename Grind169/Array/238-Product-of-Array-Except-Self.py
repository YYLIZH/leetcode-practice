from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        result = [0] * len(nums)
        prefix_product = 1
        postfix_product = 1

        for i in range(len(nums)):
            result[i] = prefix_product
            prefix_product *= nums[i]

        for j in range(len(nums) - 1, -1, -1):
            result[j] *= postfix_product
            postfix_product *= nums[j]
        return result
