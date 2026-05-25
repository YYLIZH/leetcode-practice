from typing import List


class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        if not intervals:
            return 0

        intervals.sort(key=lambda x: x[1])

        count = 0
        curr_end = intervals[0][1]

        for i in range(1, len(intervals)):
            if intervals[i][0] < curr_end:
                count += 1
            else:
                curr_end = intervals[i][1]

        return count
