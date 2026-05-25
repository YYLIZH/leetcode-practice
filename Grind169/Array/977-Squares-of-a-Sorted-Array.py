from typing import List


class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        aux = [0] * len(nums)
        left_pointer = 0
        right_pointer = len(nums) - 1

        for i in range(len(nums) - 1, -1, -1):
            if (abs(nums[left_pointer])) > abs(nums[right_pointer]):
                aux[i] = nums[left_pointer] ** 2
                left_pointer += 1
            else:
                aux[i] = nums[right_pointer] ** 2
                right_pointer -= 1

        return aux
