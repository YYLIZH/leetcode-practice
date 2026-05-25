from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapping = {}

        for idx, item in enumerate(nums):
            complement = target - item
            if complement in mapping:
                return [mapping[complement], idx]
            mapping[item] = idx

        return []
