from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """

        pivot = k % len(nums)
        nums[:] = nums[-pivot:] + nums[:-pivot]
