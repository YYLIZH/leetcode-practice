from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        major = nums[0]
        cnt = 1

        # Boyer-Moore algorithm
        # Remove arbitrary 2 numbers will not affect the majority
        for num in nums[1:]:
            if major == num:
                cnt += 1
            elif cnt > 0:
                cnt -= 1
            else:  # cnt=0
                major = num
                cnt += 1

        return major
