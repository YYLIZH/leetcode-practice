from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:

        # Sum for j+1 to i = sum[i]-sum[j]
        # Need sum[i]-sum[j]=k
        # sum[j]=sum[i]-k

        curr_sum = 0
        count = 0

        # {prefix sum: count}
        prefix_map = {0: 1}

        for num in nums:
            curr_sum += num

            target = curr_sum - k
            if target in prefix_map:
                count += prefix_map[target]

            prefix_map[curr_sum] = prefix_map.get(curr_sum, 0) + 1

        return count
