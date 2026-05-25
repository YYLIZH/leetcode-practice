from typing import List


class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        close = nums[0] + nums[1] + nums[2]

        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            min_sum = nums[i] + nums[i + 1] + nums[i + 2]
            if min_sum > target:
                if abs(target - close) > abs(target - min_sum):
                    close = min_sum
                if min_sum > target and i > 0:
                    break

            max_sum = nums[i] + nums[len(nums) - 1] + nums[len(nums) - 2]
            if max_sum < target:
                if abs(target - close) > abs(target - max_sum):
                    close = max_sum
                continue

            left = i + 1
            right = len(nums) - 1

            while left < right:
                curr = nums[i] + nums[left] + nums[right]
                if curr == target:
                    return curr

                if abs(target - close) > abs(target - curr):
                    close = curr

                if curr > target:
                    right -= 1
                else:
                    left += 1

        return close
