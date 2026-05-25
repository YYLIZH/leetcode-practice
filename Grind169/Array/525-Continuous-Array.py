from typing import List


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        max_len = 0
        curr_val = 0
        # hash map stores
        # {current_value: the first index it appear}
        mp = {0: -1}

        for i, num in enumerate(nums):
            if num == 1:
                curr_val += 1
            else:
                curr_val -= 1

            if curr_val in mp:
                max_len = max(max_len, i - mp[curr_val])
            else:
                mp[curr_val] = i
        return max_len
