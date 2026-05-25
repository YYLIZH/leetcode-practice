from typing import List


class Solution:
    def insert(
        self, intervals: List[List[int]], newInterval: List[int]
    ) -> List[List[int]]:
        result = []

        for index, interval in enumerate(intervals):
            if interval[1] < newInterval[0]:
                result.append(interval)

            elif newInterval[1] < interval[0]:
                result.append(newInterval)
                return result + intervals[index:]

            else:  # Consider the overlap case
                newInterval[0] = min(interval[0], newInterval[0])
                newInterval[1] = max(interval[1], newInterval[1])

        result.append(newInterval)  # Consider the interval is at last
        return result
