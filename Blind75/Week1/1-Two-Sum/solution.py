from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        checking_dict = {}
        for i in range(len(nums)):
            curr = nums[i]
            if checking_dict.get(target - curr) is None:
                checking_dict[curr] = i
            else:
                return [i, checking_dict[target - curr]]
