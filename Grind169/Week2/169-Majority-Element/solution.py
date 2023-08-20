from typing import List


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # Use Moore's Voting Algorithm
        # https://ithelp.ithome.com.tw/articles/10213285
        cnt = 1
        res = nums[0]

        for n in nums[1:]:
            if n == res:
                cnt += 1
            else:
                cnt -= 1

            if cnt == 0:
                res = n
                cnt = 1

        return res
